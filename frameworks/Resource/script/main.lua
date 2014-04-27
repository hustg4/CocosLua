--[[
 description:脚本入口点
 author:wp_g4
 date:2013/03/13
 --]]

Game = {}

--启动游戏
function Game:start()
    
    --系统初始化
    self:init()
    
    --加载公共模块
    self:requireCommonModule()
    
    --加载网络配置
    self:loadNetConfig()
    
    --启动场景
    --ReplaceScene(clsParticleScene)
    --ReplaceScene(clsLoginScene)
    ReplaceScene(clsDemoScene)
end

--重启游戏
function Game:restart()
    --(1)清理已经注册到NetCenter中的组件
    NetCenter:sharedNetCenter():removeAllNetFilters()
    --(2)清理所有已经加载的模块
    self:unrequireAllUserModules()
    --(3)清理数据库连接缓存
    SQLite:clearConnectionCache()
    --(4)重新执行本文件
    local path = CCFileUtils:sharedFileUtils():fullPathForFilename("script/main.lua")
    dofile(path)
end

--系统初始化
function Game:init()
    self.systemModuleList={}    --系统模块列表，在游戏重启清除所有加载的模块时会用到
    for k,v in pairs(package.loaded) do
        self.systemModuleList[k]=v
    end
end

--删除所有游戏层加载的模块
function Game:unrequireAllUserModules()
    
    for k,v in pairs(package.loaded) do
        if not self.systemModuleList[k] then
            package.loaded[k] = nil
        end
    end
    
end

--加载公共模块
function Game:requireCommonModule()
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

function __G__TRACKBACK__(msg)
    print("----------------------------------------")
    print("LUA ERROR: " .. tostring(msg) .. "\n")
    print(debug.traceback())
    
    print("----------------------------------------")
end

xpcall(function() Game:start() end,__G__TRACKBACK__)
