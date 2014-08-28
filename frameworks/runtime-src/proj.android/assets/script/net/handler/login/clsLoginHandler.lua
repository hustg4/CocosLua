--[[
 description:登录
 author:wp_g4
 date:2013/03/27
 --]]


class("clsLoginHandler",clsNetHandler)

function clsLoginHandler:handleSuccessfulMessage(netResponse)
    print("clsLoginHandler:handleSuccessfulMessage")
    local msg = ResponseBodyToLua(netResponse)
    if msg.success == 1 then
        Notifier:notify(NotifyEvent.Net.LoginAction,true)
        else
        Notifier:notify(NotifyEvent.Net.LoginAction,false)
    end
end

function clsLoginHandler:handleFailedMessage(netResponse)
end