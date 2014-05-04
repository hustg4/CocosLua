
--[[
 description:CCB测试
 author:wp_g4
 date:2013/08/13
 --]]

class("clsCCBTestViewController",clsViewController)

clsCCBTestViewController.layer=nil

function clsCCBTestViewController:load()
    self:showView()
end

function clsCCBTestViewController:showView()
    
    self:loadCCB("ccb/MainScene.ccbi")
    self:getScene():addChild(self.ccbRootLayer)

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
end

function clsCCBTestViewController:onCCBFileControlButtonTapped(...)
	print("onCCBFileControlButtonTapped")
	local arg = pairlist(...)
    print(#arg)
    print(arg[1]==self.ccbfileControlButton)
    print(arg[2])
    print(self.ccbControlButton)
end

