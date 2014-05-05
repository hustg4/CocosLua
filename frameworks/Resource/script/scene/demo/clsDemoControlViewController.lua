
--[[
 description:demo control view controller
 author:qiuwenbo
 date:2014/05/03
 --]]

class("clsDemoControlViewController",clsViewController)

clsDemoControlViewController.contentLayer = nil
clsDemoControlViewController.contentId = nil

function clsDemoControlViewController:load()
    self.contentId = 1
    self:showView()
end

function clsDemoControlViewController:showView( )
	local winSize = cc.Director:getInstance():getWinSize()
	
	local background = cc.Sprite:create("images/control/background.png")
    background:setPosition(cc.p(winSize.width / 2, winSize.height / 2));
    self:getScene():addChild(background)

    local pMenu = cc.Menu:create()
    pMenu:setPosition(cc.p(0, 0))

    local previousItem = cc.MenuItemImage:create("images/control/b1.png", "images/control/b2.png")
    previousItem:registerScriptTapHandler(MakeScriptHandler(self, self.showPreviousContent))
    pMenu:addChild(previousItem)

    local restartItem = cc.MenuItemImage:create("images/control/r1.png", "images/control/r2.png")
    restartItem:registerScriptTapHandler(MakeScriptHandler(self, self.showContent))
    pMenu:addChild(restartItem)

    local nextItem = cc.MenuItemImage:create("images/control/f1.png", "images/control/f2.png")
    nextItem:registerScriptTapHandler(MakeScriptHandler(self, self.showNextContent))
    pMenu:addChild(nextItem)

    previousItem:setPosition(cc.p(winSize.width / 2 - restartItem:getContentSize().width * 2, restartItem:getContentSize().height / 2))
    restartItem:setPosition(cc.p(winSize.width / 2, restartItem:getContentSize().height / 2))
    nextItem:setPosition(cc.p(winSize.width / 2 + restartItem:getContentSize().width * 2, restartItem:getContentSize().height / 2))

    self:getScene():addChild(pMenu, 2)

    self:showContent()
end

function clsDemoControlViewController:showPreviousContent()
    if self.contentId <= 1 then 
        self.contentId = 2
    else 
        self.contentId = self.contentId - 1
    end

    self:showContent() 
end 

function clsDemoControlViewController:showContent()
    if self.contentId == 1 then 
        self:showControlButton()
    elseif self.contentId == 2 then 
        self:showColourPicker()
    end 
end

function clsDemoControlViewController:showNextContent()
    if self.contentId >= 2 then 
        self.contentId = 1
    else 
        self.contentId = self.contentId + 1
    end

    self:showContent() 
end 

------------------------------------------------------------------------------
function clsDemoControlViewController:showControlButton(  )
    if self.contentLayer then 
        self.contentLayer:removeFromParent()
    end 

    self.contentLayer = cc.Layer:create()
    self:getScene():addChild(self.contentLayer, 1)

    local winSize = cc.Director:getInstance():getWinSize()

    local backgroundButton = cc.Scale9Sprite:create("images/control/button.png")
    local backgroundHighlightedButton = cc.Scale9Sprite:create("images/control/buttonHighlighted.png")
    
    local titleButton = cc.Label:createWithTTF("点我", "font/HANYI.ttf", 30)
    titleButton:setColor(cc.c3b(159, 168, 176))
    
    
    local controlButton = cc.ControlButton:create(titleButton, backgroundButton)
    controlButton:setBackgroundSpriteForState(backgroundHighlightedButton, cc.CONTROL_STATE_HIGH_LIGHTED)
    controlButton:setTitleColorForState(cc.c3b(255, 255, 255), cc.CONTROL_STATE_HIGH_LIGHTED)

    controlButton:setPosition(cc.p(winSize.width / 2, winSize.height / 2))

    controlButton:registerControlEventHandler(self.touchDownAction, cc.CONTROL_EVENTTYPE_TOUCH_DOWN)
    controlButton:registerControlEventHandler(self.touchDragInsideAction, cc.CONTROL_EVENTTYPE_DRAG_INSIDE)
    controlButton:registerControlEventHandler(self.touchDragOutsideAction, cc.CONTROL_EVENTTYPE_DRAG_OUTSIDE)
    controlButton:registerControlEventHandler(self.touchDragEnterAction, cc.CONTROL_EVENTTYPE_DRAG_ENTER)
    controlButton:registerControlEventHandler(self.touchDragExitAction, cc.CONTROL_EVENTTYPE_DRAG_EXIT)
    controlButton:registerControlEventHandler(self.touchUpInsideAction, cc.CONTROL_EVENTTYPE_TOUCH_UP_INSIDE)
    controlButton:registerControlEventHandler(self.touchUpOutsideAction, cc.CONTROL_EVENTTYPE_TOUCH_UP_OUTSIDE)
    controlButton:registerControlEventHandler(self.touchCancelAction, cc.CONTROL_EVENTTYPE_TOUCH_CANCEL)


    self.contentLayer:addChild(controlButton)
end

function clsDemoControlViewController:touchDownAction(  )
    print("touchDownAction")
end

function clsDemoControlViewController:touchDragInsideAction(  )
    print("touchDragInsideAction")
end

function clsDemoControlViewController:touchDragOutsideAction(  )
    print("touchDragOutsideAction")
end

function clsDemoControlViewController:touchDragEnterAction(  )
    print("touchDragEnterAction")
end

function clsDemoControlViewController:touchDragExitAction(  )
    print("touchDragExitAction")
end

function clsDemoControlViewController:touchUpInsideAction(  )
    print("touchUpInsideAction")
end

function clsDemoControlViewController:touchUpOutsideAction(  )
    print("touchUpOutsideAction")
end

function clsDemoControlViewController:touchCancelAction(  )
    print("touchCancelAction")
end
------------------------------------------------------------------------------

function clsDemoControlViewController:showColourPicker( )
    if self.contentLayer then 
        self.contentLayer:removeFromParent()
    end 

    self.contentLayer = cc.Layer:create()
    self:getScene():addChild(self.contentLayer, 1)

    local winSize = cc.Director:getInstance():getWinSize()

    local pColorLabel = nil

    local function colourValueChanged(pSender)
        if nil == pSender or nil == pColorLabel then
            return
        end
         
        local pPicker = pSender
        local strFmt  = string.format("#%02X%02X%02X",pPicker:getColor().r, pPicker:getColor().g, pPicker:getColor().b)
        pColorLabel:setString(strFmt)           
    end

    local pColourPicker = cc.ControlColourPicker:create()
    pColourPicker:setColor(cc.c3b(37, 46, 252))
    pColourPicker:setPosition(cc.p (winSize.width/2 - pColourPicker:getContentSize().width / 2, winSize.height/2))
    pColourPicker:registerControlEventHandler(colourValueChanged, cc.CONTROL_EVENTTYPE_VALUE_CHANGED)
    self.contentLayer:addChild(pColourPicker)     
              
    --Add the black background for the text
    local pBackground = cc.Scale9Sprite:create("images/control/buttonBackground.png")
    pBackground:setContentSize(cc.size(150, 50))
    pBackground:setPosition(cc.p(winSize.width/2 + pBackground:getContentSize().width / 2.0, winSize.height/2))
    self.contentLayer:addChild(pBackground)
     
    pColorLabel = cc.Label:createWithTTF("#color", "font/HANYI.ttf", 30)
    pColorLabel:setPosition(pBackground:getPosition())
    self.contentLayer:addChild(pColorLabel)
     
    --Update the color text
    colourValueChanged(pColourPicker)
     
end