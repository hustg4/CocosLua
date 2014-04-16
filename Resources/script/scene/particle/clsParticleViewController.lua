--[[
 description:粒子界面
 author:wp_g4
 date:2013/03/28
 --]]

class("clsParticleViewController",clsViewController)

clsParticleViewController.layer=nil

function clsParticleViewController:load()
    
    self:showView()
    
end

function clsParticleViewController:unload()
end


function clsParticleViewController:showView()
    
    self.layer=CCLayer:create()
    self.layer:setTouchEnabled(true)
    self.layer:registerScriptTouchHandler(MakeScriptHandler(self,self.onTouch))
    self:getScene():addChild(self.layer)
    
    -- ask director the window size
    local size = CCDirector:sharedDirector():getWinSize()
    
    --(1)背景
    local spriteBg=CCSprite:create("images/Background_FullScreen_login.png")
    spriteBg:setPosition(size.width/2, size.height/2);
    self.layer:addChild(spriteBg)
    
    --[[
    --泡泡
    local particle = CCParticleSystemQuad:create("particle/effect_stage_bubble.plist")
    particle:setPosition(size.width/2, size.height/2)
    self.layer:addChild(particle)
    
    --树叶
    local particle = CCParticleSystemQuad:create("particle/effect_stage_leaf.plist")
    particle:setPosition(size.width/2, size.height/2)
    self.layer:addChild(particle)
    
    --火星
    local particle = CCParticleSystemQuad:create("particle/effect_touch.plist")
    particle:setPosition(size.width/2, size.height/2)
    self.layer:addChild(particle)
     
     --]]
    
    --[[
    --技能
    for i=1,4 do
        local particle = CCParticleSystemQuad:create("particle/effect_fire_10"..i..".plist")
        particle:setPosition(i*100, size.height/2)
        self.layer:addChild(particle)
    end
    --]]
    
    --[[
    --火花
    local particle = CCParticleSystemQuad:create("particle/effect_monster_jump.plist")
    particle:setPosition(size.width/2, size.height/2)
    self.layer:addChild(particle)
    --]]
    
    --[[
    --受击
    for i=1,4 do
        local particle = CCParticleSystemQuad:create("particle/effect_hurt10"..i..".plist")
        particle:setPosition(i*100, size.height/2)
        self.layer:addChild(particle)
    end
     --]]
    
    --[[
    --白光
    local particle = CCParticleSystemQuad:create("particle/effect_pictext_select.plist")
    particle:setPosition(size.width/2, size.height/2)
    self.layer:addChild(particle)
    
    --彩光
    local particle = CCParticleSystemQuad:create("particle/effect_guide_cloud.plist")
    particle:setPosition(size.width/2, size.height/2)
    self.layer:addChild(particle)
    --]]
    
    --[[
    --小星星
    local particle = CCParticleSystemQuad:create("particle/effect_arrowstar.plist")
    particle:setPosition(size.width/2, size.height/2)
    self.layer:addChild(particle)
    
    --云
    local particle = CCParticleSystemQuad:create("particle/effect_cloud.plist")
    particle:setPosition(size.width/2, size.height/2)
    self.layer:addChild(particle)
     --]]
    
    --[[
    --星光
    local particle = CCParticleSystemQuad:create("particle/effect_eggpool.plist")
    particle:setPosition(size.width/2, size.height/2)
    self.layer:addChild(particle)
    
    --一闪
    local particle = CCParticleSystemQuad:create("particle/effect_eggtrans.plist")
    particle:setPosition(size.width/2, size.height/2)
    self.layer:addChild(particle)
    --]]
    
    --[[
    --碎纸
    local particle = CCParticleSystemQuad:create("particle/effect_firework_paper.plist")
    particle:setPosition(size.width/2, size.height/2)
    self.layer:addChild(particle)
    --]]
    
    --[[
    local particle = CCParticleSystemQuad:create("particle/effect_fire_101.plist")
    particle:setPosition(100, size.height/2)
    self.layer:addChild(particle)
    
    local moveRight = CCMoveTo:create(1,ccp(400,size.height/2))
    local moveLeft = CCMoveTo:create(1,ccp(100,size.height/2))
    local seq = CCSequence:createWithTwoActions(moveRight, moveLeft)
    particle:runAction(CCRepeatForever:create(seq))
     --]]

end

--处理触摸层接受touch事件
function clsParticleViewController:onTouch(eventType, x, y)
    if eventType == "began" then
        --self:showStaBar()
        self:showReviveAnimation()
    end
end

function clsParticleViewController:showReviveAnimation()
    
    if self.reviveLayer then
        self.reviveLayer:removeFromParentAndCleanup(true)
        self.reviveLayer = nil
    end
    
    local winSize = CCDirector:sharedDirector():getWinSize()
    
    self.reviveLayer = CCLayer:create()
    self.layer:addChild(self.reviveLayer)
    
    --精灵
    local spriteHero = CCSprite:create("images/juren.png")
    spriteHero:setPosition(ccp(winSize.width/2,winSize.height/2))
    self.reviveLayer:addChild(spriteHero)
    
    local heroSize = spriteHero:getContentSize()
    
    --四道光线
    for i=1,4 do
        
        local spriteLine = CCSprite:create("images/revive/2.png")
        spriteLine:setAnchorPoint(ccp(0.5,0))
        spriteLine:setPosition(ccp(heroSize.width/2,heroSize.height/2))
        spriteLine:setRotation(90*i)
        spriteHero:addChild(spriteLine)
        
        --缩小动画
        local scaleTo = CCEaseIn:create(CCScaleTo:create(0.5,0.1),2)
        spriteLine:runAction(scaleTo)
    end
    
    -- 光圈 和 十字星
    local ring = CCSprite:create("images/revive/1.png")
    ring:setOpacity(0)
    ring:setPosition(ccp(heroSize.width/2,heroSize.height/2))
    spriteHero:addChild(ring)
    
    local star = CCSprite:create("images/revive/4.png")
    star:setOpacity(0)
    star:setPosition(ccp(heroSize.width/2,heroSize.height/2))
    spriteHero:addChild(star)
    
    local delay = CCDelayTime:create(0.2)
    local fadeIn = CCFadeIn:create(0)
    local scaleTo = CCScaleTo:create(0.3,0.1)

    local actions = CCArray:create()
    actions:addObject(delay)
    actions:addObject(fadeIn)
    actions:addObject(scaleTo)
    
    local seq = CCSequence:create(actions)
    ring:runAction(seq)
    
    local seqCopy = tolua.cast(seq:copy(),"CCAction")
    seqCopy:autorelease()
    star:runAction(seqCopy)
    
    --光环收缩结束
    local function endParticleFunc()
        
        --各种竖条随机出现
        local items = {{path="images/revive/2.png"},{path="images/revive/3.png"}}
        local itemTotalWidth = 60
        local num = 25
        for i=1,num do
            local index = math.ceil(math.random()*(#items))
            local spriteItem = CCSprite:create(items[index].path)
            spriteItem:setAnchorPoint(ccp(0.5,0))
            spriteItem:setOpacity(0)
            spriteItem:setPosition(ccp((heroSize.width-itemTotalWidth)/2+math.random()*itemTotalWidth,heroSize.height/2 - 50))
            spriteHero:addChild(spriteItem)
            
            local totalTime = 0.6
            local delayTime = math.random()*totalTime
            local delay = CCDelayTime:create(delayTime)
            local fadeIn = CCFadeIn:create(0.1)
            local fadeOut = CCFadeOut:create(0.1)
            
            local actions = CCArray:create()
            actions:addObject(delay)
            actions:addObject(fadeIn)
            actions:addObject(fadeOut)
            
            local seq = CCSequence:create(actions)
            spriteItem:runAction(seq)
        end
        
        --小星星爆
        local particle = CCParticleSystemQuad:create("particle/light.plist")
        particle:setPosition(ccp(heroSize.width/2,heroSize.height/2 - 50))
        particle:setAutoRemoveOnFinish(true)
        spriteHero:addChild(particle)
        
    end
    
    local delay = CCDelayTime:create(0.5)
    local callback = CCCallFunc:create(endParticleFunc)
    spriteHero:runAction(CCSequence:createWithTwoActions(delay, callback))
    
    
end

function clsParticleViewController:showStaBar()
    local winSize = CCDirector:sharedDirector():getWinSize()
    
    local endPercent = 100
    local animationTime = 1
    
    --背景条
    local spriteBg = CCSprite:create("images/sta/sta_bar_background.png")
    local bgSize = spriteBg:getContentSize()
    
    spriteBg:setPosition(ccp(winSize.width/2,winSize.height/2))
    self.layer:addChild(spriteBg)
    
    
    --体力条
    local progresBar = CCProgressTimer:create(CCSprite:create("images/sta/sta_bar.png"))
    local barSize = progresBar:getContentSize()
    
    progresBar:setAnchorPoint(ccp(0,0))
    progresBar:setPosition(ccp((bgSize.width-barSize.width)/2,(bgSize.height-barSize.height)/2))
    progresBar:setType(kCCProgressTimerTypeBar)
    progresBar:setMidpoint(ccp(0, 0))
    progresBar:setBarChangeRate(ccp(1, 0))
    progresBar:setPercentage(0)
    spriteBg:addChild(progresBar)
    
    local progresTo = CCProgressTo:create(animationTime,endPercent)
    
    local function endParticleFunc()
        
        --小星星爆
        
        local particle = CCParticleSystemQuad:create("particle/fireworks2.plist")
        particle:setAutoRemoveOnFinish(true)
        particle:setPosition(ccp(barSize.width,bgSize.height/2))
        spriteBg:addChild(particle)
        
    end
    
    local callback = CCCallFunc:create(endParticleFunc)
    
    progresBar:runAction(CCSequence:createWithTwoActions(progresTo, callback))
    
    --小星星（尾巴）
    local x = progresBar:getPercentage()/100*bgSize.width
    local particleTail = CCParticleSystemQuad:create("particle/startail.plist")
    particleTail:setAutoRemoveOnFinish(true)
    particleTail:setPosition(ccp(x,bgSize.height/2))
    spriteBg:addChild(particleTail)
    
    local moveTo = CCMoveTo:create(animationTime,ccp(endPercent/100*bgSize.width,bgSize.height/2))
    
    local function removeTail()
        particleTail:removeFromParentAndCleanup(true)
    end
    
    local callback = CCCallFunc:create(removeTail)
    
    particleTail:runAction(CCSequence:createWithTwoActions(moveTo, callback))
    
end
