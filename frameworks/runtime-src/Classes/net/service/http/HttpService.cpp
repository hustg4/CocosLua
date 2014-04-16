//
//  HttpService.cpp
//  The9Framework
//
//  Created by wp_g4 on 13-2-22.
//
//

#include "HttpService.h"
#include "HttpClient.h"
#include "NetConfig.h"

using namespace cocos2d;
using namespace network;


bool HttpService::init()
{
    return true;
}

void HttpService::sendMessage(NetRequest *netRequest)
{
    JSONObject* msg=(JSONObject*)netRequest->getBody();
    HttpRequest* httpRequest=new HttpRequest();
    httpRequest->setUserData(netRequest);
    //setUserData不增加引用记数
    netRequest->retain();
    //method
    httpRequest->setRequestType(HttpRequest::Type::GET);
    //form
    HttpForm* httpForm=HttpForm::create();
    int count=msg->count();;
    __Array* allKeys=msg->allKeys();
    for (int i=0; i<count; i++) {
        __String* key=(__String*)allKeys->getObjectAtIndex(i);
        httpForm->putParam(key->getCString(), msg->getString(key->getCString()));
    }
    //url
    std::string url=HttpServiceAddress;
    std::string formStr=httpForm->toString();
    if (formStr.size()!=0) {
        url.append("?").append(formStr);
    }
    httpRequest->setUrl(url.c_str());
    //set cookieFile
//    std::string cookieFile=CCFileUtils::sharedFileUtils()->getWritablePath();
//    cookieFile.append("cookie.txt");
//    httpRequest->setCookieFile(cookieFile.c_str());
    log("HttpService发出:%s",httpRequest->getUrl());
    //callback
    httpRequest->setResponseCallback(this, httpresponse_selector(HttpService::onHttpRequestCompleted));
    HttpClient::getInstance()->send(httpRequest);
    httpRequest->release();
}


void HttpService::executeCommand(const std::string& command, Ref* param)
{
}

void HttpService::onHttpRequestCompleted(cocos2d::network::HttpClient *client, cocos2d::network::HttpResponse *response)
{
    if (!response)
    {
        return;
    }
    HttpRequest* request=response->getHttpRequest();
    if (0 != strlen(request->getTag()))
    {
        log("%s completed", response->getHttpRequest()->getTag());
    }
    if (!response->isSucceed())
    {
        //访问失败获取错误信息
        log("response failed");
        log("error buffer: %s", response->getErrorBuffer());
        return;
    }
    // 获取返回数据。
    std::vector<char> *buffer = response->getResponseData();
    std::string str;
    str.clear();
    str.assign(buffer->begin(), buffer->end());
    //unicode反编码
    RegexUtil::replaceAll(str, "\\\\u[0-9a-fA-F]{4}", this, RegexUtilReplaceCallBack(&HttpService::replaceCallback));
    JSONObject* jsonObj=JSONObject::createWithString(str);
    log("HttpService收到:%s\n",jsonObj->toPrettyString());
    NetRequest* netRequest=(NetRequest*)request->getUserData();
    NetResponse* netResponse=NetResponse::create(netRequest->getProtocolID(), jsonObj,netRequest);
    NetCenter::sharedNetCenter()->dispatchSuccessfulMessage(netResponse);
    //发请求时retain过
    netRequest->release();
}

const char* HttpService::replaceCallback(const std::string &oldStr)
{
    //oldStr 格式 \u767b
    //(1)取纯数字部分
    std::string unicodeNumStr;
    unicodeNumStr.append(oldStr, 2, 4);
    //(2)转换数字部分的字符串为十六进制数字
    unsigned int unicodeNum;
    sscanf(unicodeNumStr.c_str(), "%x",&unicodeNum);
    //(3)根据十六进制数字编码UTF8字符
    const char* utf8Char=this->convertUnicodeToUTF8(unicodeNum);
    return utf8Char;
}

const char* HttpService::convertUnicodeToUTF8(unsigned int unicode)
{
    std::string str;
    if (unicode<=0x00007F) {
        char c=unicode;
        str.append(1, c);
    }else if (unicode<=0x0007FF){
        unsigned c1=0xC0+((unicode>>6)&0x1F);//10-6
        unsigned c2=0x80+(unicode&0x3F);//5-0
        str.append(1,c1);
        str.append(1,c2);
    }else if (unicode<=0x00FFFF){
        unsigned c1=0xE0+((unicode>>12)&0x0F);//15-12
        unsigned c2=0x80+((unicode>>6)&0x3F);//11-6
        unsigned c3=0x80+(unicode&0x3F);//5-0
        str.append(1,c1);
        str.append(1,c2);
        str.append(1,c3);
    }else if (unicode<=0x10FFFF){
        unsigned c1=0xE0+((unicode>>18)&0x07);//20-18
        unsigned c2=0x80+((unicode>>12)&0x3F);//17-12
        unsigned c3=0x80+((unicode>>6)&0x3F);//11-6
        unsigned c4=0x80+(unicode&0x3F);//5-0
        str.append(1,c1);
        str.append(1,c2);
        str.append(1,c3);
        str.append(1,c4);
    }
    return str.c_str();
}
