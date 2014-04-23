//
//  HttpForm.cpp
//  The9Framework
//
//  Created by wp_g4 on 13-3-5.
//
//

#include "HttpForm.h"
#include "cocos2d.h"

using namespace std;


bool HttpForm::init()
{
    paramDict=cocos2d::__Dictionary::create();
    CC_SAFE_RETAIN(paramDict);
    return true;
}

HttpForm::~HttpForm()
{
    CC_SAFE_RELEASE_NULL(paramDict);
}

void HttpForm::putParam(const std::string& paramName,const std::string& paramValue)
{
    paramDict->setObject(cocos2d::__String::create(paramValue), paramName);
}

const char* HttpForm::getParam(const std::string &paramName)
{
    cocos2d::__String* paramValue=(cocos2d::__String*)paramDict->objectForKey(paramName);
    if (paramValue!=NULL) {
        return paramValue->getCString();
    }
    return NULL;
}

void HttpForm::removeParam(const std::string& paramName)
{
    paramDict->removeObjectForKey(paramName);
}

const char* HttpForm::toString()
{
    std::string paramUrl;
    int count=paramDict->count();
    cocos2d::__Array* keyArray=paramDict->allKeys();
    for (int i=0; i<count; i++) {
        cocos2d::__String* key=(cocos2d::__String*)keyArray->getObjectAtIndex(i);
        std::string paramName=key->getCString();
        cocos2d::__String* value=(cocos2d::__String*)paramDict->objectForKey(paramName);
        std::string paramValue=value->getCString();
        paramUrl.append(paramName);
        paramUrl.append("=");
        paramUrl.append(paramValue);
        if (i!=count-1) {
            paramUrl.append("&");
        }
    }
    return cocos2d::__String::create(paramUrl)->getCString();
}

char HttpForm::dec2hexChar(short int n) {
    if ( 0 <= n && n <= 9 ) {
        return char( short('0') + n );
    } else if ( 10 <= n && n <= 15 ) {
        return char( short('A') + n - 10 );
    } else {
        return char(0);
    }
}

short int HttpForm::hexChar2dec(char c) {
    if ( '0'<=c && c<='9' ) {
        return short(c-'0');
    } else if ( 'a'<=c && c<='f' ) {
        return ( short(c-'a') + 10 );
    } else if ( 'A'<=c && c<='F' ) {
        return ( short(c-'A') + 10 );
    } else {
        return -1;
    }
}

const char* HttpForm::escapeURL(const string &URL)
{
    string result = "";
    for ( unsigned int i=0; i<URL.size(); i++ ) {
        char c = URL[i];
        if (
            ( '0'<=c && c<='9' ) ||
            ( 'a'<=c && c<='z' ) ||
            ( 'A'<=c && c<='Z' ) ||
            c=='/' || c=='.'
            ) {
            result += c;
        } else {
            int j = (short int)c;
            if ( j < 0 ) {
                j += 256;
            }
            int i1, i0;
            i1 = j / 16;
            i0 = j - i1*16;
            result += '%';
            result += this->dec2hexChar(i1);
            result += this->dec2hexChar(i0);
        }
    }
    return cocos2d::__String::create(result)->getCString();
}

const char* HttpForm::deescapeURL(const string &URL) {
    string result = "";
    for ( unsigned int i=0; i<URL.size(); i++ ) {
        char c = URL[i];
        if ( c != '%' ) {
            result += c;
        } else {
            char c1 = URL[++i];
            char c0 = URL[++i];
            int num = 0;
            num += this->hexChar2dec(c1) * 16 + this->hexChar2dec(c0);
            result += char(num);
        }
    }
    return cocos2d::__String::create(result)->getCString();
}

