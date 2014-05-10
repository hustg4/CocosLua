
--[[
 description:登录
 author:wp_g4
 date:2013/03/28
 --]]


class("clsLoginViewController",clsUIViewController)

clsLoginViewController.layer=nil
clsLoginViewController.modalLayer = nil

function clsLoginViewController:load()
    Notifier:addObserver(NotifyEvent.UI.ShowLoginView,self,self.showView)
    Notifier:addObserver(NotifyEvent.Net.LoginAction,self,self.loginCallback)
    self:showView()
end

function clsLoginViewController:showView()
    
    --ask director the window size
    local size = cc.Director:getInstance():getWinSize()
    self.layer = cc.Layer:create()

    --(1)背景
    local spriteBg = cc.Sprite:create("images/Background_FullScreen_login.png")
    spriteBg:setPosition(size.width/2, size.height/2)
    self.layer:addChild(spriteBg)
    
    --(2)标题
    local labelTitle = cc.LabelTTF:create("Abc123!!?@登录场景" , "DFPYuanW7-GB", 32)
    --labelTitle:setStroke(cc.c3b(0,0,0),1)
    --labelTitle:setShadow(cc.c3b(0,0,0),1,-1)
    --local labelTitle = cc.LabelBMFont:create("文档接口的实现","font/hh.fnt")
    -- position the label on the center of the screen
    labelTitle:setColor(cc.c3b(255,0,0))
    labelTitle:setPosition(cc.p(size.width/2,size.height/2+50))
    -- add the label as a child to this layer
    self.layer:addChild(labelTitle)
    
    --[[
    local labelHTML = CCHTMLLabelTTF:create("<font face='Arial-BoldMT' size=22 color='#FFFFFF'>皮糙肉厚：</font><font face='Arial-BoldMT' size=22 color='#FFCE00'>不大于200伤害的攻击对其无效</font>","Arial-BoldMT",22)
    labelHTML:setPosition(cc.p(size.width/2,size.height/2-50))
    self.layer:addChild(labelHTML)
    --]]
    
    --(3)注册按钮
    --local menuItemRegister = cc.MenuItemFont:create("注册")
    local menuItemRegister = cc.MenuItemLabel:create(cc.LabelTTF:create("注册2" , "汉仪蝶语体简", 32))
    --TODO 为什么此方法调用存在问题
    --menuItemRegister:setFontSize(20)
    --menuItemRegister:setFontSizeObj(20)
    menuItemRegister:registerScriptTapHandler(MakeScriptHandler(self,self.menuCallbackRegister))
    menuItemRegister:setPosition(180, 160)
    
    --(4)登录按钮
    local menuItemLogin = cc.MenuItemFont:create("登录")
    menuItemLogin:setFontSizeObj(20)
    menuItemLogin:registerScriptTapHandler(MakeScriptHandler(self,self.menuCallbackLogin))
    menuItemLogin:setPosition(240, 160)
    
    --(4)模态对话框按钮
    local menuItemModal = cc.MenuItemFont:create("模态")
    menuItemModal:setFontSizeObj(20)
    menuItemModal:registerScriptTapHandler(MakeScriptHandler(self,self.menuCallbackModal))
    menuItemModal:setPosition(300, 160)
    
    local menuItemSprite1 = cc.MenuItemSprite:create(cc.Sprite:create("images/icon/effect_gantanhao_disable.png"),nil)
    local menuItemSprite2 = cc.MenuItemSprite:create(cc.Sprite:create("images/icon/effect_gantanhao_up.png"),nil)
    local menuItemToogle = cc.MenuItemToggle:create(menuItemSprite1)
    menuItemToogle:addSubItem(menuItemSprite2)
    menuItemToogle:setPosition(460, 40)
    
    local menu = cc.Menu:create()
    menu:setPosition(0,0)
    
    menu:addChild(menuItemRegister)
    menu:addChild(menuItemLogin)
    menu:addChild(menuItemModal)
    menu:addChild(menuItemToogle)
    
    menu:setTag(14111)
    self.layer:addChild(menu)
    self:setRootLayer(self.layer)
    
    self.layer:setTouchEnabled(true)
    self.layer:registerScriptTouchHandler(MakeScriptHandler(self,self.onTouch))
    
    self.layer:setAccelerometerEnabled(true)
    self.layer:registerScriptAccelerateHandler(MakeScriptHandler(self,self.onAccelerate))
    
    --AutoLayout(self.layer)
    
    --[[
    local button = clsButton:create("images/long_button_blue.png")
    button:setEnabled(false)
    button:setZOrder(0)
    button:setScaleOnTouch(true)
    button:setPosition(cc.p(200,200))
    self.layer:addChild(button)
    
    local button = clsButton:create("images/long_button_blue.png")
    button:setEnabled(false)
    button:setZOrder(1)
    button:setScaleOnTouch(true)
    button:setPosition(cc.p(220,200))
    self.layer:addChild(button)
    --]]
    
end

function clsLoginViewController:onTouch(eventType,x,y)
    
    if eventType == "began" then
        
        --[[
        if self.webView then
            self.webView:destroy()
            self.webView = nil
        else
            
            local size = cc.Director:getInstance():getWinSize()
            local w = 320
            local h = 240
            
            local spriteBg = cc.Sprite:create("images/blue.png")
            spriteBg:setAnchorPoint(cc.p(0,0))
            spriteBg:setPosition(cc.p(50,50))
            self.layer:addChild(spriteBg)
            
            local spriteSize = spriteBg:getContentSize()
            
            self.webView = WebView:new(cc.rect(50,50,spriteSize.width,spriteSize.height))
            self.webView:loadURL("http://www.baidu.com")
            self.webView:show()
        end
        
         --]]
         
        return true
    end
end

function clsLoginViewController:menuCallbackRegister()
    --self.layer:removeFromParent(true)
    --Notifier:notify(NotifyEvent.UI.ShowRegisterView)
    Game:restart();
end

function clsLoginViewController:menuCallbackLogin(tag,sender)
    self.layer:unregisterScriptTouchHandler()
    --MessageSender:login("test1737","111111")
    --[[
    local texture2d = CCTextureCache:sharedTextureCache():addImage("images/dog.png")
    local textureParams = ccTexParams:new()
    texture2d:setTexParameters(textureParams)
     --]]
    --[[
    CCTextureCacheUtil:addImageAsync("images/dog.png",self,"addImageCallback1")
    CCTextureCacheUtil:addImageAsync("images/icon/effect_gantanhao_disable.png",self,"addImageCallback2")
     --]]
end

function clsLoginViewController:addImageCallback1(path)
    print("clsLoginViewController:addImageCallback1:",path)
end

function clsLoginViewController:addImageCallback2(path)
    print("clsLoginViewController:addImageCallback2:",path)
end

function clsLoginViewController:menuCallbackModal(tag,sender)
    
    local size = cc.Director:getInstance():getWinSize()
    self.modalLayer = ModalLayer:create()
    
    self.layer:addChild(self.modalLayer)
    
    local tableView = cc.TableView:create(self,cc.size(300,69))
    tableView:setTag(101)
    tableView:setScriptDelegate(self)
    tableView:setPosition(90, size.height/2)
    tableView:setDirection(kCCScrollViewDirectionHorizontal)
    tableView:reloadData()
    self.modalLayer:addChild(tableView)
end

function clsLoginViewController:loginCallback(result)
    if result then
        print("登录成功，获取玩家详细数据")
        MessageSender:getDtl()
        else
        print("登录失败")
    end
end

function clsLoginViewController:onAccelerate(x,y,z,time)
    if math.abs(x) >=1.5 or math.abs(y) >=1.5 or math.abs(z) >=1.5 then
        print("clsLoginViewController:onAccelerate",x,y,z,time)
    end
end

--table data source
function clsLoginViewController:cellSizeForTable(tableView)
    --print("clsLoginViewController:cellSizeForTable")
    return cc.size:new(29,69)
end

function clsLoginViewController:numberOfCellsInTableView(tableView)
    --print("clsLoginViewController:numberOfCellsInTableView")
    return 10
end

function clsLoginViewController:tableCellAtIndex(tableView,index)
    --print("clsLoginViewController:tableCellAtIndex")
    local cell = tableView:dequeueCell()
    if cell == nil then
        
        cell = cc.TableViewCell:create()
        local sprite = cc.Sprite:create("images/icon/effect_gantanhao_up.png")
        sprite:setAnchorPoint(CCPoint:new(0,0))
        sprite:setPosition(cc.p(0,0))
        cell:addChild(sprite)
        
    end
    return cell
end

--table delegate
function clsLoginViewController:tableCellTouched(tableView,cell)
    print("clsLoginViewController:tableCellTouched")
    print(tableView:getTag())
    self.modalLayer:removeFromParent(true)
end


function clsLoginViewController:unload()
    Notifier:removeObserver(NotifyEvent.UI.ShowLoginView,self)
end



