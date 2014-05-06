--[[
 description:观察者
 author:wp_g4
 date:2012/02/21
 --]]

--结构定义
clsObserver = {}
clsObserver.__index = clsObserver

--字段定义
clsObserver.target=nil
clsObserver.callback=nil

--构造器
function clsObserver:new(target,callback)
    local self = {}
    setmetatable(self,clsObserver)
    self.target=target
    if type(callback)=="function" then
        self.callback=callback
        else self.callback=target[callback]
    end
    return self
end

-------------------------------------------------------------------------
-------------------------------------------------------------------------

--[[
 description:游戏通知管理器
 author:wp_g4
 date:2012/02/21
 --]]

--初始化
Notifier={}

Notifier.observerMap={}   --观察者map

--添加观察者
function Notifier:addObserver(name,target,callback)
    if not self.observerMap[name] then
        self.observerMap[name]={}
    end
    local list=self.observerMap[name]
    table.insert(list,clsObserver:new(target,callback))
end

--删除观察者
function Notifier:removeObserver(name,target)
    if self.observerMap[name] then
        local list=self.observerMap[name]
        local size=table.getn(list)
        local index=0
        for i,observer in ipairs(list) do
            if observer.target==target then
                index=i
                break
            end
        end
        if index~=0 then
            table.remove(list,index)
        end
    end
end

--发送通知
function Notifier:notify(name,...)
    local arg = pairlist(...)
    if self.observerMap[name] then
        local list=self.observerMap[name]
        for _,observer in pairs(list) do
            if observer.callback then
                observer.callback(observer.target,name,unpack(arg))
                else
                print("Notifier-Log:observer[".. tostring(observer) .."]的callback不存在")
            end
        end
    end
end
