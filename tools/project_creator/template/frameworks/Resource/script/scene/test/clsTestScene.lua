
--[[
 description:测试场景
 author:wp_g4
 date:2014/05/19
 --]]


require ("scene/test/clsTestViewController")

class("clsTestScene",clsGameScene)

function clsTestScene:onEnter()
    
    --测试
    local testViewController = clsTestViewController:create()
    self:loadViewController(testViewController)

    self:showViewController(clsTestViewController)
end

function clsTestScene:onExit()
    
end

