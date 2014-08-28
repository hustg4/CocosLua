--[[
 description:网络消息
 author:wp_g4
 date:2013/03/27
 --]]

MessageSender={}

--登录
function MessageSender:login(username,password)
    local msg=JSONObject:create()
    msg:putString("c", "welcome")
    msg:putString("a", "login")
    msg:putString("name", username)
    msg:putString("pwd", password)
    local request=NetRequest:create(NetConfig.ProtocolId.Login, msg)
    NetCenter:sharedNetCenter():sendMessage(request)
end

--获取玩家详细数据
function MessageSender:getDtl()
    local msg=JSONObject:create()
    msg:putString("c", "player")
    msg:putString("a", "getDtl")
    local request=NetRequest:create(NetConfig.ProtocolId.GetDtl, msg)
    NetCenter:sharedNetCenter():sendMessage(request)
end

