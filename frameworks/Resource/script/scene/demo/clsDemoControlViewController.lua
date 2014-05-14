
--[[
 description:demo control view controller
 author:qiuwenbo
 date:2014/05/03
 --]]
require ("scene/demo/clsDemoPager")

class("clsDemoControlViewController",clsUIViewController)

clsDemoControlViewController.layer=nil

clsDemoControlViewController.demoPager = nil
clsDemoControlViewController.contentId = nil

clsDemoControlViewController.kDemoCount = 6

function clsDemoControlViewController:load()
    self:showView()
end

function clsDemoControlViewController:showView( )
	local winSize = cc.Director:getInstance():getWinSize()
    self.layer = cc.Layer:create()
    self:setRootLayer(self.layer)

    self.demoPager = clsDemoPager:create()
    self.demoPager.delegate = self
    self.layer:addChild(self.demoPager)
	
    self:showContent(0)
end

function clsDemoControlViewController:showContent( offset )
    if not self.contentId then 
        self.contentId = 1
    end 

    self.contentId = self.contentId + offset

    if self.contentId < 1 then 
        self.contentId = self.kDemoCount
    elseif self.contentId > self.kDemoCount then 
        self.contentId = 1
    end 

    local contentLayer = nil
    local contentName = nil

    if self.contentId == 1 then 
        contentLayer = self:showControlButton()
        contentName = "ControlTest"
    elseif self.contentId == 2 then 
        contentLayer = self:showColourPicker()
        contentName = "ColourPickerTest"
    elseif self.contentId == 3 then
        contentLayer = self:showControlSwitch()
        contentName = "ControlSwitchTest"
    elseif self.contentId == 4 then 
        contentLayer = self:showControlSlider()
        contentName = "ControlSliderTest"
    elseif self.contentId == 5 then 
        contentLayer = self:showControlPotentiometer()
        contentName = "PotentiometerTest"
    elseif self.contentId == 6 then 
        contentLayer = self:showControlStepper()
        contentName = "ControlStepperTest"
    end

    if contentLayer and contentName then 
        self.demoPager:addContent(contentLayer, contentName)
    end 
end

------------------------------------------------------------------------------
function clsDemoControlViewController:showControlButton(  )

    local contentLayer = cc.Layer:create()

    local winSize = cc.Director:getInstance():getWinSize()

    --Add a label in which the button events will be displayed
    local pDisplayValueLabel = nil
    pDisplayValueLabel = cc.Label:create("No Event", "font/HANYI.ttf", 32)
    pDisplayValueLabel:setAnchorPoint(cc.p(0.5, -1))
    pDisplayValueLabel:setPosition(cc.p(winSize.width / 2.0, winSize.height / 2.0))
    contentLayer:addChild(pDisplayValueLabel, 1)
    
    --Add the button
    local pBackgroundButton            = cc.Scale9Sprite:create("extensions/button.png")
    local pBackgroundHighlightedButton = cc.Scale9Sprite:create("extensions/buttonHighlighted.png")
    
    local pTitleButtonLabel = cc.Label:create("Touch Me!", "font/HANYI.ttf", 30)
    pTitleButtonLabel:setColor(cc.c3b(159, 168, 176))
    
    local pControlButton = cc.ControlButton:create(pTitleButtonLabel, pBackgroundButton)
    local function touchDownAction()
        if nil == pDisplayValueLabel then
            return
        end         
        pDisplayValueLabel:setString("Touch Down" )
    end
    
    local function touchDragInsideAction()
        if nil == pDisplayValueLabel then
            return
        end 
        pDisplayValueLabel:setString("Drag Inside")
    end
    
    local function touchDragOutsideAction()
        if nil == pDisplayValueLabel then
            return
        end 
        pDisplayValueLabel:setString("Drag Outside")
    end
    
    local function touchDragEnterAction()
        if nil == pDisplayValueLabel then
            return
        end 
        pDisplayValueLabel:setString("Drag Enter")
    end
    
    local function touchDragExitAction()
        if nil == pDisplayValueLabel then
            return
        end 
        pDisplayValueLabel:setString("Drag Exit")
    end
    
    local function touchUpInsideAction()
        if nil == pDisplayValueLabel then
            return
        end 
        pDisplayValueLabel:setString("Touch Up Inside.")
    end
    
    local function touchUpOutsideAction()
        if nil == pDisplayValueLabel then
            return
        end 
        pDisplayValueLabel:setString("Touch Up Outside.")
    end
    
    local function touchCancelAction()
        if nil == pDisplayValueLabel then
            return
        end 
        pDisplayValueLabel:setString("Touch Cancel")
    end
    
    pControlButton:setBackgroundSpriteForState(pBackgroundHighlightedButton, cc.CONTROL_STATE_HIGH_LIGHTED )
    pControlButton:setTitleColorForState(cc.c3b(255, 255, 255), cc.CONTROL_STATE_HIGH_LIGHTED )
    pControlButton:setAnchorPoint(cc.p(0.5, 1))
    pControlButton:setPosition(cc.p(winSize.width / 2.0, winSize.height / 2.0))
    pControlButton:registerControlEventHandler(touchDownAction,cc.CONTROL_EVENTTYPE_TOUCH_DOWN )
    pControlButton:registerControlEventHandler(touchDragInsideAction,cc.CONTROL_EVENTTYPE_DRAG_INSIDE)
    pControlButton:registerControlEventHandler(touchDragOutsideAction,cc.CONTROL_EVENTTYPE_DRAG_OUTSIDE)
    pControlButton:registerControlEventHandler(touchDragEnterAction,cc.CONTROL_EVENTTYPE_DRAG_ENTER)
    pControlButton:registerControlEventHandler(touchDragExitAction,cc.CONTROL_EVENTTYPE_DRAG_EXIT)
    pControlButton:registerControlEventHandler(touchUpInsideAction,cc.CONTROL_EVENTTYPE_TOUCH_UP_INSIDE)
    pControlButton:registerControlEventHandler(touchUpOutsideAction,cc.CONTROL_EVENTTYPE_TOUCH_UP_OUTSIDE)
    pControlButton:registerControlEventHandler(touchCancelAction,cc.CONTROL_EVENTTYPE_TOUCH_CANCEL)
    contentLayer:addChild(pControlButton, 1)
    
    --Add the black background
    local pBackgroundButton = cc.Scale9Sprite:create("extensions/buttonBackground.png")
    pBackgroundButton:setContentSize(cc.size(300, 170))
    pBackgroundButton:setPosition(cc.p(winSize.width / 2.0, winSize.height / 2.0))
    contentLayer:addChild(pBackgroundButton)

    return contentLayer
end

------------------------------------------------------------------------------

function clsDemoControlViewController:showColourPicker( )

    local contentLayer = cc.Layer:create()

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
    contentLayer:addChild(pColourPicker)     
              
    --Add the black background for the text
    local pBackground = cc.Scale9Sprite:create("images/control/buttonBackground.png")
    pBackground:setContentSize(cc.size(150, 50))
    pBackground:setPosition(cc.p(winSize.width/2 + pBackground:getContentSize().width / 2.0, winSize.height/2))
    contentLayer:addChild(pBackground)
     
    pColorLabel = cc.Label:createWithTTF("#color", "font/HANYI.ttf", 30)
    pColorLabel:setPosition(pBackground:getPosition())
    contentLayer:addChild(pColorLabel)
     
    --Update the color text
    colourValueChanged(pColourPicker)
     
    return contentLayer
end

------------------------------------------------------------------------------

function clsDemoControlViewController:showControlSwitch( )

    local contentLayer = cc.Layer:create()

    local winSize = cc.Director:getInstance():getWinSize()
        
    --Add the black background for the text
    local pBackground = cc.Scale9Sprite:create("extensions/buttonBackground.png")
    pBackground:setContentSize(cc.size(80, 50))
    pBackground:setPosition(cc.p(winSize.width/2 - pBackground:getContentSize().width / 2.0, winSize.height/2))
    contentLayer:addChild(pBackground)


    local pDisplayValueLabel = cc.Label:createWithTTF("#color", "font/HANYI.ttf", 30)
    pDisplayValueLabel:setPosition(pBackground:getPosition())
    contentLayer:addChild(pDisplayValueLabel)
    
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
    contentLayer:addChild(pSwitchControl)
    pSwitchControl:registerControlEventHandler(valueChanged, cc.CONTROL_EVENTTYPE_VALUE_CHANGED)
    
    --Update the value label
    valueChanged(pSwitchControl)

    return contentLayer
end

------------------------------------------------------------------------------

function clsDemoControlViewController:showControlSlider( )

    local contentLayer = cc.Layer:create()

    local winSize = cc.Director:getInstance():getWinSize()

    local pDisplayValueLabel = cc.Label:createWithTTF("Move the slider thumb!\nThe lower slider is restricted." ,"font/HANYI.ttf", 32)
    pDisplayValueLabel:setPosition(cc.p(winSize.width / 2, winSize.height * 3 / 4))
    contentLayer:addChild(pDisplayValueLabel)
    
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
    contentLayer:addChild(pSlider)    
    contentLayer:addChild(pRestrictSlider)

    return contentLayer
end 

------------------------------------------------------------------------------

function clsDemoControlViewController:showControlPotentiometer( )

    local contentLayer = cc.Layer:create()

    local winSize = cc.Director:getInstance():getWinSize()

    -- Add the black background for the text
    local pBackground  = cc.Scale9Sprite:create("extensions/buttonBackground.png")
    pBackground:setContentSize(cc.size(80, 50))
    pBackground:setPosition(cc.p(winSize.width/2 - pBackground:getContentSize().width / 2.0, winSize.height/2))
    contentLayer:addChild(pBackground)
        
    local pDisplayValueLabel = cc.Label:createWithTTF("", "font/HANYI.ttf", 30)
    pDisplayValueLabel:setPosition(pBackground:getPosition())
    contentLayer:addChild(pDisplayValueLabel)
    
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
    
    contentLayer:addChild(pPotentiometer)
        
    -- Update the value label
    valueChanged(pPotentiometer)

    return contentLayer
end

function clsDemoControlViewController:showControlStepper( )

    local contentLayer = cc.Layer:create()

    local winSize = cc.Director:getInstance():getWinSize()
        
    -- Add the black background for the text
    local background  = cc.Scale9Sprite:create("extensions/buttonBackground.png")
    background:setContentSize(cc.size(100, 50))
    background:setPosition(cc.p(winSize.width/2 - background:getContentSize().width / 2.0, winSize.height/2))
    contentLayer:addChild(background)
    
    local pDisplayValueLabel =  cc.Label:createWithTTF("0", "font/HANYI.ttf", 30)
    pDisplayValueLabel:setPosition(background:getPosition())
    contentLayer:addChild(pDisplayValueLabel)
    
    
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
    contentLayer:addChild(stepper)
    
    -- Update the value label
    valueChanged(stepper)

    return contentLayer
end