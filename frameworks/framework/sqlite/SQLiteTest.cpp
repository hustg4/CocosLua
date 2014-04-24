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

void SQLiteTest::run()
{
//    testDrop();
//        testCreate();
//    testInsert();
//    testDelete();
//    testUpdate();
    testSelect();
}


void SQLiteTest::testCreate()
{
    SQLite* sqlite = SQLite::openSQLite("db.sqlite");
    if (sqlite) {
        __Array* columnArray = __Array::create(__String::create("id"),__String::create("name"),__String::create("age"),NULL);
        bool res = sqlite->createTable("people", columnArray);
        if (res) {
            CCLOG("创建表成功");
        }else{
            CCLOG("创建表失败");
        }
    }else{
        CCLOG("打开数据库失败");
    }
}

void SQLiteTest::testDrop()
{
    SQLite* sqlite = SQLite::openSQLite("db.sqlite");
    if (sqlite) {
        bool res = sqlite->dropTable("people");
        if (res) {
            CCLOG("删除表成功");
        }else{
            CCLOG("删除表失败");
        }
    }else{
        CCLOG("打开数据库失败");
    }
}

void SQLiteTest::testInsert()
{
    SQLite* sqlite = SQLite::openSQLite("db.sqlite");
    __Dictionary* dict = __Dictionary::create();
    dict->setObject(__String::create("wangpeng"), "name");
    dict->setObject(__String::create("27"), "age");
    dict->setObject(__String::create("108"), "id");
    bool res = sqlite->insertIntoTable("people", dict);
    if (res) {
        CCLOG("插入成功");
    }else{
        CCLOG("插入失败");
    }
}

void SQLiteTest::testDelete()
{
    SQLite* sqlite = SQLite::openSQLite("db.sqlite");
    bool res = sqlite->deleteFromTable("people", "age","27");
    if (res) {
        CCLOG("删除成功");
    }else{
        CCLOG("删除失败");
    }
}

void SQLiteTest::testUpdate()
{
    SQLite* sqlite = SQLite::openSQLite("db.sqlite");
    __Dictionary* dict = __Dictionary::create();
    dict->setObject(__String::create("wp_g4"), "name");
    bool res = sqlite->updateTable("people", dict,"age","27");
    if (res) {
        CCLOG("更新成功");
    }else{
        CCLOG("更新失败");
    }
}

void SQLiteTest::testSelect()
{
    SQLite* sqlite = SQLite::openSQLite("db.sqlite");
    __Dictionary* cndDict = __Dictionary::create();
    cndDict->setObject(__String::create("28"), "age");
    __Array* ids = __Array::create(__String::create("wangpeng"),__String::create("wp"),NULL);
    __Array* array = sqlite->selectTable("people", "name",ids);
    CCLOG("count:%ld",array->count());
    for (int i=0; i<array->count(); i++) {
        __Dictionary* dict = (__Dictionary*)array->getObjectAtIndex(i);
        __Array* keyArray = dict->allKeys();
        CCLOG("===================");
        for (int j=0; j<keyArray->count(); j++) {
            __String* key = (__String*)keyArray->getObjectAtIndex(j);
            __String* value = (__String*)dict->objectForKey(key->getCString());
            CCLOG("key:%s value:%s",key->getCString(),value->getCString());
        }
    }
}

void SQLiteTest::testGetRecordCount()
{
    SQLite* sqlite = SQLite::openSQLite("dwx.rdb");
    int count = sqlite->getRecordCount("b_lang");
    printf("count:%d",count);
}
