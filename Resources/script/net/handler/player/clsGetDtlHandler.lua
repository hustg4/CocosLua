--[[
 description:玩家详细数据
 author:wp_g4
 date:2013/03/27
 --]]


class("clsGetDtlHandler",clsNetHandler)

function clsGetDtlHandler:handleSuccessfulMessage(netResponse)
  print("clsGetDtlHandler:handleSuccessfulMessage")
end

function clsGetDtlHandler:handleFailedMessage(netResponse)
end