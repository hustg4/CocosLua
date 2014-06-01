--[[
 description:ViewController的Lua部分
 author:wp_g4
 date:2014/05/06
 --]]

class("clsViewController",{create = function() return ViewController:create() end})

function clsViewController:show()
    self:getScene():showViewController(self)    
end

function clsViewController:hide()
    self:getScene():hideViewController(self)
end

function clsViewController:loadCCB(ccbFile)
    return cl.loadCCB(ccbFile,self)
end
