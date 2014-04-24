//
//  Socket.h
//  Framework
//
//  Created by wp_g4 on 13-8-22.
//
//

#ifndef __Framework__Socket__
#define __Framework__Socket__

#include <iostream>
#include "cocos2d.h"

#include <pthread.h>
#include <semaphore.h>
#include "ODSocket.h"

/******************SocketDelegate******************/

class Socket;

class SocketDelegate {
    
public:
    
    virtual ~SocketDelegate(){};
    
    virtual void onReceived(Socket* socket , unsigned char* data,unsigned int size){};
    
    virtual void onException(Socket* socket , const std::string& errorMessage){};
    
    virtual void onConnected(Socket* socket){};
    
    virtual void onDisconnected(Socket* socket){};
    
};

/******************SocketOperation******************/

enum SocketOperationType {
    SocketOperationTypeConnect = 0,         //连接
    SocketOperationTypeSendMessage = 1,     //发送消息
    SocketOperationTypeDisconnect = 2       //关闭连接
};

class SocketOperation : public cocos2d::Ref{
    
public:
    
    static SocketOperation* create(SocketOperationType type,cocos2d::Data data);
    
    SocketOperation(SocketOperationType type,cocos2d::Data data);
    
    ~SocketOperation();
    
    SocketOperationType getType(){ return this->type; };
    
    cocos2d::Data getData(){ return this->data; };
    
private:
    
    SocketOperationType type;
    
    cocos2d::Data data;
    
};

/******************SocketEvent******************/

enum SocketEventType {
    SocketEventTypeConnected = 0,
    SocketEventTypeReceivedMessage = 1,
    SocketEventTypeException = 2,
    SocketEventTypeDisConnected = 3
};

class SocketEvent : public cocos2d::Ref {
    
public:
    
    static SocketEvent* create(SocketEventType type,cocos2d::Data data);
    
    SocketEvent(SocketEventType type,cocos2d::Data data);
    
    ~SocketEvent();
    
    SocketEventType getType(){ return this->type; };
    
    cocos2d::Data getData(){ return this->data; };
    
private:
    
    SocketEventType type;
    
    cocos2d::Data data;
    
};

/******************Socket******************/

class Socket : public cocos2d::Ref{
    
public:
    
    Socket(const std::string& host, int port);
    
    ~Socket();
    
    void setHost(const std::string& host){ this->host = host; };
    
    const char* getHost(){ return this->host.c_str(); };
    
    int getPort(){ return this->port; };
    
    void connect();
    
    bool isConnecting(){ return this->connecting; };
    
    bool isConnected(){ return this->connected; };
    
    void disconnect();
    
    void send(unsigned char* data , unsigned int size);
    
    void send(const std::string& data);
    
    void setDelegate(SocketDelegate* delegate){ this->delegate = delegate; };
    
    SocketDelegate* getDelegate(){ return this->delegate; };
    
    void destroy();
    
public:
    
    friend void* senderThreadFunc(void *data);
    
    friend void* receiverThreadFunc(void* data);
    
    //发送者线程中运行，处理操作
    void processOperationQueue();
    
    //接收者线程中运行，从套接口读数据
    void readData();
    
    //主线程运行，处理事件
    void processEventQueue(float delta);
    
private:
    
    ODSocket* odsocket;
    
    std::string host;
    
    int port;
    
    SocketDelegate* delegate;
    
    bool connecting;
    
    bool connected;
    
    pthread_t senderThread;                         //发送者线程
    
    pthread_t recevierThread;                       //接收者线程
    
    sem_t *          pSem;
    
    sem_t            sem;
    
    pthread_mutex_t  operationQueueMutex;           //操作队列互斥锁
    
    pthread_mutex_t  eventQueueMutex;               //事件队列互斥锁
    
    bool isThreadStarted;                           //线程是否创建并启动
    
    cocos2d::__Array* operationQueue;               //操作队列
    
    cocos2d::__Array* eventQueue;                   //事件队列
    
    void addOperation(SocketOperation* operation);  //添加操作并通知网络线程开始处理
    
    void addEvent(SocketEvent* event);              //添加网络事件，主线程处理
    
    void startNetThread();                          //启动网络线程
    
};

#endif /* defined(__Framework__Socket__) */
