//
//  NetProtocol.cpp
//  Framework
//
//  Created by wp_g4 on 13-3-2.
//
//

#include "NetProtocol.h"

NetProtocol::NetProtocol()
	: handler(NULL)
{
}

bool NetProtocol::init()
{
    return true;
}

NetProtocol::~NetProtocol()
{
    CC_SAFE_RELEASE_NULL(handler);
}

NetProtocol* NetProtocol::create(const std::string &protocolID, const std::string &serviceID, NetHandler *handler)
{
    NetProtocol* netProtocol=NetProtocol::create();
    netProtocol->setID(protocolID);
    netProtocol->setServiceID(serviceID);
    netProtocol->setHandler(handler);
    return netProtocol;
}