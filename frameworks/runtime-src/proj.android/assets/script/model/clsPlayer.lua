
--[[
 description:玩家
 author:wp_g4
 date:2013/03/28
 --]]

luaclass("clsPlayer",clsModel)

--常量
clsPlayer.MAX_AGE = 100

--字段
clsPlayer.age = NULL           --年龄

function clsPlayer:init()
    print("clsPlayer:init:",self)
end

function clsPlayer:updateFromDB()
    print("clsPlayer:updateFromDB",self)
    print("age:"..self.age)
    self.age = 100
end

--检查玩家年龄是否有效
function clsPlayer:isAgeValid()
    return self.age < clsPlayer.MAX_AGE
end

local test = false

if not test then
    return
end


--- test code
local player = clsPlayer:new()

print("age=".. tostring(player.age))
player.age = 6
print("age="..player.age)

player.updateFlag = true
--player.hp = 5;
--print("hp="..player.hp)
print("age="..player.age)

--- end test


--test
print("===================")
luaclass("clsXXPlayer",clsPlayer)

clsXXPlayer.tall = NULL

function clsXXPlayer:init()
    print("self:"..tostring(self))
    print("clsXXPlayer:init")
end

function clsXXPlayer:updateFromDB()
    print("self:"..tostring(self))
    print("clsXXPlayer:updateFromDB")
    self.tall = true
    self.age = 29
end

local player = clsXXPlayer:new()

print("age=".. tostring(player.age))
player.age = 6
print("age="..player.age)

player.updateFlag = true
--player.hp = 5;
--print("hp="..player.hp)
print("age="..player.age)

--end test

--test
print("==================")

luaclass("clsYYPlayer",clsXXPlayer)

clsYYPlayer.num = NULL

function clsYYPlayer:init()
    print("self:"..tostring(self))
    print("clsYYPlayer:init")
end

function clsYYPlayer:updateFromDB()
    print("self:"..tostring(self))
    print("clsYYPlayer:updateFromDB")
    clsYYPlayer.num=100
end

local player = clsYYPlayer:new()
print("---------")
player.age=101
player.updateFlag = true
print(player.age)
print(player.tall)
print(player.num)

--end test
