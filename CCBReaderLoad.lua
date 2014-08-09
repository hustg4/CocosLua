
function CCBReaderLoad(strFilePath,proxy,owner)
    if nil == proxy then
        return nil
    end

    local ccbReader = proxy:createCCBReader()
    local node      = ccbReader:load(strFilePath)
    local rootName  = "" 
    --owner set in readCCBFromFile is proxy
    if nil ~= owner then
        --Callbacks
        local ownerCallbackNames = ccbReader:getOwnerCallbackNames() 
        local ownerCallbackNodes = ccbReader:getOwnerCallbackNodes()
        local ownerCallbackControlEvents = ccbReader:getOwnerCallbackControlEvents()
        local i = 1
        for i = 1,table.getn(ownerCallbackNames) do
            local callbackName =  ownerCallbackNames[i]
            local callbackNode =  tolua.cast(ownerCallbackNodes[i],"cc.Node")
            if "function" == type(owner[callbackName]) then
                proxy:setCallback(callbackNode, MakeScriptHandler(owner,owner[callbackName]), ownerCallbackControlEvents[i])
            else
                print("Warning: Cannot find owner's lua function:" .. ":" .. callbackName)
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
            if 2 == callbackType and nil ~= owner then
                --print("callbackName:"..callbackName.." callbackType:"..callbackType)
                if "function" == type(owner[callbackName]) then
                    local callfunc = cc.CallFunc:create(MakeScriptHandler(owner,owner[callbackName]))
                    animationManager:setCallFuncForLuaCallbackNamed(callfunc, callbackCombine)
                else
                    print("Warning: Cannot find owner's lua function:" .. ":" .. callbackName)
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


local function CCBuilderReaderLoad(strFilePath,proxy,owner)
    print("\n********** \n".."CCBuilderReaderLoad(strFilePath,proxy,owner)".." was deprecated please use ".. "CCBReaderLoad(strFilePath,proxy,owner)" .. " instead.\n**********")
    return CCBReaderLoad(strFilePath,proxy,owner)
end
rawset(_G,"CCBuilderReaderLoad",CCBuilderReaderLoad)
