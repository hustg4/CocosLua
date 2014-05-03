
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
	local arg = pairlist(...)
    print(#arg)
    print(self.ccbItemCheck == arg[2])
    print(arg[1])
    print(arg[2])
end

