--[[
 description:更新界面
 author:wp_g4
 date:2013/03/28
 --]]

class("clsUpdateViewController",clsViewController)

clsUpdateViewController.layer=nil

function clsUpdateViewController:load()
    --显示更新界面
    self:showView()
    --检查客户端版本
    local resourceManager=ResourceManager:sharedResourceManager()
    resourceManager:setRootURL(NetConfig.ResourceServerRootUrl)
    
    resourceManager:setScriptDelegate(self)
    
    resourceManager:checkVersion()
    
end

function clsUpdateViewController:unload()
end


function clsUpdateViewController:showView()
    
    self.layer=CCLayer:create()
    -- ask director the window size
    local size = CCDirector:sharedDirector():getWinSize();
    --(1)背景
    local spriteBg=CCSprite:create("images/Background_FullScreen_login.png");
    spriteBg:setPosition(size.width/2, size.height/2);
    self.layer:addChild(spriteBg);
    
    --(2)标题
    local labelTitle = CCLabelTTF:create("更新客户端版本", "Thonburi", 32);
    -- position the label on the center of the screen
    labelTitle:setPosition( size.width / 2, size.height/2 + 30 );
    -- add the label as a child to this layer
    self.layer:addChild(labelTitle, 1);
    
    self:getScene():addChild(self.layer)
end

function clsUpdateViewController:onVersionCheckCompleted(latest,fileNum,needUpdateProgram,programUpdateURL)
    print("clsUpdateViewController:onVersionCheckCompleted",latest,fileNum,needUpdateProgram,programUpdateURL)
    if latest then
        --版本已经最新，则直接切换到登录
        print("版本已经最新")
        
        local num = ResourceManager:sharedResourceManager():checkModule("m1")
        print("模块需要更新的文件数量:"..num)
        if num > 0 then
            ResourceManager:sharedResourceManager():updateModule("m1")
        end
        
    else
        --版本过时，需要更新
        print("版本过时，开始更新")
        if needUpdateProgram then
            print("程序需要更新，更新地址：",programUpdateURL)
            else
            ResourceManager:sharedResourceManager():updateVersion()
        end
        
    end
end

function clsUpdateViewController:onVersionUpdated()
    --更新完成:重启
    Game:restart()
end

function clsUpdateViewController:onModuleUpdated(moduleName)
    print("模块["..moduleName.."]已更新")
end

function clsUpdateViewController:onSingleFileUpdated(moduleName,filePath)
end

function clsUpdateViewController:onErrorOccured(errorType,errorMsg)
    print(errorType,errorMsg)
end

