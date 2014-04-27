//
//  SQLite.h
//  Framework
//
//  Created by wp_g4 on 13-5-14.
//
//

#ifndef __Framework__SQLite__
#define __Framework__SQLite__

#include <iostream>
#include "cocos2d.h"
#include "libsqlite/sqlite3.h"

/**
 * 对sqlite数据库的封装
 */
class SQLite :public cocos2d::Ref{
    
public:
    
    virtual ~SQLite();//此处使用virtual是因为SQLite会被继承
    
    /**
     * 打开SQLite数据库
     * @param dbFile db文件
     */
    static SQLite* openSQLite(const std::string& dbFile);
    
    /**
     * 清除所有连接缓存
     */
    static void clearConnectionCache();
    
    /**
     * 创建表
     * @param tableName 表名
     * @param columnVector 列名数组
     */
    bool createTable(const std::string& tableName,const cocos2d::ValueVector& columnVector);
    
    /**
     * 删除表
     * @param tableName 表名
     */
    bool dropTable(const std::string& tableName);
    
    /**
     * 插入数据
     * @param tableName 表名
     * @param keyValueMap 键值对
     */
    bool insertIntoTable(const std::string& tableName,const cocos2d::ValueMap& keyValueMap);
    
    /**
     * 清空表
     * @param tableName 表名
     */
    bool clearTable(const std::string& tableName);
    
    /**
     * 删除符合多个条件的数据
     * @param tableName 表名
     * @param conditionMap 条件字典
     */
    bool deleteFromTable(const std::string& tableName,const cocos2d::ValueMap& conditionMap);
    
    /**
     * 删除符合单个条件的数据
     * @param tableName 表名
     * @param columnName 条件column名
     * @param columnValue 条件column值
     */
    bool deleteFromTable(const std::string& tableName,const std::string& columnName,const std::string& columnValue);
    
    /**
     * 更新符合多个条件的数据
     * @param tableName 表名
     * @param keyValueMap 键值对
     * @param conditionMap 条件字典
     */
    bool updateTable(const std::string& tableName,const cocos2d::ValueMap& keyValueMap,const cocos2d::ValueMap& conditionMap);
    
    /**
     * 更新符合单个条件的数据
     * @param tableName 表名
     * @param keyValueMap 键值对
     * @param columnName 条件column名
     * @param columnValue 条件column值
     */
    bool updateTable(const std::string& tableName,const cocos2d::ValueMap& keyValueMap,const std::string& columnName,const std::string& columnValue);
    
    /**
     * 获取表中记录数量
     * @param tableName 表名
     */
    int getRecordCount(const std::string& tableName);
    
    /**
     * 查询符合多个条件的数据
     * @param tableName 表名
     * @param conditionMap 条件字典
     */
    cocos2d::ValueVector selectTable(const std::string& tableName,const cocos2d::ValueMap& conditionMap);
    
    /**
     * 查询符合单个条件的数据
     * @param tableName 表名
     * @param columnName 条件column名
     * @param columnValue 条件column值
     */
    cocos2d::ValueVector selectTable(const std::string& tableName,const std::string& columnName,const std::string& columnValue);
    
    /**
     * 查询条件为一个字段多个值的结果
     * @param tableName 表名
     * @param columnName 条件column名
     * @param columnValues 条件column 所有可能的值
     */
    cocos2d::ValueVector selectTable(const std::string& tableName,const std::string& columnName,const cocos2d::ValueVector& columnValues);
    
    /**
     * 根据sql查询表
     * @param tableName 表名
     * @param sql 查询语句
     */
    cocos2d::ValueVector selectTable(const std::string& tableName,const std::string& sql);
    
protected:
    
    sqlite3* db;
    
    bool initWithFile(const std::string& file);
    
    /**
     * 根据多个字段名条件，组装查询sql
     * @param tableName 表名
     * @param conditionMap 条件字典
     */
    std::string getExecuteSql(const std::string& tableName,const cocos2d::ValueMap& conditionMap);
    
    /**
     * 根据单个字段名条件，组装查询sql
     * @param tableName 表名
     * @param columnName 条件column名
     * @param columnValue 条件column值
     */
    std::string getExecuteSql(const std::string& tableName, const std::string& columnName,const std::string& columnValue);
    
    
    /**
     * 根据一个字段多个值的条件，组装查询sql
     * @param tableName 表名
     * @param columnName 条件column名
     * @param columnValues 条件column 所有可能的值
     */
    std::string getExecuteSql(const std::string& tableName,const std::string& columnName,const cocos2d::ValueVector& columnValues);
    
    //执行更新的sql
    bool executeUpdate(const std::string& sql);
    
    // 返回查询结果  ValueVector - ValueMap
    cocos2d::ValueVector executeQuery(const std::string& sql);
    
    //转换条件字典为字符串
    std::string convertConditionMap(const cocos2d::ValueMap& conditionMap);
    
    //不需要指定列名，按顺序插入数据(此功能使用有风险，暂时废弃)
    bool insertIntoTable(const std::string& tableName,const cocos2d::ValueVector& valueArray);
    
};

#endif /* defined(__Framework__SQLite__) */
