--[[
 description:日志过滤器
 author:wp_g4
 date:2013/06/26
 --]]

class("clsLogFilter",clsNetFilter)

function clsLogFilter:filterSuccessfulMessage(netResponse)
    print("clsLogFilter:filterSuccessfulMessage")
    return netResponse
end

function clsLogFilter:filterFailedMessage(netResponse)
    print("clsLogFilter:filterFailedMessage")
    return netResponse
end