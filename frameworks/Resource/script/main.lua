--[[
 description:脚本入口点
 author:wp_g4
 date:2013/03/13
 --]]

require ("framework/Config")
require ("framework/class")
require ("framework/luaclass")
require ("framework/clsModel")
require ("framework/SystemExtend")
require ("framework/FrameworkExtend")
require ("framework/Notifier")
require ("framework/functions")
require ("framework/SQLiteLua")
    
require ("ui/clsButton")
    
require ("const/NotifyEvent")
    
require ("net/NetConfig")    
require ("net/MessageSender")
    
require ("model/GameData")
    
require ("scene/ccb/clsCCBTestScene")
require ("scene/drag/clsDragScene")
require ("scene/login/clsLoginScene")
require ("scene/map/clsMapScene")
require ("scene/update/clsUpdateScene")
require ("scene/particle/clsParticleScene")
require ("scene/demo/clsDemoScene")
require ("scene/demo/clsDemoControlScene")

--游戏启动
function Game:onStart()

    print("Game:onStart")
    
    --加载网络配置
    self:loadNetConfig()
    
    --启动场景
    --ReplaceScene(clsParticleScene)
    --ReplaceScene(clsLoginScene)
    --ReplaceScene(clsDemoScene)
    ReplaceScene(clsCCBTestScene)
    -- ReplaceScene(clsDemoControlScene)
end

--游戏停止
function Game:onStop()
    print("Game:onStop")
end

--加载网络配置
function Game:loadNetConfig()
    local netCenter=NetCenter:sharedNetCenter()
    
    --filters
    for _,filterClass in ipairs(NetConfig.Filters) do
        netCenter:addNetFilter(filterClass:create())
    end
    
    --protocols
    for _,protocolConfig in ipairs(NetConfig.Protocols) do
        local protocolId = protocolConfig.protocolId
        local serviceId = protocolConfig.serviceId
        local handlerClass = protocolConfig.handlerClass
        local handler = handlerClass:create()
        netCenter:addNetProtocol(protocolId,serviceId,handler)
    end
    
end
