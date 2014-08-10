//
//  Socket.cpp
//  Framework
//
//  Created by wp_g4 on 13-8-22.
//
//

#include "Socket.h"

USING_NS_CC;

#define SOCKET_SEMAPHORE "socket"

/******************SocketOperation******************/

SocketOperation* SocketOperation::create(SocketOperationType type, Data data)
{
    SocketOperation* operation = new SocketOperation(type,data);
    operation->autorelease();
    return operation;
}

SocketOperation::SocketOperation(SocketOperationType type, Data data)
{
    this->type = type;
    this->data = data;
}

SocketOperation::~SocketOperation()
{
}

/******************SocketEvent******************/

SocketEvent* SocketEvent::create(SocketEventType type, Data data)
{
    SocketEvent* event = new SocketEvent(type,data);
    event->autorelease();
    return event;
}

SocketEvent::SocketEvent(SocketEventType type, Data data)
{
    this->type = type;
    this->data = data;
}

SocketEvent::~SocketEvent()
{
}


/******************Socket******************/

Socket::Socket(const std::string& host, int port)
:delegate(NULL),
connecting(false),
connected(false),
isThreadStarted(false)
{
    this->host = host;
    this->port = port;
    this->operationQueue = __Array::create();
    CC_SAFE_RETAIN(this->operationQueue);
    this->eventQueue = __Array::create();
    CC_SAFE_RETAIN(this->eventQueue);
    
    odsocket = new ODSocket();
    odsocket->Init();
    odsocket->Create(AF_INET,SOCK_STREAM,0);
    
    CCDirector::getInstance()->getScheduler()->scheduleSelector(schedule_selector(Socket::processEventQueue), this, 0.1, false);
}

Socket::~Socket()
{
    if (odsocket) {
        delete odsocket;
    }
    CC_SAFE_RELEASE_NULL(this->operationQueue);
    CC_SAFE_RELEASE_NULL(this->eventQueue);
}

void Socket::connect()
{
    if (this->isConnecting()||this->isConnected()) {
        return;
    }
    this->connecting = true;
    SocketOperation* operation = SocketOperation::create(SocketOperationTypeConnect, Data::Null);
    this->addOperation(operation);
}

void Socket::disconnect()
{
    if (!this->isConnected()) {
        return;
    }
    SocketOperation* operation = SocketOperation::create(SocketOperationTypeDisconnect, Data::Null);
    this->addOperation(operation);
}

void Socket::send(unsigned char *data, unsigned int size)
{
    Data dData;
    dData.copy(data, size);
    SocketOperation* operation = SocketOperation::create(SocketOperationTypeSendMessage, dData);
    this->addOperation(operation);
}

void Socket::send(const std::string &data)
{
    const char* bytes = data.c_str();
    Data dData;
    dData.copy((unsigned char*)bytes, data.size());
    SocketOperation* operation = SocketOperation::create(SocketOperationTypeSendMessage, dData);
    this->addOperation(operation);
}

void Socket::destroy()
{
    CCDirector::getInstance()->getScheduler()->unscheduleAllForTarget(this);
    this->release();
}

void Socket::addOperation(SocketOperation *operation)
{
    if (!isThreadStarted) {
        this->startNetThread();
    }
    operationQueueMutex.lock();
    //将操作添加到队列，并通知网络线程处理
    if (operation->getType() == SocketOperationTypeConnect) {
        
        this->operationQueue->insertObject(operation, 0);
        
    }else if (operation->getType() == SocketOperationTypeSendMessage){
        
        this->operationQueue->addObject(operation);
        
    }else if (operation->getType() == SocketOperationTypeDisconnect){
        
        this->operationQueue->removeAllObjects();
        this->operationQueue->addObject(operation);
    }
    waitCondition.notify_one();
    operationQueueMutex.unlock();
}

void Socket::addEvent(SocketEvent *event)
{
    eventQueueMutex.lock();
    this->eventQueue->addObject(event);
    eventQueueMutex.unlock();
}

void Socket::startNetThread()
{
    auto t = std::thread(CC_CALLBACK_0(Socket::senderThreadFunc, this));
    t.detach();
    
    t = std::thread(CC_CALLBACK_0(Socket::receiverThreadFunc, this));
    t.detach();
    
    
    isThreadStarted = true;
}

void Socket::senderThreadFunc()
{
    while (true) {
        
        std::unique_lock<std::mutex> lk(waitMutex);
        waitCondition.wait(lk);
        
        this->processOperationQueue();
    }
}

void Socket::receiverThreadFunc()
{
    while (true) {
        this->readData();
    }
}

//run in sender thread
void Socket::processOperationQueue()
{
    operationQueueMutex.lock();
    //剪切操作队列（多线程环境下，减少线程对操作队列的持有时间）
    __Array* tempArray = new __Array();
    tempArray->init();
    tempArray->addObjectsFromArray(this->operationQueue);
    this->operationQueue->removeAllObjects();
    operationQueueMutex.unlock();
    
    //处理操作
    for (int i = 0; i < tempArray->count(); i++) {
        
        SocketOperation* operation = (SocketOperation*)tempArray->getObjectAtIndex(i);
        switch (operation->getType()) {
            case SocketOperationTypeConnect:
            {
                char ip[100] = {0};
                ODSocket::DnsParse(this->host.c_str(), ip);
                bool res = odsocket->Connect(ip, this->port);
                if (res) {
                    this->addEvent(SocketEvent::create(SocketEventTypeConnected, Data::Null));
                }
            }
                break;
            case SocketOperationTypeSendMessage:
            {
                odsocket->Send((char*)operation->getData().getBytes(), operation->getData().getSize());
            }
                break;
            case SocketOperationTypeDisconnect:
            {
                int res = odsocket->Close();
                if (res == 0) {
                    this->addEvent(SocketEvent::create(SocketEventTypeDisConnected, Data::Null));
                }
            }
                break;
                
            default:
                break;
        }
    }
    tempArray->release();
}

//run in receiver thread
void Socket::readData()
{
    if (this->connected) {
        //从套接口读数据
        std::vector<char> buffer;
        int totalSize = 0;
        const int TEMP_BUFFER_SIZE = 1024;
        char tempBuff[TEMP_BUFFER_SIZE];
        int recvSize = -1;
        while ((recvSize = odsocket->Recv(tempBuff, TEMP_BUFFER_SIZE))>0) {
            
            totalSize += recvSize;
            buffer.insert(buffer.end(), tempBuff, tempBuff + recvSize);
            
            if (recvSize!=TEMP_BUFFER_SIZE) {
                break;
            }
        }
        if (totalSize > 0) {
            Data data;
            data.copy((unsigned char*)buffer.data(), totalSize);
            this->addEvent(SocketEvent::create(SocketEventTypeReceivedMessage, data));
        }
    }
}

//run in main thread
void Socket::processEventQueue(float delta)
{
    eventQueueMutex.lock();
    //剪切事件队列（多线程环境下，减少线程对事件队列的持有时间）
    __Array* tempArray = __Array::create();
    tempArray->addObjectsFromArray(this->eventQueue);
    this->eventQueue->removeAllObjects();
    eventQueueMutex.unlock();
    
    //处理事件
    for (int i = 0; i < tempArray->count(); i++) {
        
        SocketEvent* event = (SocketEvent*)tempArray->getObjectAtIndex(i);
        switch (event->getType()) {
            case SocketEventTypeConnected:
            {
                this->connecting = false;
                this->connected = true;
                if (this->delegate) {
                    this->delegate->onConnected(this);
                }
            }
                break;
            case SocketEventTypeReceivedMessage:
            {
                if (this->delegate) {
                    this->delegate->onReceived(this, event->getData().getBytes(), event->getData().getSize());
                }
            }
                break;
            case SocketEventTypeException:
            {
                if (this->delegate) {
                    std::string errorMsg = (char*)event->getData().getBytes();
                    this->delegate->onException(this, errorMsg);
                }
            }
                break;
            case SocketEventTypeDisConnected:
            {
                this->connected = false;
                if (this->delegate) {
                    this->delegate->onDisconnected(this);
                }
            }
                break;
                
            default:
                break;
        }
    }
}