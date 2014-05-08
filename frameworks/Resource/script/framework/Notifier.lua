--[[
 description:观察者
 author:wp_g4
 date:2012/02/21
 --]]

--结构定义
clsObserver = {}
clsObserver.__index = clsObserver

--字段定义
clsObserver.target = nil
clsObserver.callback = nil

--构造器
function clsObserver:new(target,callback)
    local self = {}
    setmetatable(self,clsObserver)
    self.target = target
    self.callback = callback
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
function Notifier:addObserver(name,targetOrFunction,callback)
    if not self.observerMap[name] then
        self.observerMap[name] = {}
    end
    local list = self.observerMap[name]
    if type(targetOrFunction) == "function" then
        table.insert(list,clsObserver:new(nil,targetOrFunction))
    else
        table.insert(list,clsObserver:new(target,callback))
    end
end

--删除观察者
function Notifier:removeObserver(targetOrFunction,name)
    if name then
        self:_removeObserver_(targetOrFunction,name)
    else
        for name,_ in pairs(self.observerMap) do
            self:_removeObserver_(targetOrFunction,name)
        end
    end
end

--清空
function Notifier:clear()
    self.observerMap = {}
end

--发送通知
function Notifier:notify(name,...)
    local arg = pairlist(...)
    if self.observerMap[name] then
        local list = self.observerMap[name]
        for _,observer in pairs(list) do
            local target = observer.target
            local callback = observer.callback
            if callback then
                if target then
                    callback(target,name,unpack(arg))
                else
                    callback(name,unpack(arg))
                end
            else
                print("Notifier:observer[".. tostring(observer) .."]的callback不存在")
            end
        end
    end
end

--删除观察者
function Notifier:_removeObserver_(targetOrFunction,name)
    if self.observerMap[name] then
        local list = self.observerMap[name]
        local size = table.getn(list)
        local index = 0
        for i,observer in ipairs(list) do
            if observer.target == targetOrFunction or  observer.callback == targetOrFunction then
                index = i
                break
            end
        end
        if index ~= 0 then
            table.remove(list,index)
        end
    end
end

