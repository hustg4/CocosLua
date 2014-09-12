
--[[
 description:CCB测试
 author:wp_g4
 date:2013/08/13
 --]]

class("clsCCBTestViewController",clsViewController)

local EVENT_SCALE_END = "scaleEnd"
local EVENT_ROTATION_END = "rotationEnd"

function clsCCBTestViewController:load()
    local ccblayer = self:loadCCB("ccb/MainScene.ccbi")
    print("ccblayer",ccblayer)
    self:setRootLayer(ccblayer)
end

function clsCCBTestViewController:unload()
    
end


function clsCCBTestViewController:onScaleEndEvent(eventName,...)
    print("onScaleEndEvent:",eventName,"params:",...)
end

function clsCCBTestViewController:onRotationEndEvent(eventName,...)
    print("onRotationEndEvent:",eventName,"params:",...)
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

