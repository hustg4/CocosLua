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
	scene:showViewController(viewControllerClsOrInstance)
end

function cl.hideViewController(viewControllerClsOrInstance)
	local scene = SceneManager:getInstance():getCurrentScene()
	scene:hideViewController(viewControllerClsOrInstance)
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
    return cc.Director:getInstance():getOpenGLView():getDesignResolutionSize()
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
--使用范例:cl.searchChild(node,123)
function cl.searchChild(node,tag,_includeSelf)
    if _includeSelf and node:getTag() == tag then
        return node
    end
    
    local result
    
    local childArray = node:getChildren()
    
    for i,child in ipairs(childArray) do
        
        result = cl.searchChild(child,tag,true)
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

function cl.loadCCB(ccbFile,owner)
    local proxy = cc.CCBProxy:create()
    local ccbReader = proxy:createCCBReader()
    local node = ccbReader:load(ccbFile)

    --Callbacks
    local ownerCallbackNames = ccbReader:getOwnerCallbackNames() 
    local ownerCallbackNodes = ccbReader:getOwnerCallbackNodes()
    local ownerCallbackControlEvents = ccbReader:getOwnerCallbackControlEvents()
    local i = 1
    for i = 1,table.getn(ownerCallbackNames) do
        local callbackName =  ownerCallbackNames[i]
        local callbackNode =  tolua.cast(ownerCallbackNodes[i],"cc.Node")
        if "function" == type(owner[callbackName]) then
            proxy:setCallback(callbackNode, cl.makeScriptHandler(owner,owner[callbackName]), ownerCallbackControlEvents[i])
        else
            print("Warning: Cannot find ViewController's lua function:" .. ":" .. callbackName)
        end

    end

    --Variables
    local ownerOutletNames = ccbReader:getOwnerOutletNames() 
    local ownerOutletNodes = ccbReader:getOwnerOutletNodes()

    for i = 1, table.getn(ownerOutletNames) do
        local outletName = ownerOutletNames[i]
        local outletNode = tolua.cast(ownerOutletNodes[i],"cc.Node")
        owner[outletName] = outletNode
    end

    local nodesWithAnimationManagers = ccbReader:getNodesWithAnimationManagers()
    local animationManagersForNodes  = ccbReader:getAnimationManagersForNodes()
    
    for i = 1 , table.getn(nodesWithAnimationManagers) do
        local innerNode = tolua.cast(nodesWithAnimationManagers[i], "cc.Node")
        local animationManager = tolua.cast(animationManagersForNodes[i], "cc.CCBAnimationManager")
        innerNode.animationManager = animationManager
        
        --Setup timeline callbacks
        local keyframeCallbacks = animationManager:getKeyframeCallbacks()

        for i = 1 , table.getn(keyframeCallbacks) do
            local callbackCombine = keyframeCallbacks[i]
            local beignIndex,endIndex = string.find(callbackCombine,":")
            local callbackType    = tonumber(string.sub(callbackCombine,1,beignIndex - 1))
            local callbackName    = string.sub(callbackCombine,endIndex + 1, -1)
            
            --Owner callback
            if 2 == callbackType then
                --print("callbackName:"..callbackName.." callbackType:"..callbackType)
                if "function" == type(owner[callbackName]) then
                    local callfunc = cc.CallFunc:create(cl.makeScriptHandler(owner,owner[callbackName]))
                    animationManager:setCallFuncForLuaCallbackNamed(callfunc, callbackCombine)
                else
                    print("Warning: Cannot find ViewController's lua function:" .. ":" .. callbackName)
                end
            end
        end
        --start animation
        local autoPlaySeqId = animationManager:getAutoPlaySequenceId()
        if -1 ~= autoPlaySeqId then
            animationManager:runAnimationsForSequenceIdTweenDuration(autoPlaySeqId, 0)
        end
    end

    return node
end


--=============== ===============
