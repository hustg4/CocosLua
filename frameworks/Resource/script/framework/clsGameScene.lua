--[[
 description:GameScene的Lua实现
 author:wp_g4
 date:2014/05/06
 --]]

class("clsGameScene",{create = function(...) return GameScene:create(...) end})

--覆盖C++中的api
function clsGameScene:loadViewController(viewController)
    local name = viewController.className
    self:callOrigin("loadViewController",name,viewController)
end

function clsGameScene:unloadViewController(viewControllerCls)
    self:callOrigin("unloadViewController",viewControllerCls.className)
end

function clsGameScene:getViewController(viewControllerCls)
    self:callOrigin("getViewController",viewControllerCls.className)
end

function clsGameScene:showViewController(viewControllerCls)
    self:callOrigin("showViewController",viewControllerCls.className)
end

function clsGameScene:hideViewController(viewControllerCls)
    self:callOrigin("hideViewController",viewControllerCls.className)
end