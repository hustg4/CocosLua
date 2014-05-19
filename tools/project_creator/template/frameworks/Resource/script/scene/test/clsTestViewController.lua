
--[[
 description:测试界面
 author:wp_g4
 date:2014/05/19
 --]]


class("clsTestViewController",clsViewController)


function clsTestViewController:load()
    self:initView()
end

function clsTestViewController:unload()
end

function clsTestViewController:layerWillAppear()
end

function clsTestViewController:layerDidDisappear()
end

function clsTestViewController:initView()
    
    self.layer = cc.Layer:create()
    self:setRootLayer(self.layer)
    
    local designSize = cl.designSize()
    local label = cc.LabelTTF:create("Hello World!","",30)
    label:setColor(cc.c3b(255,255,255))
    label:setPosition(cc.p(designSize.width/2,designSize.height/2))
    self.layer:addChild(label)
    
end
