--[[
 description:框架扩展
 author:wp_g4
 date:2013/05/13
 --]]

--clsNode
class("clsNode",{create = function() return cc.Node:create() end})

--clsLayer
class("clsLayer",{create = function() return cc.Layer:create() end})

--clsSprite
class("clsSprite",{ create = function(...) return cc.Sprite:create(...) end,
                    createWithTexture = function(...) return cc.Sprite:createWithTexture(...) end,
                    createWithSpriteFrame = function(...) return cc.Sprite:createWithSpriteFrame(...) end,
                    createWithSpriteFrameName = function(...) return cc.Sprite:createWithSpriteFrameName(...) end    })

--clsNetFilter
class("clsNetFilter",{create = function() return NetFilter:create() end})

--clsNetHandler
class("clsNetHandler",{create = function() return NetHandler:create() end})

--系统tag分配.所有框架级控件，如果要在scene上添加layer，使用的tag必须在此处申请
TAG_SYSTEM_MIN = 100000000
TAG_SYSTEM_INDICATOR = TAG_SYSTEM_MIN + 1           --clsIndicator
TAG_SYSTEM_TOAST = TAG_SYSTEM_MIN + 2               --clsToast
TAG_SYSTEM_DIALOG = TAG_SYSTEM_MIN + 3              --clsDialog

--系统zOrder分配，如果要在scene上添加layer，使用的zOrder必须在此处申请
ZOEDER_SYSTEM_INDICATOR = 100000000                 --clsIndicator
ZOEDER_SYSTEM_TOAST = 100000000                     --clsToast
ZOEDER_SYSTEM_Dialog = 100000000                    --clsDialog
