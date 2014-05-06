
--[[
 description:CCB测试
 author:wp_g4
 date:2013/08/13
 --]]

class("clsCCBTestViewController",clsViewController)

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
    self.ccbRootLayer.animationManager:runAnimationsForSequenceNamed("TL1")
end

function clsCCBTestViewController:OnRotationEnd(...)
    print("OnRotationEnd")
	local arg = pairlist(...)
    print(#arg)
    print(self.ccbRootLayer == arg[1])
    self.ccbRootLayer:removeFromParent()
end

