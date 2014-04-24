--[[
 description:SQLite的派生类
 author:wenbo qiu
 date:2013/08/20
 --]]

class("SQLiteLua",{ openSQLite = function(...) return SQLite:openSQLite(...) end})

function SQLiteLua:selectTableAsLua(...)
    local resultArray = self:selectTable(...)
    resultArray = tolua.cast(resultArray,"CCArray")
    local tArray = {}
    local resultCount = resultArray:count()
    for i = 0 , resultCount-1 do
        local columnDict = tolua.cast(resultArray:objectAtIndex(i),"CCDictionary")
        local tObject = {}
        local columnNameArray = columnDict:allKeys()
        columnNameArray = tolua.cast(columnNameArray,"CCArray")
        local columnCount = columnNameArray:count()
        for j = 0 , columnCount-1 do
            local columnName = tolua.cast(columnNameArray:objectAtIndex(j),"CCString")
            local columnValue = tolua.cast(columnDict:objectForKey(columnName:getCString()),"CCString")
            tObject[columnName:getCString()] = columnValue:getCString()
        end
        table.insert(tArray,tObject)
    end
    return tArray
end

-- 查询符合多个条件的数据,以Lua Table包装返回结果
-- @param dbpath 数据库文件路径
-- @param tableName 表名
-- @param conditionDict 条件字典 (CCDictionary)
function SQLiteLua:selectTableByCondition(tablename, conditionDict)
    if type(conditionDict) == "table" then
        local conditionTable = conditionDict
        conditionDict = CCDictionary:create()
        for k,v in pairs(conditionTable) do
            conditionDict:setObject(CCString:create(v),k)
        end
    end
    conditionDict = tolua.cast(conditionDict,"Dictionary")
    local resultArray = self:selectTableAsLua(tablename,conditionDict)
    return resultArray
end

-- 查询符合单个条件的数据,以Lua Table包装返回结果
-- @param dbpath 数据库文件路径
-- @param tableName 表名
-- @param columnName 条件column名
-- @param columnValue 条件column值
function SQLiteLua:selectTableByValue(tablename, columnName, columnValue)
    local resultArray = self:selectTableAsLua(tablename,columnName,columnValue)
    return resultArray
end

-- 查询符合单个条件的数据,以Lua Table包装返回结果
-- @param dbpath 数据库文件路径
-- @param tableName 表名
-- @param columnName 条件column名
-- @param columnValues 条件column 所有可能的值 (CCArray)
function SQLiteLua:selectTableByValues(tablename, columnName, columnValues)
    local resultArray = self:selectTableAsLua(tablename,columnName,columnValues)
    return resultArray
end

-- 查询符合单个条件的数据,以Lua Table包装返回结果
-- @param dbpath 数据库文件路径
-- @param tableName 表名
-- @param sql 查询语句
function SQLiteLua:selectTableBySQL(tablename, sql)
    local resultArray = self:selectTableAsLua(tablename,sql)
    return resultArray
end