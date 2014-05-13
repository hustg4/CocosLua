--[[
	description:用于多个demo的切换
	author:qiuwenbo
	date:05/12/2014
]]

class("clsDemoPager", clsNode)

clsDemoPager.__create = clsDemoPager.create

clsDemoPager.delegate = nil
clsDemoPager.pNameLabel = nil

function clsDemoPager:create()
	local demoPager = clsDemoPager:__create()
    demoPager:init()

    return demoPager
end

function clsDemoPager:init()
	local winSize = cc.Director:getInstance():getWinSize()

	local pBackground = cc.Sprite:create("images/control/background.png")
    pBackground:setPosition(cc.p(winSize.width / 2, winSize.height / 2));
    self:addChild(pBackground)

    local pRibbon = cc.Scale9Sprite:create("extensions/ribbon.png", cc.rect(1, 1, 48, 55))
    pRibbon:setContentSize(cc.size(winSize.width, 57))
    pRibbon:setPosition(cc.p(winSize.width/2, winSize.height - pRibbon:getContentSize().height / 2.0))
    self:addChild(pRibbon, 2)

	local pNameLabel = cc.Label:createWithTTF("", "font/HANYI.ttf", 26)
    pNameLabel:setPosition(cc.p(winSize.width / 2, winSize.height - pRibbon:getContentSize().height / 2.0 + 14))
    self:addChild(pNameLabel, 3)

    self.pNameLabel = pNameLabel

	local pMenu = cc.Menu:create()
    pMenu:setPosition(cc.p(0, 0))

    local previousItem = cc.MenuItemImage:create("images/control/b1.png", "images/control/b2.png")
    previousItem:registerScriptTapHandler(cl.makeScriptHandler(self, self.showPrevious))
    pMenu:addChild(previousItem)

    local restartItem = cc.MenuItemImage:create("images/control/r1.png", "images/control/r2.png")
    restartItem:registerScriptTapHandler(cl.makeScriptHandler(self, self.restart))
    pMenu:addChild(restartItem)

    local nextItem = cc.MenuItemImage:create("images/control/f1.png", "images/control/f2.png")
    nextItem:registerScriptTapHandler(cl.makeScriptHandler(self, self.showNext))
    pMenu:addChild(nextItem)

    previousItem:setPosition(cc.p(winSize.width / 2 - restartItem:getContentSize().width * 2, restartItem:getContentSize().height / 2))
    restartItem:setPosition(cc.p(winSize.width / 2, restartItem:getContentSize().height / 2))
    nextItem:setPosition(cc.p(winSize.width / 2 + restartItem:getContentSize().width * 2, restartItem:getContentSize().height / 2))

    self:addChild(pMenu, 4)
end

function clsDemoPager:showPrevious()
	self:showContent(-1)
end 

function clsDemoPager:restart()
    self:showContent(0)
end

function clsDemoPager:showNext()
    self:showContent(1)
end

function clsDemoPager:showContent( offset )
	if self.contentLayer then 
		self.contentLayer:removeFromParent()
		self.contentLayer = nil
	end 

	if self.delegate and self.delegate.showContent then 
		self.delegate:showContent(offset)
	end 
end

function clsDemoPager:addContent( contentLayer, contentName )
	self.contentLayer = contentLayer
	self:addChild(contentLayer, 1)

	self.pNameLabel:setString(contentName)
end