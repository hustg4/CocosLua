--[[
 description:系统配置
 author:wp_g4
 date:2013/06/13
 --]]

require ("framework/SystemExtend")
require ("framework/Notifier")
require ("framework/class")
require ("framework/luaclass")
require ("framework/clsModel")
require ("framework/FrameworkExtend")
require ("framework/clsViewController")
require ("framework/clsGameScene")
require ("framework/functions")

MODEL_LOCK_DEBUG = true     --model 加锁开关

NULL = nil
if MODEL_LOCK_DEBUG then
    NULL = "null"
end

--=============== ===============

cl = cl or {}

function cl.showViewController(viewControllerClsOrInstance)
	local scene = SceneManager:getInstance():getCurrentScene()
	scene:showViewController(viewControllerClsOrInstance.className)
end

function cl.hideViewController(viewControllerClsOrInstance)
	local scene = SceneManager:getInstance():getCurrentScene()
	scene:hideViewController(viewControllerClsOrInstance.className)
end

function cl.runScene(sceneClass,paramTable)
    if type(sceneClass) == "string" then
        sceneClass = _G[sceneClass];
    end
    
    local scene = sceneClass["create"](sceneClass,paramDict)

    if paramTable then
        for k,v in pairs(paramTable) do
            scene:putAttribute(k,v)
        end
    end
    SceneManager:getInstance():runScene(scene)
end

--设计尺寸
function cl.designSize()
    return cc.EGLView:sharedOpenGLView():getDesignResolutionSize()
end

--获取子节点，根据多个tag沿树结构搜索
function cl.getChild(node,...)
    local arg = pairlist(...)
    local child = node
    for i,tag in ipairs(arg) do
        child = child:getChildByTag(tag)
    end
    return child
end

--在所有子结点中搜索指定tag的结点，递归搜索
--使用范例:SearchChild(node,123)
function cl.searchChild(node,tag,_includeSelf)
    if _includeSelf and node:getTag() == tag then
        return node
    end
    
    local result
    
    local childArray = node:getChildren()
    
    for i,child in ipairs(childArray) do
        
        result = SearchChild(child,tag,true)
        if result then
            break
        end
        
    end
    
    return result
end

--回调
function cl.callFunction(target,callback,...)
    if callback then
        local arg = pairlist(...)
        if type(callback)=="string" then
            if target then
                if target[callback] then
                    return target[callback](target,unpack(arg))
                end
            end
            else
            if target then
                return callback(target,unpack(arg))
                else
                return callback(unpack(arg))
            end
        end
    end
end

--构造script handler
function cl.makeScriptHandler(target,selector,...)
    local parg = pairlist(...)
    return function(...)
    local arg = pairlist(...)
    for _,v in ipairs(parg) do
        table.insert(arg,v)
    end
    arg.n = table.maxn(arg)
    return selector(target,unpack(arg))
end
end

--=============== ===============
