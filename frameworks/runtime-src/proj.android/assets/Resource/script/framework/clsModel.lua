
--[[
 description:数据模型的基类
 author:wp_g4
 date:2013/09/09
 --]]
 
luaclass("clsModel")

--模型更新标记，updateFlag为true时，下一次访问模型中任意字段，都会触发对updateFromDB()的调用，之后updateFlag会被置为false
clsModel.updateFlag = false

--模块更新次数
clsModel.updateTimes = 0

--外部使用的构造函数
function clsModel:new()
    local obj=self:__ctor()
    return obj:__createProxy()
end

--预定义函数，通过数据包更新模型
function clsModel:updateWithData(data)
    table.dcopy(self,data)
end

--预定义函数，当updateFlag为true时，调用此函数更新模型，此函数从db中取配置性数据更新到模型中
function clsModel:updateFromDB()
    print("clsModel:updateFromDB",self)
end

--内部使用的真正的更新操作,静态方法
function clsModel:__updateFromDB(obj)
    --本方法内的self是类，而不是实例
    if self.super then
        self.super:__updateFromDB(obj)
    end
    self.updateFromDB(obj)
end

--为对象创建一个代理，监控外部对对象字段的访问与更新，完成两个功能
--1、访问字段时检查updateFlag，如果值为true则调用updateFromDB
--2、如果是debug模式，禁止外部直接向对象里添加新字段
function clsModel:__createProxy()
    local obj = self
    local proxy = {}
    local mt = {
        __index = function(t,k)
        if type(obj[k])~="function" and obj.updateFlag then
            obj.updateFlag = false
            --注：updateFromDB中不能修改updateFlag的值，否则可能造成死循环
            obj.class:__updateFromDB(obj)
            obj.updateTimes = obj.updateTimes + 1
        end
        return obj[k]
        end,
        
        __newindex = function(t,k,v)
        if MODEL_LOCK_DEBUG then
            assert(type(obj[k])~="nil", "table \"".. tostring(t) .."\" can't insert the key \""..k.."\"")
        end
        obj[k] = v
        end
    }
    setmetatable(proxy,mt)
    return proxy
end

function clsModel:init()
    print("clsModel:init:",self)
end
