
--[[
 description:demo场景
 author:cokey
 date:2014/04/26
 --]]


require ("scene/demo/clsDemoViewController")

class("clsDemoScene",clsGameScene)

function clsDemoScene:onEnter()
    local demoViewController=clsDemoViewController:create()
    self:loadViewController(demoViewController)
end

function clsDemoScene:onExit()
end

