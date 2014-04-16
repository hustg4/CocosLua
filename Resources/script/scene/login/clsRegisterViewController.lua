--[[
 description:注册
 author:wp_g4
 date:2013/03/28
 --]]

class("clsRegisterViewController",clsViewController)

clsRegisterViewController.layer=nil

function clsRegisterViewController:load()
    Notifier:addObserver(NotifyEvent.UI.ShowRegisterView,self,self.showView)
end

function clsRegisterViewController:showView()
    self.layer=CCLayer:create()
    -- ask director the window size
    local size = CCDirector:sharedDirector():getWinSize();
    --(1)背景
    local spriteBg=CCSprite:create("images/Background_FullScreen_login.png");
    spriteBg:setPosition(size.width/2, size.height/2);
    self.layer:addChild(spriteBg);
    
    --(2)标题
    local labelTitle = CCLabelTTF:create("注册界面@登录场景", "Thonburi", 32);
    -- position the label on the center of the screen
    labelTitle:setPosition( size.width / 2, size.height/2 + 30 );
    -- add the label as a child to this layer
    self.layer:addChild(labelTitle);
    
    --(3)注册按钮
    local menuItemRegister = CCMenuItemFont:create("注册")
    --TODO 为什么此方法调用存在问题
    --menuItemRegister:setFontSize(20)
    menuItemRegister:setFontSizeObj(18)
    menuItemRegister:setPosition(0, 0)
    menuItemRegister:registerScriptTapHandler(MakeScriptHandler(self,self.menuCallbackRegister))
    menuItemRegister:setPosition(-40, -20)
    
    --(4)登录按钮
    local menuItemLogin = CCMenuItemFont:create("前往登录")
    menuItemLogin:setFontSizeObj(18)
    menuItemLogin:setPosition(0, 0)
    menuItemLogin:registerScriptTapHandler(MakeScriptHandler(self,self.menuCallbackLogin))
    menuItemLogin:setPosition(40, -20)
    
    local menu = CCMenu:create()
    menu:addChild(menuItemRegister)
    menu:addChild(menuItemLogin)
    menu:setTag(2222)
    self.layer:addChild(menu)
    
    --(5)遮罩层
    local size = CCSprite:create("images/icon/effect_gantanhao_up.png"):getContentSize()
    local backGround = CCScale9Sprite:create("images/icon/effect_gantanhao_up.png");
    local button=CCControlButton:create(backGround);
    button:setPosition(300, 200);
    
    button:setPreferredSize(CCSizeMake(40,200));
    button:addScriptDelegateForControlEvent(self, CCControlEventTouchUpInside);
    self.layer:addChild(button)
    
    self:getScene():addChild(self.layer)
end

function clsRegisterViewController:menuCallbackRegister()
    --kMaskTypePenetrate kMaskTypeCover
    local maskLayer = MaskLayer:create(CCRectMake(145,125,100,30),kMaskTypePenetrate)
    self.layer:addChild(maskLayer)
end

function clsRegisterViewController:menuCallbackLogin()
    print("clsRegisterViewController:menuCallbackLogin")
    self.layer:removeFromParentAndCleanup(true)
    Notifier:notify(NotifyEvent.UI.ShowLoginView)
end

function clsRegisterViewController:unload()
    Notifier:removeObserver(NotifyEvent.UI.ShowRegisterView,self)
end

function clsRegisterViewController:onControlEvent(sender,eventType)
    print("CCControlEventTouchUpInside:"..CCControlEventTouchUpInside)
    print("eventType:"..eventType)
end
