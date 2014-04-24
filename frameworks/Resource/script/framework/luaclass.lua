
--[[
 
 description:此函数用于创建model类
 
 param: className 类名，必需是字符串
 
 param: super 父类
 
 author:wp_g4
 
 date:2013/09/09
 
 --]]

function luaclass(className,super)
    
    --TODO 先对所有参数进行检查 className不能为空;super必需是通过luaclass函数构造出来的table
    
    local cls = {}
    
    --记录类名
    cls.className = className
    
    --设置__index为自己,类会被继承或者实例化
    cls.__index = cls
    
    --设置父类
    cls.super = super
    setmetatable(cls,super)
    
    if not super then
        --外部使用的构造函数,静态
        function cls:new()
            local obj=self:__ctor()
            return obj
        end
    
        --内部使用的真正的构造函数，静态，外部不可调用
        function cls:__ctor()
            local obj
            if self.super then
                obj = self.super:__ctor()
                else
                obj={}
            end
            setmetatable(obj,self)
            obj.class = self
            obj:init()
            return obj
        end
    end
    
    --初始化函数
    function cls:init()
        --外部可重写此函数进行初始化
    end
    
    _G[className] = cls
end
