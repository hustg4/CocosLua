--[[
 description:版本更新场景
 author:wp_g4
 date:2013/03/28
 --]]
 
require ("scene/update/clsUpdateViewController")

class("clsUpdateScene",{create=function() return GameScene:create() end})

function clsUpdateScene:onEnter()
    self:loadViewController(clsUpdateViewController)
end

function clsUpdateScene:onExit()

end