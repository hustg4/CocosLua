--[[
 description:ViewController的Lua部分
 author:wp_g4
 date:2014/05/06
 --]]

class("clsViewController",{create = function() return ViewController:create() end})

function clsViewController:createWithCCB(ccbFile)
    local controller = self:create()
    local nodeCCB = controller:loadCCB(ccbFile)
    controller:setRootLayer(nodeCCB)
    controller:onDidLoadFromCCB()
    return controller
end

function clsViewController:onDidLoadFromCCB()
    --override me
end

--被C++调用，时机是load()之后
function clsViewController:registerEvents()
	self._eventNames_ = self:eventNames()
	if self._eventNames_ then
		for eventName,callback in pairs(self._eventNames_) do
			Notifier:addObserver(eventName,self,callback)
		end
	end
end

--被C++调用，时机是unload()之前
function clsViewController:unregisterEvents()
	if self._eventNames_ then
		for eventName,_ in pairs(self._eventNames_) do
			Notifier:removeObserver(eventName,self)
		end
	end
end

--具体的ViewController根据需要覆盖，返回所要关心的事件列表
function clsViewController:eventNames()
	--override me
	--sample
	--return {"eventName1","eventName2","eventName3"};
end

function clsViewController:show()
    self:getScene():showViewController(self)    
end

function clsViewController:hide()
    self:getScene():hideViewController(self)
end

function clsViewController:loadCCB(ccbFile)
    return cl.loadCCB(ccbFile,self)
end
