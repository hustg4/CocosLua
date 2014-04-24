--[[
 description: drag demo
 author:wxf
 date:2013/06/26
 --]]



require ("scene/drag/clsDragViewController")

class("clsDragScene",clsGameScene)

function clsDragScene:onEnter()
    local dragViewController=clsDragViewController:create()
    self:loadViewController(dragViewController)
end

function clsDragScene:onExit()

end