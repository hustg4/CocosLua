//
//  NetCenter.cpp
//  Framework
//
//  Created by wp_g4 on 13-2-21.
//
//

#include "NetCenter.h"

using namespace cocos2d;

NetCenter::NetCenter(){
    netServiceDict=__Dictionary::create();
    CC_SAFE_RETAIN(netServiceDict);
    netProtocolDict=__Dictionary::create();
    CC_SAFE_RETAIN(netProtocolDict);
    netFilterChain = __Array::create();
    CC_SAFE_RETAIN(netFilterChain);
}

NetCenter::~NetCenter()
{
    CC_SAFE_RELEASE_NULL(netServiceDict);
    CC_SAFE_RELEASE_NULL(netProtocolDict);
    CC_SAFE_RELEASE_NULL(netFilterChain);
}

NetCenter* NetCenter::sharedNetCenter()
{
    static NetCenter instance;
    return &instance;
}


void NetCenter::addNetService(const std::string& serviceID,NetService* service)
{
    netServiceDict->setObject(service, serviceID);
}

void NetCenter::removeNetService(const std::string& serviceID)
{
    netServiceDict->removeObjectForKey(serviceID);
}

void NetCenter::addNetProtocol(const std::string &protocolID, const std::string &serviceID, NetHandler *handler)
{
    NetProtocol* protocol=NetProtocol::create(protocolID, serviceID, handler);
    this->addNetProtocol(protocol);
}

void NetCenter::addNetProtocol(NetProtocol *protocol)
{
    netProtocolDict->setObject(protocol, protocol->getID());
}

void NetCenter::removeNetProtocol(const std::string &protocolID)
{
    netProtocolDict->removeObjectForKey(protocolID);
}

void NetCenter::removeNetProtocolForNetService(const std::string &serviceID)
{
    __Array* targetKeys=__Array::create();
    __Array* allKeys=netProtocolDict->allKeys();
    int count=allKeys->count();
    for (int i=0; i<count; i++) {
        __String* key=(__String*)allKeys->getObjectAtIndex(i);
        NetProtocol* protocol=(NetProtocol*)netProtocolDict->objectForKey(key->getCString());
        if (strcmp(protocol->getServiceID().c_str(), serviceID.c_str())==0) {
            targetKeys->addObject(key);
        }
    }
    netProtocolDict->removeObjectsForKeys(targetKeys);
}

void NetCenter::addNetFilter(NetFilter *filter)
{
    this->netFilterChain->addObject(filter);
}

void NetCenter::removeNetFilter(NetFilter *filter)
{
    this->netFilterChain->removeObject(filter);
}

void NetCenter::removeAllNetFilters()
{
    this->netFilterChain->removeAllObjects();
}

void NetCenter::sendMessage(NetRequest *request)
{
    NetProtocol* protocol=(NetProtocol*)netProtocolDict->objectForKey(request->getProtocolID());
    CCAssert(protocol!=NULL, "unknown protocol");
    NetService* service=(NetService*)netServiceDict->objectForKey(protocol->getServiceID());
    CCAssert(service!=NULL, "no service for protocol");
    service->sendMessage(request);
}

void NetCenter::dispatchSuccessfulMessage(NetResponse *response)
{
    NetProtocol* protocol=(NetProtocol*)netProtocolDict->objectForKey(response->getProtocolID());
    if (protocol == NULL) {
        CCLog("unknown protocol");
        return;
    }
    //(1)过滤
    int count = this->netFilterChain->count();
    for (int i = 0; i < count; i++) {
        if (response) {
            NetFilter* filter = (NetFilter*)netFilterChain->getObjectAtIndex(i);
            response = filter->filterSuccessfulMessage(response);
        }else{
            break;
        }
    }
    if (response == NULL) {
//        CCLOG("消息过滤后为NULL，不进行后续处理");
        return;
    }
    //(2)处理
    NetHandler* handler=(NetHandler*)protocol->getHandler();
    CCAssert(handler!=NULL, "no handler for protocol");
    handler->handleSuccessfulMessage(response);
}

void NetCenter::dispatchFailedMessage(NetResponse *response)
{
    //(1)过滤
    int count = this->netFilterChain->count();
    for (int i = 0; i < count; i++) {
        if (response) {
            NetFilter* filter = (NetFilter*)netFilterChain->getObjectAtIndex(i);
            response = filter->filterFailedMessage(response);
        }else{
            break;
        }
    }
    if (response == NULL) {
//        CCLOG("消息过滤后为NULL，不进行后续处理");
        return;
    }
    //(2)处理
    NetProtocol* protocol=(NetProtocol*)netProtocolDict->objectForKey(response->getProtocolID());
    CCAssert(protocol!=NULL, "unknown protocol");
    NetHandler* handler=(NetHandler*)protocol->getHandler();
    CCAssert(handler!=NULL, "no handler for protocol");
    handler->handleFailedMessage(response);
}

void NetCenter::sendCommand(const std::string &serviceID, const std::string &command, cocos2d::Ref *param)
{
    NetService* service=(NetService*)netServiceDict->objectForKey(serviceID);
    if (service) {
        service->executeCommand(command,param);
    }else{
        CCLOG("不存在的网络服务[%s]",serviceID.c_str());
    }
}
