--[[
 description:系统配置
 author:wp_g4
 date:2013/06/13
 --]]

Config = {}

Config.debug = true         --debug开关

NULL = nil
if Config.debug then        --定义一个全局常量NULL,在model类字段定义时，应该使用NULL代替nil 
    NULL = "null"
end
