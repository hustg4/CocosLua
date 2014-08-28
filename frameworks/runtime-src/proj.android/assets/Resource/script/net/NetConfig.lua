--[[
 description:网络配置
 author:wp_g4
 date:2013/03/27
 --]]

NetConfig={}

NetConfig.ResourceServerRootUrl = "http://localhost:8080/framework-resource"    --资源服务器资源根地址
  

--==========================    网络服务      ==========================

NetConfig.Service={}                    --应该与C++中的id保持一致,具体就由service开发者填写

NetConfig.Service.Http="http"           --HttpService
NetConfig.Service.Socket="socket"       --SocketService


--==========================    协议ID      ==========================

NetConfig.ProtocolId={}

NetConfig.ProtocolId.Login="login-login"              --登录
NetConfig.ProtocolId.GetDtl="player-getDtl"           --获取玩家详细数据


--==========================    过滤器配置   ==========================

require ("net/filter/clsLogFilter")

NetConfig.Filters = {
    clsLogFilter
}


--==========================    协议配置    ==========================

require ("net/handler/login/clsLoginHandler")
require ("net/handler/player/clsGetDtlHandler")

NetConfig.Protocols = {

    { protocolId = NetConfig.ProtocolId.Login,handlerClass = clsLoginHandler,serviceId = NetConfig.Service.Http},
    
    { protocolId = NetConfig.ProtocolId.GetDtl,handlerClass = clsGetDtlHandler,serviceId = NetConfig.Service.Http}
}                  
