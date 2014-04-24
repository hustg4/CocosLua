//
//  SQLiteTest.h
//  Framework
//
//  Created by wp_g4 on 13-5-13.
//
//

#ifndef __Framework__SQLiteTest__
#define __Framework__SQLiteTest__

#include <iostream>

class SQLiteTest {
    
public:
    
    static void run();
    
    static void testCreate();
    
    static void testDrop();
    
    static void testInsert();
    
    static void testDelete();
    
    static void testUpdate();
    
    static void testSelect();
    
    static void testGetRecordCount();
    
};

#endif /* defined(__Framework__SQLiteTest__) */
