
--[[
 description:CCB测试场景
 author:wp_g4
 date:2013/08/13
 --]]

require ("scene/ccb/clsCCBTestViewController")

class("clsCCBTestScene",clsGameScene)

function clsCCBTestScene:onEnter()
    local ccbTestViewController=clsCCBTestViewController:create()
    self:loadViewController(ccbTestViewController)
end

function clsCCBTestScene:onExit()
end

