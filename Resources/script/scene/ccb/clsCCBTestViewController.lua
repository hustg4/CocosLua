
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
    
    self.layer = ScriptCCBReader:readCCB("ccb/MainScene.ccbi", self)
    self:getScene():addChild(self.layer)

end

function clsCCBTestViewController:unload()
    
end

function clsCCBTestViewController:onClick(sender)
    print(sender)
end

