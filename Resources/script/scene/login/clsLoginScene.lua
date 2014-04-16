
--[[
 description:登录场景
 author:wp_g4
 date:2013/03/28
 --]]


require ("scene/login/clsLoginViewController")
require ("scene/login/clsRegisterViewController")

class("clsLoginScene",clsGameScene)

function clsLoginScene:onEnter()
    local loginViewController=clsLoginViewController:create()
    self:loadViewController(loginViewController)
    local registerViewController=clsRegisterViewController:create()
    self:loadViewController(registerViewController)

    --[[
    local sqlite = SQLiteLua:openSQLite("dictionary.sqlite")
    local playerList = sqlite:selectTableAsLua("player")
    print(#playerList)
    local player = playerList[1]
    print(player,type(player.id),type(player.name),type(player.age),type(player.isTall))
    
    for k,v in pairs(player) do
        print(k,v,type(v))
    end
    --]]
    
end

function clsLoginScene:onExit()
end

