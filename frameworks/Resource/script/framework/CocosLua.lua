--[[
 description:系统配置
 author:wp_g4
 date:2013/06/13
 --]]

MODEL_LOCK_DEBUG = true     --model 加锁开关

NULL = nil
if MODEL_LOCK_DEBUG then
    NULL = "null"
end
