--[[
 description:系统扩展，系统级别的api
 author:wp_g4
 date:2013/03/23
 --]]

--浅拷贝 t2->t1(t2中的键值copy到t1)
function table.scopy(t1,t2)
    if t1 and t2 then
        for k,v in pairs(t2) do
            t1[k]=v
        end
    end
end

--深拷贝 t2->t1(t2中的键值copy到t1)
function table.dcopy(t1,t2)
    if t1 and t2 then
        for k,v in pairs(t2) do
            if type(v)=="table" then
                if type(t1[k])~="table" then
                    t1[k]={}
                end
                table.dcopy(t1[k],v)
            else
                t1[k]=v
            end
        end
    end
end

--获取表t中键值对的数量
function table.size(t)
    local count = 0
    for k,v in pairs(t) do
        count = count +1
    end
    return count
end

--获取表t中所有的键
function table.allKeys(t)
    local keys = {}
    for k,v in pairs(t) do
        table.insert(keys,k)
    end
    return keys
end

--格式化输出表t
function table.dump(t, max_level, prefix)
    if type(prefix) ~= "string" then
        prefix = ""
    end
    if type(max_level)~="number" then
        max_level = 10
    end
    if type(t) ~= "table" then
        print(prefix .. tostring(t))
        else
        print(t)
        if max_level ~= 0 then
            local prefix_next = prefix .. "    "
            print(prefix .. "{")
            for k,v in pairs(t) do
                io.stdout:write(prefix_next .. k .. " = ")
                if type(v) ~= "table" or (type(max_level) == "number" and max_level <= 1) then
                    print(v)
                    else
                    if max_level == nil then
                        var_dump(v, nil, prefix_next)
                        else
                        table.dump(v, max_level - 1, prefix_next)
                    end
                end
            end
            print(prefix .. "}")
        end
    end
end 

--锁定表，使得表不能再插入新的k-v
function table.lockInsert(t)
    local _t = t
    t = {}
    local mt = {
        __index = _t,
        
        __newindex = function(t,k,v)
        assert(type(_t[k])~="nil", "table \"".. tostring(t) .."\" can't insert the key \""..k.."\"")
        _t[k] = v
        end
    }
    setmetatable(t,mt)
    return t
end


--将可变参数装包
function pairlist(...)
    local arg = {}
    for i=1,select("#",...) do
        local item = select(i,...)
        table.insert(arg,item)
    end
    return arg
end

function string.indexOf(str,ch)
    
    local t = {}      -- table to store the indices
    local i = 0
    while true do
        i = string.find(str,ch, i+1)   -- find 'next' newline
        if i == nil then break end
        table.insert(t, i)
    end
    
    return t
    
end

StringUtil = {}

function StringUtil:trim(str)
    return str:match("^%s*(.-)%s*$")
end

function StringUtil:length(str)
    local _ , len = string.gsub(str, "[^\128-\191]", "")
    return len
end

function StringUtil:charArray(str)
    local charArray = {}
    for c in string.gfind(str, "[%z\1-\127\192-\253][\128-\191]*") do
        table.insert(charArray,c)
    end
    return charArray
end

function StringUtil:subString(str,startIndex,endIndex)
    local substr = ""
    local charArray = StringUtil:charArray(str)
    for i = startIndex,endIndex do
        substr = substr..charArray[i]
    end
    return substr
end

