--[[
 description:系统配置
 author:wp_g4
 date:2013/06/13
 --]]

require ("framework/SystemExtend")
require ("framework/Notifier")
require ("framework/class")
require ("framework/luaclass")
require ("framework/clsModel")
require ("framework/FrameworkExtend")
require ("framework/clsViewController")
require ("framework/functions")

MODEL_LOCK_DEBUG = true     --model 加锁开关

NULL = nil
if MODEL_LOCK_DEBUG then
    NULL = "null"
end
