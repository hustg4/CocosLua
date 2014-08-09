//
//  SQLiteTest.cpp
//  Framework
//
//  Created by wp_g4 on 13-5-13.
//
//

#include "SQLiteTest.h"
#include "libsqlite/sqlite3.h"
#include "cocos2d.h"
#include "SQLite.h"

using namespace cocos2d;

//注:测试在macos上进行，

#define DB_PATH "/Users/wangpeng/Desktop/db.sqlite"

void SQLiteTest::run()
{
//    testDrop();
//    testCreate();
//    testInsert();
//    testDelete();
//    testUpdate();
    testSelect();
}


void SQLiteTest::testCreate()
{
    SQLite* sqlite = SQLite::openSQLite(DB_PATH);
    if (sqlite) {
        ValueVector valueVector;
        valueVector.push_back(Value("id"));
        valueVector.push_back(Value("name"));
        valueVector.push_back(Value("age"));
        bool res = sqlite->createTable("people", valueVector);
        if (res) {
            CCLOG("successful");
        }else{
            CCLOG("failure");
        }
    }else{
        CCLOG("failure");
    }
}

void SQLiteTest::testDrop()
{
    SQLite* sqlite = SQLite::openSQLite(DB_PATH);
    if (sqlite) {
        bool res = sqlite->dropTable("people");
        if (res) {
            CCLOG("successful");
        }else{
            CCLOG("failure");
        }
    }else{
        CCLOG("failure");
    }
}

void SQLiteTest::testInsert()
{
    SQLite* sqlite = SQLite::openSQLite(DB_PATH);
    
    ValueMap valueMap;
    valueMap["name"] = "wangpeng";
    valueMap["age"] = "27";
    valueMap["id"] = "108";
    bool res = sqlite->insertIntoTable("people", valueMap);
    if (res) {
        CCLOG("插入成功");
    }else{
        CCLOG("插入失败");
    }
}

void SQLiteTest::testDelete()
{
    SQLite* sqlite = SQLite::openSQLite(DB_PATH);
    bool res = sqlite->deleteFromTable("people", "age","27");
    if (res) {
        CCLOG("删除成功");
    }else{
        CCLOG("删除失败");
    }
}

void SQLiteTest::testUpdate()
{
    SQLite* sqlite = SQLite::openSQLite(DB_PATH);
    
    ValueMap map;
    map["name"] = "wp_g4";
    
    bool res = sqlite->updateTable("people", map,"age","27");
    if (res) {
        CCLOG("更新成功");
    }else{
        CCLOG("更新失败");
    }
}

void SQLiteTest::testSelect()
{
    SQLite* sqlite = SQLite::openSQLite(DB_PATH);
    
    ValueVector ids;
    ids.push_back(Value("wangpeng"));
    ids.push_back(Value("wp"));
    
    ValueVector array = sqlite->selectTable("people", "name",ids);
    CCLOG("count:%ld",array.size());
    for (int i=0; i<array.size(); i++) {
        ValueMap map = array[i].asValueMap();
        for (auto iter = map.cbegin(); iter != map.cend(); ++iter)
        {
            std::string key = iter->first;
            std::string value = iter->second.asString();
            CCLOG("key:%s value:%s",key.c_str(),value.c_str());
        }
    }
}

void SQLiteTest::testGetRecordCount()
{
    SQLite* sqlite = SQLite::openSQLite("dwx.rdb");
    int count = sqlite->getRecordCount("b_lang");
    printf("count:%d",count);
}
