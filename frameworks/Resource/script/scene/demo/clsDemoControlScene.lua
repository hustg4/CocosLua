
--[[
 description:demo control场景
 author:qiuwenbo
 date:2014/05/03
 --]]


require ("scene/demo/clsDemoControlViewController")

class("clsDemoControlScene",clsGameScene)

function clsDemoControlScene:onEnter()
    local viewController=clsDemoControlViewController:create()
    self:loadViewController(viewController)

    self:showViewController(viewController)
end

function clsDemoControlScene:onExit()
end