--[[
 description:粒子场景
 author:wp_g4
 date:2013/03/28
 --]]
 
require ("scene/particle/clsParticleViewController")

class("clsParticleScene",{create=function() return GameScene:create() end})

function clsParticleScene:onEnter()
    local particleViewController = clsParticleViewController:create()
    self:loadViewController(particleViewController)
end

function clsParticleScene:onExit()

end