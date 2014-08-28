--[[
 description:GameScene的Lua实现
 author:wp_g4
 date:2014/05/06
 --]]

class("clsGameScene",{create = function(...) return GameScene:create(...) end})

--覆盖C++中的api
function clsGameScene:loadViewController(viewControllerCls)
    local viewController = viewControllerCls:create()
    local name = viewController.className
    self:callOrigin("loadViewController",name,viewController)
end

function clsGameScene:unloadViewController(viewControllerClsOrInstance)
    self:callOrigin("unloadViewController",viewControllerClsOrInstance.className)
end

function clsGameScene:getViewController(viewControllerClsOrInstance)
	--TODO 此接口是否应该废除待考虑
    return self:callOrigin("getViewController",viewControllerClsOrInstance.className)
end

function clsGameScene:showViewController(viewControllerClsOrInstance,data)
	local viewController = self:callOrigin("getViewController",viewControllerClsOrInstance.className)
	if viewController then
		viewController.data = data
	end
    self:callOrigin("showViewController",viewControllerClsOrInstance.className)
end

function clsGameScene:hideViewController(viewControllerClsOrInstance)
    self:callOrigin("hideViewController",viewControllerClsOrInstance.className)
end

function clsGameScene:addMutexRelation(viewControllerClsOrInstance1,viewControllerClsOrInstance2)
    self:callOrigin("addMutexRelation",viewControllerClsOrInstance1.className,viewControllerClsOrInstance2.className)
end
    
function clsGameScene:removeMutexRelation(viewControllerClsOrInstance1,viewControllerClsOrInstance2)
    self:callOrigin("removeMutexRelation",viewControllerClsOrInstance1.className,viewControllerClsOrInstance2.className)
end
