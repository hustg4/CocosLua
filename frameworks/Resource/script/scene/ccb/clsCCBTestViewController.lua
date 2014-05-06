
--[[
 description:CCB测试
 author:wp_g4
 date:2013/08/13
 --]]

class("clsCCBTestViewController",clsViewController)

local EVENT_SCALE_END = "scaleEnd"
local EVENT_ROTATION_END = "rotationEnd"

function clsCCBTestViewController:load()
    self:showView()
end

function clsCCBTestViewController:showView()
    self:loadCCB("ccb/MainScene.ccbi")
    self:addSceneNode(self.ccbRootLayer)
    print("self.checkRootNode:"..tostring(self.checkRootNode))
    print("self.nodeCheck:"..tostring(self.nodeCheck))
end

function clsCCBTestViewController:unload()
    
end

function clsCCBTestViewController:eventNames()
    return {EVENT_SCALE_END,EVENT_ROTATION_END}
end

--被Notifier调用
function clsCCBTestViewController:onEvent(eventName,...)
    print("eventName:",eventName,"params:",...)
    if eventName == EVENT_SCALE_END then
        print("收到缩放完毕事件")
    elseif eventName == EVENT_ROTATION_END then
        print("收到旋转完毕事件")
    end
end

function clsCCBTestViewController:onItemCheckTapped(...)
	print("onItemCheckTapped")
	local arg = pairlist(...)
    print(#arg)
    print(self.ccbItemCheck == arg[2])
    print(arg[1])
    print(arg[2])
    print(self.ccbItemCheck)
end

function clsCCBTestViewController:onControlButtonTapped(...)
	print("onControlButtonTapped")
	local arg = pairlist(...)
    print(#arg)
    print(arg[1]==self.ccbControlButton)
    print(arg[2])
    print(self.ccbControlButton)
end

function clsCCBTestViewController:onCCBFileItemCheckTapped(...)
	print("onCCBFileItemCheckTapped")
	local arg = pairlist(...)
    print(#arg)
    print(self.ccbfileItemCheck == arg[2])
    print(arg[1])
    print(arg[2])
    print(self.ccbfileItemCheck)
end

function clsCCBTestViewController:onCCBFileControlButtonTapped(...)
	print("onCCBFileControlButtonTapped")
	local arg = pairlist(...)
    print(#arg)
    print(arg[1]==self.ccbfileControlButton)
    print(arg[2])
    print(self.ccbfileControlButton)
end

function clsCCBTestViewController:OnScaleEnd(...)
    print("OnScaleEnd")
	local arg = pairlist(...)
    print(#arg)
    print(self.nodeCheck == arg[1])
    --self.ccbRootLayer.animationManager:runAnimationsForSequenceNamed("TL1")
    Notifier:notify(EVENT_SCALE_END,"hello",109)
end

function clsCCBTestViewController:OnRotationEnd(...)
    print("OnRotationEnd")
	local arg = pairlist(...)
    print(#arg)
    print(self.ccbRootLayer == arg[1])
    --self.ccbRootLayer:removeFromParent()
    Notifier:notify(EVENT_ROTATION_END,12,18,"xxx")
end

