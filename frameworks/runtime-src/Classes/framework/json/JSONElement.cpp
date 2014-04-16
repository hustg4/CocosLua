//
//  JSONElement.cpp
//  The9Framework
//
//  Created by wp_g4 on 13-2-27.
//
//

#include "JSONElement.h"
#include "JSONParser.h"
#include "JSONFormatter.h"

using namespace cocos2d;

/**
 ******************JSONObject******************
 */

JSONObject::JSONObject()
{
    dataHolder=__Dictionary::create();
    CC_SAFE_RETAIN(dataHolder);
}

JSONObject::~JSONObject()
{
    CC_SAFE_RELEASE_NULL(dataHolder);
}

bool JSONObject::init()
{
    return true;
}

JSONObject* JSONObject::createWithString(const std::string &jsonStr)
{
    return dynamic_cast<JSONObject*>(JSONParser::parseString(jsonStr));
}

JSONObject* JSONObject::createWithFile(const std::string &jsonFilePath)
{
    return dynamic_cast<JSONObject*>(JSONParser::parseFile(jsonFilePath));
}

bool JSONObject::has(const std::string& key)
{
    return dataHolder->objectForKey(key)!=NULL;
}

int JSONObject::count()
{
    return dataHolder->count();
}

void JSONObject::putBool(const std::string& key,bool value)
{
    dataHolder->setObject(JSONBool::create(value), key);
}

bool JSONObject::getBool(const std::string& key)
{
    Ref* value=dataHolder->objectForKey(key);
    JSONElement* jsonBool=dynamic_cast<JSONElement*>(value);
    return jsonBool!=NULL ? jsonBool->boolValue() : false;
}

void JSONObject::putNumber(const std::string& key,double value)
{
    dataHolder->setObject(JSONNumber::create(value), key);
}

double JSONObject::getNumber(const std::string& key)
{
    Ref* value=dataHolder->objectForKey(key);
    JSONElement* jsonNumber=dynamic_cast<JSONElement*>(value);
    return jsonNumber!=NULL ? jsonNumber->numberValue() : 0;
}

void JSONObject::putString(const std::string& key,const std::string& value)
{
    dataHolder->setObject(JSONString::create(value.c_str()), key);
}

const char* JSONObject::getString(const std::string& key)
{
    Ref* value=dataHolder->objectForKey(key);
    JSONElement* jsonString=dynamic_cast<JSONElement*>(value);
    return jsonString!=NULL ? jsonString->stringValue() : "";
}

void JSONObject::putJSONObject(const std::string& key,JSONObject* value)
{
    dataHolder->setObject(value, key);
}

JSONObject* JSONObject::getJSONObject(const std::string& key)
{
    Ref* value=dataHolder->objectForKey(key);
    JSONObject* jsonObject=dynamic_cast<JSONObject*>(value);
    return jsonObject;
}

void JSONObject::putJSONArray(const std::string& key,JSONArray* value)
{
    dataHolder->setObject(value, key);
}

JSONArray* JSONObject::getJSONArray(const std::string& key)
{
    Ref* value=dataHolder->objectForKey(key);
    JSONArray* jsonArray=dynamic_cast<JSONArray*>(value);
    return jsonArray;
}

void JSONObject::put(const std::string& key,Ref* value)
{
    dataHolder->setObject(value, key);
}

Ref* JSONObject::get(const std::string& key)
{
    return dataHolder->objectForKey(key);
}

__Array* JSONObject::allKeys()
{
    return dataHolder->allKeys();
}

void JSONObject::remove(const std::string &key)
{
    dataHolder->removeObjectForKey(key);
}

void JSONObject::removeAll()
{
    dataHolder->removeAllObjects();
}

const char* JSONObject::toString()
{
    return JSONFormatter::format(this,false);
}

const char* JSONObject::toPrettyString()
{
    return JSONFormatter::format(this,true);
}

const char* JSONObject::toLuaString()
{
    //头
    std::string luaStr="{\n";
    int num=this->count();
    __Array* keyArray=this->allKeys();
    for (int i=0; i<num; i++) {
        //键
        const char* key=((__String*)keyArray->getObjectAtIndex(i))->getCString();
        luaStr.append("[\"");
        luaStr.append(key);
        luaStr.append("\"]");
        luaStr.append("=");
        //值
        Ref* obj=this->get(key);
        JSONBool* jsonBool=NULL;
        JSONNumber* jsonNumber=NULL;
        JSONString* jsonString=NULL;
        JSONObject* jsonObj=NULL;
        JSONArray* jsonArray=NULL;
        if ((jsonBool=dynamic_cast<JSONBool*>(obj))!=NULL) {
            luaStr.append(jsonBool->stringValue());
        }else if ((jsonNumber=dynamic_cast<JSONNumber*>(obj))!=NULL){
            luaStr.append(jsonNumber->stringValue());
        }else if ((jsonString=dynamic_cast<JSONString*>(obj))!=NULL){
            luaStr.append("[==[");
            luaStr.append(jsonString->stringValue());
            luaStr.append("]==]");
        }else if ((jsonObj=dynamic_cast<JSONObject*>(obj))!=NULL){
            std::string value=jsonObj->toLuaString();
            luaStr.append(value);
        }else if ((jsonArray=dynamic_cast<JSONArray*>(obj))!=NULL){
            std::string value=jsonArray->toLuaString();
            luaStr.append(value);
        }
        if (i<num-1) {
            luaStr.append(",");
            luaStr.append("\n");
        }
    }
    //尾
    luaStr.append("\n}");
    __String* ccstr=__String::create(luaStr);
    return ccstr->getCString();
}

/**
 ******************JSONArray******************
 */

JSONArray::JSONArray()
{
    dataHolder=__Array::create();
    CC_SAFE_RETAIN(dataHolder);
}

JSONArray::~JSONArray()
{
    CC_SAFE_RELEASE_NULL(dataHolder);
}

bool JSONArray::init()
{
    return true;
}

JSONArray* JSONArray::createWithString(const std::string &jsonStr)
{
    return dynamic_cast<JSONArray*>(JSONParser::parseString(jsonStr));
}

JSONArray* JSONArray::createWithFile(const std::string &jsonFilePath)
{
    return dynamic_cast<JSONArray*>(JSONParser::parseFile(jsonFilePath));
}

int JSONArray::count()
{
    return dataHolder->count();
}

void JSONArray::addBool(bool value)
{
    JSONBool* jsonBool=JSONBool::create(value);
    dataHolder->addObject(jsonBool);
}

void JSONArray::insertBool(bool value, unsigned int index)
{
    JSONBool* jsonBool=JSONBool::create(value);
    dataHolder->insertObject(jsonBool, index);
}

bool JSONArray::getBool(int index)
{
    Ref* value=dataHolder->getObjectAtIndex(index);
    JSONElement* jsonBool=dynamic_cast<JSONElement*>(value);
    return jsonBool!=NULL ? jsonBool->boolValue() :false;
}

void JSONArray::addNumber(double value)
{
    JSONNumber* jsonNumber=JSONNumber::create(value);
    dataHolder->addObject(jsonNumber);
}

void JSONArray::insertNumber(double value, unsigned int index)
{
    JSONNumber* jsonNumber=JSONNumber::create(value);
    dataHolder->insertObject(jsonNumber, index);
}

double JSONArray::getNumber(int index)
{
    Ref* value=dataHolder->getObjectAtIndex(index);
    JSONElement* jsonNumber=dynamic_cast<JSONElement*>(value);
    return jsonNumber!=NULL ? jsonNumber->numberValue() : 0;
}

void JSONArray::addString(const std::string& value)
{
    JSONString* jsonString=JSONString::create(value.c_str());
    dataHolder->addObject(jsonString);
}

void JSONArray::insertString(const std::string &value, unsigned int index)
{
    JSONString* jsonString=JSONString::create(value.c_str());
    dataHolder->insertObject(jsonString, index);
}

const char* JSONArray::getString(int index)
{
    Ref* value=dataHolder->getObjectAtIndex(index);
    JSONElement* jsonString=dynamic_cast<JSONElement*>(value);
    return jsonString!=NULL ? jsonString->stringValue() : "";
}

void JSONArray::addJSONObject(JSONObject* value)
{
    dataHolder->addObject(value);
}

void JSONArray::insertJSONObject(JSONObject *value, unsigned int index)
{
    dataHolder->insertObject(value, index);
}

JSONObject* JSONArray::getJSONObject(int index)
{
    Ref* value=dataHolder->getObjectAtIndex(index);
    JSONObject* jsonObject=dynamic_cast<JSONObject*>(value);
    return jsonObject;
}

void JSONArray::addJSONArray(JSONArray* value)
{
    dataHolder->addObject(value);
}

void JSONArray::insertJSONArray(JSONArray *value, unsigned int index)
{
    dataHolder->insertObject(value, index);
}

JSONArray* JSONArray::getJSONArray(int index)
{
    Ref* value=dataHolder->getObjectAtIndex(index);
    JSONArray* jsonArray=dynamic_cast<JSONArray*>(value);
    return jsonArray;
}

void JSONArray::add(Ref* value)
{
    dataHolder->addObject(value);
}

void JSONArray::insert(cocos2d::Ref *value, unsigned int index)
{
    dataHolder->insertObject(value, index);
}

Ref* JSONArray::get(int index)
{
    return dataHolder->getObjectAtIndex(index);
}

void JSONArray::removeLast()
{
    dataHolder->removeLastObject();
}

void JSONArray::remove(unsigned int index)
{
    dataHolder->getObjectAtIndex(index);
}

void JSONArray::removeAll()
{
    dataHolder->removeAllObjects();
}

const char* JSONArray::toString()
{
    return JSONFormatter::format(this,false);
}

const char* JSONArray::toPrettyString()
{
    return JSONFormatter::format(this,true);
}

const char* JSONArray::toLuaString()
{
    //头
    std::string luaStr="{\n";
    int num=this->count();
    for (int i=0; i<num; i++) {
        //值
        Ref* obj=this->get(i);
        JSONBool* jsonBool=NULL;
        JSONNumber* jsonNumber=NULL;
        JSONString* jsonString=NULL;
        JSONObject* jsonObj=NULL;
        JSONArray* jsonArray=NULL;
        if ((jsonBool=dynamic_cast<JSONBool*>(obj))!=NULL) {
            luaStr.append(jsonBool->stringValue());
        }else if ((jsonNumber=dynamic_cast<JSONNumber*>(obj))!=NULL){
            luaStr.append(jsonNumber->stringValue());
        }else if ((jsonString=dynamic_cast<JSONString*>(obj))!=NULL){
            luaStr.append("[==[");
            luaStr.append(jsonString->stringValue());
            luaStr.append("]==]");
        }else if ((jsonObj=dynamic_cast<JSONObject*>(obj))!=NULL){
            std::string value=jsonObj->toLuaString();
            luaStr.append(value);
        }else if ((jsonArray=dynamic_cast<JSONArray*>(obj))!=NULL){
            std::string value=jsonArray->toLuaString();
            luaStr.append(value);
        }
        if (i<num-1) {
            luaStr.append(",");
            luaStr.append("\n");
        }
    }
    //尾
    luaStr.append("\n}");
    __String* ccstr=__String::create(luaStr);
    return ccstr->getCString();
}

/**
 ******************JSONElement******************
 */
JSONElement::~JSONElement()
{
    
}

/**
 ******************JSONBool******************
 */

JSONBool::JSONBool(bool value)
{
    this->value=value;
}

JSONBool* JSONBool::create(bool value)
{
    JSONBool* jsonBool=new JSONBool(value);
    jsonBool->autorelease();
    return jsonBool;
}


bool JSONBool::boolValue()
{
    return value;
}

double JSONBool::numberValue()
{
    return value;
}

const char* JSONBool::stringValue()
{
    return value?"true":"false";
}


/**
 ******************JSONNumber******************
 */

JSONNumber::JSONNumber(double value)
{
    this->value=value;
}

JSONNumber* JSONNumber::create(double value)
{
    JSONNumber* jsonNumber=new JSONNumber(value);
    jsonNumber->autorelease();
    return jsonNumber;
}

bool JSONNumber::boolValue()
{
    return value;
}

double JSONNumber::numberValue()
{
    return value;
}

const char* JSONNumber::stringValue()
{
    __String* stringValue=__String::createWithFormat("%lf",value);
    //TODO 去掉小数后面的0，如果最后一个是小数点也去掉。可能有更好的办法，待研究
    std::string str=stringValue->getCString();
    while (str.find_first_of('.')!=-1&&(str.at(str.size()-1)=='.'||str.at(str.size()-1)=='0')) {
        str.erase(str.begin()+str.size()-1);
    }
    stringValue=__String::create(str);
    return stringValue->getCString();
}

/**
 ******************JSONString******************
 */

JSONString::JSONString(const std::string& value)
{
    this->value = value;
}

JSONString::~JSONString()
{
}

JSONString* JSONString::create(const std::string &value)
{
    JSONString* jsonString=new JSONString(value);
    jsonString->autorelease();
    return jsonString;
}

bool JSONString::boolValue()
{
    return !value.empty();
}

double JSONString::numberValue()
{
    double doubleValue;
    sscanf(value.c_str(), "%lf",&doubleValue);
    return doubleValue;
}

const char* JSONString::stringValue()
{
    return value.c_str();
}

