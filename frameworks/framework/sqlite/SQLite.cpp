//
//  SQLite.cpp
//  The9Framework
//
//  Created by wp_g4 on 13-5-14.
//
//

#include "SQLite.h"

using namespace cocos2d;

static __Dictionary sqliteCache;

SQLite::~SQLite()
{
    if (db != NULL) {
        sqlite3_close(db);
    }
}

bool SQLite::initWithFile(const std::string &file)
{
    int res = sqlite3_open(file.c_str(), &db);
    if (res == SQLITE_OK) {
        return true;
    }else{
        CCLOG("SQLite-open db:%s error code:%d",file.c_str(),res);
        return false;
    }
}

SQLite* SQLite::openSQLite(const std::string &dbFile)
{
    std::string filePath = CCFileUtils::getInstance()->fullPathForFilename(dbFile.c_str());
    SQLite* sqlite = (SQLite*)sqliteCache.objectForKey(filePath);
    
    if (sqlite) {
        return sqlite;
    }
    
    sqlite = new SQLite();
    
    if (!sqlite->initWithFile(filePath)) {
        CC_SAFE_RELEASE_NULL(sqlite);
        return NULL;
    }
    sqlite->autorelease();
    
    sqliteCache.setObject(sqlite, filePath);
    
    return sqlite;
}

void SQLite::clearConnectionCache()
{
    sqliteCache.removeAllObjects();
}

const char* SQLite::getValueTypeName(cocos2d::Ref *value)
{
    if (dynamic_cast<__String*>(value) != NULL) {
        return "__String";
    }else if (dynamic_cast<__Integer*>(value) != NULL){
        return "__Integer";
    }else if (dynamic_cast<CCFloat*>(value) != NULL){
        return "CCFloat";
    }else{
        return "UNKNOWN";
    }
}

bool SQLite::createTable(const std::string &tableName, cocos2d::__Array *columnArray)
{
    std::string sql = "CREATE TABLE IF NOT EXISTS ";
    sql.append(tableName);
    sql.append("(");
    
    int count = columnArray->count();
    for (int i = 0;i<count;i++) {
        __String* columnName = (__String*)columnArray->getObjectAtIndex(i);
        sql.append(columnName->getCString());
        sql.append(" TEXT");
        if (i != count-1) {
            sql.append(",");
        }
    }
    
    sql.append(")");
    
    return this->executeUpdate(sql);
}

bool SQLite::dropTable(const std::string &tableName)
{
    std::string sql = "DROP TABLE IF EXISTS ";
    sql.append(tableName);
    bool res = this->executeUpdate(sql);
    
    return res;
}

bool SQLite::insertIntoTable(const std::string &tableName, cocos2d::__Dictionary *keyValueDict)
{
    std::string sql = "INSERT INTO ";
    sql.append(tableName);
    std::string keyStr = "(";
    std::string valueStr = "(";
    
    __Array* keyArray = keyValueDict->allKeys();
    int count = keyArray->count();
    
    for (int i = 0; i < count; i++) {
        __String* key = (__String*)keyArray->getObjectAtIndex(i);
        __String* value = (__String*)keyValueDict->objectForKey(key->getCString());
        keyStr.append(key->getCString());
        valueStr.append("'");
        valueStr.append(value->getCString());
        valueStr.append("'");
        if (i != count-1) {
            keyStr.append(",");
            valueStr.append(",");
        }
    }
    
    keyStr.append(")");
    valueStr.append(")");
    sql.append(keyStr);
    sql.append(" VALUES ");
    sql.append(valueStr);
    
    return this->executeUpdate(sql);
}

bool SQLite::clearTable(const std::string &tableName){
    return this->deleteFromTable(tableName, NULL);
}

bool SQLite::deleteFromTable(const std::string &tableName, cocos2d::__Dictionary *conditionDict)
{
    std::string sql = "DELETE FROM ";
    sql.append(tableName);
    sql.append(this->convertConditionDictionary(conditionDict));
    
    return this->executeUpdate(sql);
}

bool SQLite::deleteFromTable(const std::string &tableName, const std::string &columnName, const std::string &columnValue)
{
    __Dictionary* conditionDict = __Dictionary::create();
    conditionDict->setObject(__String::create(columnValue), columnName);
    
    return this->deleteFromTable(tableName,conditionDict);
}

// 以下为更新接口
bool SQLite::updateTable(const std::string &tableName, cocos2d::__Dictionary *keyValueDict, cocos2d::__Dictionary *conditionDict)
{
    std::string sql = "UPDATE ";
    sql.append(tableName);
    sql.append(" SET ");
    
    __Array* keyArray = keyValueDict->allKeys();
    int count = keyArray->count();
    
    for (int i=0; i<count; i++) {
        __String* key = (__String*)keyArray->getObjectAtIndex(i);
        __String* value = (__String*)keyValueDict->objectForKey(key->getCString());
        sql.append(key->getCString());
        sql.append("='");
        sql.append(value->getCString());
        sql.append("'");
        if (i != count-1) {
            sql.append(",");
        }
    }
    
    sql.append(this->convertConditionDictionary(conditionDict));
    
    return this->executeUpdate(sql);
}

bool SQLite::updateTable(const std::string &tableName, cocos2d::__Dictionary *keyValueDict, const std::string &columnName, const std::string &columnValue)
{
    __Dictionary* conditionDict = __Dictionary::create();
    conditionDict->setObject(__String::create(columnValue), columnName);
    
    return this->updateTable(tableName, keyValueDict, conditionDict);
}

int SQLite::getRecordCount(const std::string &tableName)
{
    std::string sql = "SELECT COUNT(*) FROM ";
    sql.append(tableName);
    CCLOG("SQLite:%s",sql.c_str());
    
    sqlite3_stmt* stmt = NULL;
    int count = 0;
    bool res = sqlite3_prepare(db, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK;
    if (res) {
        while (sqlite3_step(stmt) == SQLITE_ROW ) {
            //1列数据
            count = sqlite3_column_int(stmt, 0);
        }
        sqlite3_finalize(stmt);
    }
    
    return count;
}

// 以下为查询接口
__Array* SQLite::selectTable(const std::string &tableName, cocos2d::__Dictionary *conditionDict)
{
    std::string sql = this->getExecuteSql(tableName, conditionDict);
    
    return this->executeQuery(sql);
}

__Array* SQLite::selectTable(const std::string &tableName, const std::string &columnName, const std::string &columnValue)
{
    std::string sql = this->getExecuteSql(tableName, columnName, columnValue);
    
    return this->executeQuery(sql);
}

cocos2d::__Array* SQLite::selectTable(const std::string& tableName,const std::string& columnName,cocos2d::__Array* columnValues)
{
    std::string sql = this->getExecuteSql(tableName, columnName, columnValues);
    
    return this->executeQuery(sql);
}

cocos2d::__Array* SQLite::selectTable(const std::string &tableName, const std::string &sql)
{
    return this->executeQuery(sql);
}

/****************************** 以下为私有api ******************************/

// 组装查询sql
std::string SQLite::getExecuteSql(const std::string& tableName,cocos2d::__Dictionary* conditionDict)
{
    std::string sql = "SELECT * FROM ";
    sql.append(tableName);
    sql.append(this->convertConditionDictionary(conditionDict));
    
    return sql;
}

std::string SQLite::getExecuteSql(const std::string& tableName, const std::string& columnName,const std::string& columnValue)
{
    __Dictionary* conditionDict = __Dictionary::create();
    conditionDict->setObject(__String::create(columnValue), columnName);
    
    return this->getExecuteSql(tableName, conditionDict);
}

std::string SQLite::getExecuteSql(const std::string& tableName,const std::string& columnName,cocos2d::__Array* columnValues)
{
    std::string sql = "SELECT * FROM ";
    sql.append(tableName);
    sql.append(" WHERE ");
    sql.append(columnName);
    sql.append(" IN (");
    
    int count = columnValues->count();
    for (int i = 0; i < count; i++) {
        __String* value = (__String*)columnValues->getObjectAtIndex(i);
        sql.append("'");
        sql.append(value->getCString());
        sql.append("'");
        if (i != count-1) {
            sql.append(",");
        }
    }
    sql.append(")");
    
    return sql;
}

//执行查询sql
bool SQLite::executeUpdate(const std::string &sql)
{
    CCLOG("SQLite:%s",sql.c_str());
    sqlite3_stmt* stmt = NULL;
    bool res = sqlite3_prepare(db, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK;
    if (res) {
        res = sqlite3_step(stmt) == SQLITE_DONE;
        sqlite3_finalize(stmt);
    }
    return res;
}

__Array* SQLite::executeQuery(const std::string &sql)
{
    CCLOG("SQLite:%s",sql.c_str());
    __Array* valueArray = __Array::create();
    sqlite3_stmt* stmt = NULL;
    
    bool res = sqlite3_prepare(db, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK;
    if (res) {
        while (sqlite3_step(stmt) == SQLITE_ROW ) {
            __Dictionary* columnDict = __Dictionary::create();
            int columnNum = sqlite3_column_count(stmt);
            for (int i = 0; i < columnNum; i++) {
                int type = sqlite3_column_type(stmt, i);
                
                const char* name = sqlite3_column_name(stmt, i);
                Ref* value = NULL;
                if (type == SQLITE_INTEGER) {
                    value = __Integer::create(sqlite3_column_int(stmt, i));
                }else if (type == SQLITE_FLOAT){
                    value = CCFloat::create(sqlite3_column_int(stmt, i));
                }else if (type == SQLITE_TEXT){
                    value = __String::create((char*)sqlite3_column_text(stmt, i));
                }else{
                    value = __String::create("");
                }
                columnDict->setObject(value, name);
            }
            valueArray->addObject(columnDict);
        }
        sqlite3_finalize(stmt);
    }
    
    return valueArray;
}

std::string SQLite::convertConditionDictionary(cocos2d::__Dictionary *conditionDict)
{
    std::string conditionStr;
    if (conditionDict && conditionDict->count() > 0) {
        
        conditionStr.append(" WHERE ");
        
        __Array* columnNameArray = conditionDict->allKeys();
        int count = columnNameArray->count();
        
        for (int i = 0; i < count; i++) {
            __String* columnName = (__String*)columnNameArray->getObjectAtIndex(i);
            __String* columnValue = (__String*)conditionDict->objectForKey(columnName->getCString());
            
            conditionStr.append(columnName->getCString());
            conditionStr.append("='");
            conditionStr.append(columnValue->getCString());
            conditionStr.append("'");
            
            if (i != count-1) {
                conditionStr.append(" AND ");
            }
        }
    }
    return conditionStr;
}

bool SQLite::insertIntoTable(const std::string &tableName, cocos2d::__Array *valueArray)
{
    std::string sql = "INSERT INTO ";
    sql.append(tableName);
    sql.append(" VALUES(");
    
    int count = valueArray->count();
    for (int i = 0;i < count;i++) {
        __String* value = (__String*)valueArray->getObjectAtIndex(i);
        sql.append("'");
        sql.append(value->getCString());
        sql.append("'");
        if (i != count-1) {
            sql.append(",");
        }
    }
    sql.append(")");
    
    return this->executeUpdate(sql);
}


