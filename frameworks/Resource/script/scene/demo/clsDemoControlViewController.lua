
--[[
 description:demo control view controller
 author:qiuwenbo
 date:2014/05/03
 --]]

class("clsDemoControlViewController",clsUIViewController)

clsDemoControlViewController.layer=nil

clsDemoControlViewController.contentLayer = nil
clsDemoControlViewController.contentId = nil

function clsDemoControlViewController:load()
    self.contentId = 1
    self:showView()
end

function clsDemoControlViewController:showView( )
    print("clsDemoControlViewController:showView")
	local winSize = cc.Director:getInstance():getWinSize()
    self.layer = cc.Layer:create()
    self:setRootLayer(self.layer)
	
	local background = cc.Sprite:create("images/control/background.png")
    background:setPosition(cc.p(winSize.width / 2, winSize.height / 2));
    self.layer:addChild(background)

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

    self.layer:addChild(pMenu, 2)

    self:showContent()
end

function clsDemoControlViewController:showPreviousContent()
    if self.contentId <= 1 then 
        self.contentId = 6
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
    elseif self.contentId == 3 then
        self:showControlSwitch()
    elseif self.contentId == 4 then 
        self:showControlSlider()
    elseif self.contentId == 5 then 
        self:showControlPotentiometer()
    elseif self.contentId == 6 then 
        self:showControlStepper()
    end 
end

function clsDemoControlViewController:showNextContent()
    if self.contentId >= 6 then 
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
    self.layer:addChild(self.contentLayer, 1)

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
    self.layer:addChild(self.contentLayer, 1)

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

------------------------------------------------------------------------------

function clsDemoControlViewController:showControlSwitch( )
    if self.contentLayer then 
        self.contentLayer:removeFromParent()
    end 

    self.contentLayer = cc.Layer:create()
    self.layer:addChild(self.contentLayer, 1)

    local winSize = cc.Director:getInstance():getWinSize()
        
    --Add the black background for the text
    local pBackground = cc.Scale9Sprite:create("extensions/buttonBackground.png")
    pBackground:setContentSize(cc.size(80, 50))
    pBackground:setPosition(cc.p(winSize.width/2 - pBackground:getContentSize().width / 2.0, winSize.height/2))
    self.contentLayer:addChild(pBackground)


    local pDisplayValueLabel = cc.Label:createWithTTF("#color", "font/HANYI.ttf", 30)
    pDisplayValueLabel:setPosition(pBackground:getPosition())
    self.contentLayer:addChild(pDisplayValueLabel)
    
    --Create the switch
    local function valueChanged(pSender)
        if nil == pDisplayValueLabel or nil == pSender then
            return
        end
        
        local pControl = pSender
        if pControl:isOn() then
            pDisplayValueLabel:setString("On")
        else
            pDisplayValueLabel:setString("Off")
        end
    end

    local pSwitchControl = cc.ControlSwitch:create(
            cc.Sprite:create("extensions/switch-mask.png"),
            cc.Sprite:create("extensions/switch-on.png"),
            cc.Sprite:create("extensions/switch-off.png"),
            cc.Sprite:create("extensions/switch-thumb.png"),
            cc.Label:createWithTTF("On", "font/HANYI.ttf", 16),
            cc.Label:createWithTTF("Off", "font/HANYI.ttf", 16)
        )
    pSwitchControl:setPosition(cc.p (winSize.width/2 + 10 + pSwitchControl:getContentSize().width / 2, winSize.height/2))
    self.contentLayer:addChild(pSwitchControl)
    pSwitchControl:registerControlEventHandler(valueChanged, cc.CONTROL_EVENTTYPE_VALUE_CHANGED)
    
    --Update the value label
    valueChanged(pSwitchControl)
end

------------------------------------------------------------------------------

function clsDemoControlViewController:showControlSlider( )
    if self.contentLayer then 
        self.contentLayer:removeFromParent()
    end 

    self.contentLayer = cc.Layer:create()
    self.layer:addChild(self.contentLayer, 1)

    local winSize = cc.Director:getInstance():getWinSize()

    local pDisplayValueLabel = cc.Label:createWithTTF("Move the slider thumb!\nThe lower slider is restricted." ,"font/HANYI.ttf", 32)
    pDisplayValueLabel:setPosition(cc.p(winSize.width / 2, winSize.height * 3 / 4))
    self.contentLayer:addChild(pDisplayValueLabel)
    
    local function valueChanged(pSender)
        if nil == pSender or nil == pDisplayValueLabel then
            return
        end         
        local pControl = pSender
        local strFmt = nil
        if pControl:getTag() == 1 then
            strFmt = string.format("Upper slider value = %.02f",pControl:getValue())
        elseif pControl:getTag() == 2 then
            strFmt = string.format("Lower slider value = %.02f",pControl:getValue())
        end
        
        if nil ~= strFmt then
            pDisplayValueLabel:setString(strFmt)
        end         
    end
    --Add the slider
    local pSlider = cc.ControlSlider:create("extensions/sliderTrack.png","extensions/sliderProgress.png" ,"extensions/sliderThumb.png")
    pSlider:setAnchorPoint(cc.p(0.5, 1.0))
    pSlider:setMinimumValue(0.0) 
    pSlider:setMaximumValue(5.0) 
    pSlider:setPosition(cc.p(winSize.width / 2.0, winSize.height / 2.0 + 16))
    pSlider:setTag(1)
    
    --When the value of the slider will change, the given selector will be call
    pSlider:registerControlEventHandler(valueChanged, cc.CONTROL_EVENTTYPE_VALUE_CHANGED)
    
    local pRestrictSlider = cc.ControlSlider:create("extensions/sliderTrack.png","extensions/sliderProgress.png" ,"extensions/sliderThumb.png")
    pRestrictSlider:setAnchorPoint(cc.p(0.5, 1.0))
    pRestrictSlider:setMinimumValue(0.0) 
    pRestrictSlider:setMaximumValue(5.0) 
    pRestrictSlider:setMaximumAllowedValue(4.0)
    pRestrictSlider:setMinimumAllowedValue(1.5)
    pRestrictSlider:setValue(3.0)
    pRestrictSlider:setPosition(cc.p(winSize.width / 2.0, winSize.height / 2.0 - 24))
    pRestrictSlider:setTag(2)       
    --same with restricted
    pRestrictSlider:registerControlEventHandler(valueChanged, cc.CONTROL_EVENTTYPE_VALUE_CHANGED)
    self.contentLayer:addChild(pSlider)    
    self.contentLayer:addChild(pRestrictSlider)
end 

------------------------------------------------------------------------------

function clsDemoControlViewController:showControlPotentiometer( )
    if self.contentLayer then 
        self.contentLayer:removeFromParent()
    end 

    self.contentLayer = cc.Layer:create()
    self.layer:addChild(self.contentLayer, 1)

    local winSize = cc.Director:getInstance():getWinSize()

    -- Add the black background for the text
    local pBackground  = cc.Scale9Sprite:create("extensions/buttonBackground.png")
    pBackground:setContentSize(cc.size(80, 50))
    pBackground:setPosition(cc.p(winSize.width/2 - pBackground:getContentSize().width / 2.0, winSize.height/2))
    self.contentLayer:addChild(pBackground)
        
    local pDisplayValueLabel = cc.Label:createWithTTF("", "font/HANYI.ttf", 30)
    pDisplayValueLabel:setPosition(pBackground:getPosition())
    self.contentLayer:addChild(pDisplayValueLabel)
    
    -- Add the slider
    local function valueChanged(pSender)
        if nil == pSender then
            return
        end
        
        local pControl = pSender
        local strFmt = string.format("%0.2f",pControl:getValue())
        pDisplayValueLabel:setString(strFmt )
    end
    local pPotentiometer = cc.ControlPotentiometer:create("extensions/potentiometerTrack.png","extensions/potentiometerProgress.png"
                                                                           ,"extensions/potentiometerButton.png")
    pPotentiometer:setPosition(cc.p (winSize.width/2 + 10 + pPotentiometer:getContentSize().width / 2, winSize.height/2))

    -- When the value of the slider will change, the given selector will be call
    pPotentiometer:registerControlEventHandler(valueChanged, cc.CONTROL_EVENTTYPE_VALUE_CHANGED)
    
    self.contentLayer:addChild(pPotentiometer)
        
    -- Update the value label
    valueChanged(pPotentiometer)
end

function clsDemoControlViewController:showControlStepper( )
    if self.contentLayer then 
        self.contentLayer:removeFromParent()
    end 

    self.contentLayer = cc.Layer:create()
    self.layer:addChild(self.contentLayer, 1)

    local winSize = cc.Director:getInstance():getWinSize()
        
    -- Add the black background for the text
    local background  = cc.Scale9Sprite:create("extensions/buttonBackground.png")
    background:setContentSize(cc.size(100, 50))
    background:setPosition(cc.p(winSize.width/2 - background:getContentSize().width / 2.0, winSize.height/2))
    self.contentLayer:addChild(background)
    
    local pDisplayValueLabel =  cc.Label:createWithTTF("0", "font/HANYI.ttf", 30)
    pDisplayValueLabel:setPosition(background:getPosition())
    self.contentLayer:addChild(pDisplayValueLabel)
    
    
    local minusSprite = cc.Sprite:create("extensions/stepper-minus.png")
    local plusSprite  = cc.Sprite:create("extensions/stepper-plus.png")

    local function valueChanged(pSender)
        if nil == pDisplayValueLabel or nil == pSender then
            return
        end
        
        local pControl = pSender
        local strFmt   = string.format("%0.02f",pControl:getValue() )
        pDisplayValueLabel:setString(strFmt )
    end
    local stepper   = cc.ControlStepper:create(minusSprite, plusSprite)
    stepper:setPosition(cc.p (winSize.width/2 + 10 + stepper:getContentSize().width / 2, winSize.height/2))
    stepper:registerControlEventHandler(valueChanged, cc.CONTROL_EVENTTYPE_VALUE_CHANGED)
    self.contentLayer:addChild(stepper)
    
    -- Update the value label
    valueChanged(stepper)
end