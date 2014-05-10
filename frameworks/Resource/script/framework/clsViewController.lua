--[[
 description:ViewController的Lua部分
 author:wp_g4
 date:2014/05/06
 --]]

class("clsViewController",{create = function() return ViewController:create(1) end})

--被C++调用，时机是load()之后
function clsViewController:registerEvents()
	self._eventNames_ = self:eventNames()
	if self._eventNames_ then
		for eventName,callback in pairs(self._eventNames_) do
			Notifier:addObserver(eventName,self,callback)
		end
	end
end

--被C++调用，时机是unload()之前
function clsViewController:unregisterEvents()
	if self._eventNames_ then
		for eventName,_ in pairs(self._eventNames_) do
			Notifier:removeObserver(eventName,self)
		end
	end
end

--具体的ViewController根据需要覆盖，返回所要关心的事件列表
function clsViewController:eventNames()
	--override me
	--sample
	--return {"eventName1","eventName2","eventName3"};
end

function clsViewController:loadCCB(ccbFile)

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
        if "function" == type(self[callbackName]) then
            proxy:setCallback(callbackNode, MakeScriptHandler(self,self[callbackName]), ownerCallbackControlEvents[i])
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
        self[outletName] = outletNode
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
                if "function" == type(self[callbackName]) then
                    local callfunc = cc.CallFunc:create(MakeScriptHandler(self,self[callbackName]))
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

