
--[[
 
 description:此函数用于生成"C++类"的子类
 
 param: className 类名，必需是字符串
 
 param: super "父类"或者"构造'C++实例'的function列表"
 
        (1) super是"构造'C++实例'的function列表"时，调用方式如下：
            
            class("clsSprite",{create = function() return cc.Sprite:create() end})
 
            "构造'C++实例'的function列表"是一个lua table,key是function名，value为是一个function,function的功能是创建一个"C++实例"
 
            对于每一对key-value，class函数会在"生成的类"中添加相应的构造函数，示例代码会生成一个名称为clsSprite的类，有一个构造函数create
 
            调用clsSprite:create() 即可创建出一个实例
 
 
        (2) super是"父类"时，调用方式如下：
 
            class("clsMySprite",clsSprite)
 
            生成一个名称为clsMySprite的类，其父类是clsSprite，clsSprite必需是通过class函数生成出来的类
 
            子类会继承父类已经定义的所有函数，如clsMySprite:create() 
 
 author:wp_g4
 
 date:2013/05/23
 
 --]]

function class(className,super)
    
    --TODO 先对所有参数进行检查 className不能为空;super必需是通过class函数构造出来的table,或者是构造函数列表
    
    local cls = {}
    
    --记录类名
    cls.className = className
    
    --设置__index为自己,类会被继承
    cls.__index = cls
    
    --判断super类型，如果是class函数构造出来的table，会有className属性，否则认为super是构造函数列表
    
    if super.className then  --super是一个class函数构造出来的table
        
        --设置父类
        setmetatable(cls,super)
    
    else  --super是创建 "C++ 实例" 的function列表
    
        cls.cinstanceList={}
        
        --定义 构造函数
        for name,constructor in pairs(super) do
            cls[name] =function(...)
            
            local arg = pairlist(...)
            
            
                --通过冒号 “:” 调用function，第一个参数是类本身（cls）
                local self = arg[1]
                table.remove(arg,1)
            
                --调用super中的function得到 "C++ 实例"
                local cinstance = constructor(unpack(arg))
                table.insert(self.cinstanceList,cinstance)
            
                --从类中实例化一个子表作为"C++ 实例"的peertable
                --不直接用类作为"C++ 实例"的peertable的原因是，实例会有多个
                local peertable = {}
                setmetatable(peertable,self)
            
                tolua.setpeer(cinstance,peertable)
            
                return cinstance
            end
        end
    
        --定义调用 "'C++ 实例'原始函数"的函数
        function cls:callOrigin(functionName,...)
            
            --取"C++ 实例"的peertable
            --self就是"C++ 实例"
            local peertable = tolua.getpeer(self)
            
            --将"C++ 实例"的peertable置空，以便能调到原始函数
            tolua.setpeer(self,nil)
            
            --调用原始函数
            local ret = self[functionName](self,...)
            
            --还原peertable
            tolua.setpeer(self,peertable)
            
            return ret
        end
    
    end
    _G[className] = cls
end
