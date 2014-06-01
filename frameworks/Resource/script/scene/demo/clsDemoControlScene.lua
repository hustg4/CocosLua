
--[[
 description:demo control场景
 author:qiuwenbo
 date:2014/05/03
 --]]


require ("scene/demo/clsDemoControlViewController")

class("clsDemoControlScene",clsGameScene)

function clsDemoControlScene:onEnter()
    self:loadViewController(clsDemoControlViewController)

    self:showViewController(clsDemoControlViewController)
end

function clsDemoControlScene:onExit()
end