--[[
 description:脚本入口点
 author:wp_g4
 date:2013/03/13
 --]]
 
require ("framework/cocos2dx/Cocos2d")
require ("framework/cocos2dx/Cocos2dConstants")
require ("framework/cocos2dx/Opengl")
require ("framework/cocos2dx/OpenglConstants")

require ("framework/CocosLua")

require ("scene/test/clsTestScene")

--游戏启动
function Game:onStart()
    print("Game:onStart")
    --启动场景
    cl.runScene(clsTestScene)
end

--游戏停止
function Game:onStop()
    print("Game:onStop")
end
