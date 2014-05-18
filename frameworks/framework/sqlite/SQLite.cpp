//
//  SQLite.cpp
//  Framework
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

bool SQLite::createTable(const std::string &tableName, const cocos2d::ValueVector &columnVector)
{
    std::string sql = "CREATE TABLE IF NOT EXISTS ";
    sql.append(tableName);
    sql.append("(");
    
    int count = columnVector.size();
    for (int i = 0;i<count;i++) {
        std::string columnName = columnVector[i].asString();
        sql.append(columnName);
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

bool SQLite::insertIntoTable(const std::string &tableName, const cocos2d::ValueMap &keyValueMap)
{
    std::string sql = "INSERT INTO ";
    sql.append(tableName);
    std::string keyStr = "(";
    std::string valueStr = "(";
    
    int count = keyValueMap.size();
    
    int i = 0;
    for (auto iter = keyValueMap.cbegin(); iter != keyValueMap.cend(); ++iter)
    {
        std::string key = iter->first;
        std::string value = iter->second.asString();
        keyStr.append(key);
        valueStr.append("'");
        valueStr.append(value);
        valueStr.append("'");
        if (i != count-1) {
            keyStr.append(",");
            valueStr.append(",");
        }
        i++;
    }
    
    keyStr.append(")");
    valueStr.append(")");
    sql.append(keyStr);
    sql.append(" VALUES ");
    sql.append(valueStr);
    
    return this->executeUpdate(sql);
}

bool SQLite::clearTable(const std::string &tableName){
    return this->deleteFromTable(tableName, ValueMap());
}

bool SQLite::deleteFromTable(const std::string &tableName, const cocos2d::ValueMap &conditionMap)
{
    std::string sql = "DELETE FROM ";
    sql.append(tableName);
    sql.append(this->convertConditionMap(conditionMap));
    
    return this->executeUpdate(sql);
}

bool SQLite::deleteFromTable(const std::string &tableName, const std::string &columnName, const std::string &columnValue)
{
    ValueMap conditionMap;
    conditionMap[columnName]=columnValue;
    
    return this->deleteFromTable(tableName,conditionMap);
}

// 以下为更新接口
bool SQLite::updateTable(const std::string &tableName, const cocos2d::ValueMap &keyValueMap, const cocos2d::ValueMap &conditionMap)
{
    std::string sql = "UPDATE ";
    sql.append(tableName);
    sql.append(" SET ");
    
    int count = keyValueMap.size();
    
    int i = 0;
    for (auto iter = keyValueMap.cbegin(); iter != keyValueMap.cend(); ++iter)
    {
        std::string key = iter->first;
        std::string value = iter->second.asString();
        
        sql.append(key);
        sql.append("='");
        sql.append(value);
        sql.append("'");
        if (i != count-1) {
            sql.append(",");
        }
        
        i++;
    }
    
    sql.append(this->convertConditionMap(conditionMap));
    
    return this->executeUpdate(sql);
}

bool SQLite::updateTable(const std::string &tableName, const cocos2d::ValueMap &keyValueMap, const std::string &columnName, const std::string &columnValue)
{
    ValueMap conditionMap;
    conditionMap[columnName]=columnValue;
    
    return this->updateTable(tableName, keyValueMap, conditionMap);
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
cocos2d::ValueVector SQLite::selectTable(const std::string &tableName, const cocos2d::ValueMap &conditionMap)
{
    std::string sql = this->getExecuteSql(tableName, conditionMap);
    
    return this->executeQuery(sql);
}

cocos2d::ValueVector SQLite::selectTable(const std::string &tableName, const std::string &columnName, const std::string &columnValue)
{
    std::string sql = this->getExecuteSql(tableName, columnName, columnValue);
    
    return this->executeQuery(sql);
}

cocos2d::ValueVector SQLite::selectTable(const std::string &tableName, const std::string &columnName, const cocos2d::ValueVector &columnValues)
{
    std::string sql = this->getExecuteSql(tableName, columnName, columnValues);
    
    return this->executeQuery(sql);
}

cocos2d::ValueVector SQLite::selectTable(const std::string &sql)
{
    return this->executeQuery(sql);
}

/****************************** 以下为私有api ******************************/

// 组装查询sql
std::string SQLite::getExecuteSql(const std::string &tableName, const cocos2d::ValueMap &conditionMap)
{
    std::string sql = "SELECT * FROM ";
    sql.append(tableName);
    sql.append(this->convertConditionMap(conditionMap));
    
    return sql;
}

std::string SQLite::getExecuteSql(const std::string& tableName, const std::string& columnName,const std::string& columnValue)
{
    ValueMap conditionMap;
    conditionMap[columnName]=columnValue;
    
    return this->getExecuteSql(tableName, conditionMap);
}

std::string SQLite::getExecuteSql(const std::string &tableName, const std::string &columnName, const cocos2d::ValueVector &columnValues)
{
    std::string sql = "SELECT * FROM ";
    sql.append(tableName);
    sql.append(" WHERE ");
    sql.append(columnName);
    sql.append(" IN (");
    
    int count = columnValues.size();
    for (int i = 0; i < count; i++) {
        std::string value = columnValues[i].asString();
        sql.append("'");
        sql.append(value);
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

cocos2d::ValueVector SQLite::executeQuery(const std::string &sql)
{
    CCLOG("SQLite:%s",sql.c_str());
    ValueVector valueArray;
    sqlite3_stmt* stmt = NULL;
    
    bool res = sqlite3_prepare(db, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK;
    if (res) {
        while (sqlite3_step(stmt) == SQLITE_ROW ) {
            ValueMap columnMap;
            int columnNum = sqlite3_column_count(stmt);
            for (int i = 0; i < columnNum; i++) {
                int type = sqlite3_column_type(stmt, i);
                
                const char* name = sqlite3_column_name(stmt, i);
                
                if (type == SQLITE_INTEGER) {
                    columnMap[name]=Value(sqlite3_column_int(stmt, i));
                }else if (type == SQLITE_FLOAT){
                    columnMap[name]=Value(sqlite3_column_int(stmt, i));
                }else if (type == SQLITE_TEXT){
                    columnMap[name]=Value((char*)sqlite3_column_text(stmt, i));
                }else{
                    columnMap[name] = "";
                }
            }
            valueArray.push_back(Value(columnMap));
        }
        sqlite3_finalize(stmt);
    }
    
    return valueArray;
}

std::string SQLite::convertConditionMap(const cocos2d::ValueMap &conditionMap)
{
    std::string conditionStr;
    
    int count = conditionMap.size();
    
    if (count > 0) {
        
        conditionStr.append(" WHERE ");
        
        int i = 0;
        for (auto iter = conditionMap.cbegin(); iter != conditionMap.cend(); ++iter)
        {
            std::string columnName = iter->first;
            std::string columnValue = iter->second.asString();
            
            conditionStr.append(columnName);
            conditionStr.append("='");
            conditionStr.append(columnValue);
            conditionStr.append("'");
            
            if (i != count-1) {
                conditionStr.append(" AND ");
            }
            i++;
            
        }
        
    }
    return conditionStr;
}

bool SQLite::insertIntoTable(const std::string &tableName, const cocos2d::ValueVector& valueArray)
{
    std::string sql = "INSERT INTO ";
    sql.append(tableName);
    sql.append(" VALUES(");
    
    int count = valueArray.size();
    for (int i = 0;i < count;i++) {
        std::string value = valueArray[i].asString();
        sql.append("'");
        sql.append(value);
        sql.append("'");
        if (i != count-1) {
            sql.append(",");
        }
        i++;
    }
    sql.append(")");
    
    return this->executeUpdate(sql);
}


