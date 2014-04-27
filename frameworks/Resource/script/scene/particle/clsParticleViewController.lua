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
    
    self.layer=cc.Layer:create()
    self.layer:setTouchEnabled(true)
    self.layer:registerScriptTouchHandler(MakeScriptHandler(self,self.onTouch))
    self:getScene():addChild(self.layer)
    
    -- ask director the window size
    local size = cc.Director:getInstance():getWinSize()
    
    --(1)背景
    local spriteBg=cc.Sprite:create("images/Background_FullScreen_login.png")
    spriteBg:setPosition(size.width/2, size.height/2);
    self.layer:addChild(spriteBg)
    
    --[[
    --泡泡
    local particle = cc.ParticleSystemQuad:create("particle/effect_stage_bubble.plist")
    particle:setPosition(size.width/2, size.height/2)
    self.layer:addChild(particle)
    
    --树叶
    local particle = cc.ParticleSystemQuad:create("particle/effect_stage_leaf.plist")
    particle:setPosition(size.width/2, size.height/2)
    self.layer:addChild(particle)
    
    --火星
    local particle = cc.ParticleSystemQuad:create("particle/effect_touch.plist")
    particle:setPosition(size.width/2, size.height/2)
    self.layer:addChild(particle)
     
     --]]
    
    --[[
    --技能
    for i=1,4 do
        local particle = cc.ParticleSystemQuad:create("particle/effect_fire_10"..i..".plist")
        particle:setPosition(i*100, size.height/2)
        self.layer:addChild(particle)
    end
    --]]
    
    --[[
    --火花
    local particle = cc.ParticleSystemQuad:create("particle/effect_monster_jump.plist")
    particle:setPosition(size.width/2, size.height/2)
    self.layer:addChild(particle)
    --]]
    
    --[[
    --受击
    for i=1,4 do
        local particle = cc.ParticleSystemQuad:create("particle/effect_hurt10"..i..".plist")
        particle:setPosition(i*100, size.height/2)
        self.layer:addChild(particle)
    end
     --]]
    
    --[[
    --白光
    local particle = cc.ParticleSystemQuad:create("particle/effect_pictext_select.plist")
    particle:setPosition(size.width/2, size.height/2)
    self.layer:addChild(particle)
    
    --彩光
    local particle = cc.ParticleSystemQuad:create("particle/effect_guide_cloud.plist")
    particle:setPosition(size.width/2, size.height/2)
    self.layer:addChild(particle)
    --]]
    
    --[[
    --小星星
    local particle = cc.ParticleSystemQuad:create("particle/effect_arrowstar.plist")
    particle:setPosition(size.width/2, size.height/2)
    self.layer:addChild(particle)
    
    --云
    local particle = cc.ParticleSystemQuad:create("particle/effect_cloud.plist")
    particle:setPosition(size.width/2, size.height/2)
    self.layer:addChild(particle)
     --]]
    
    --[[
    --星光
    local particle = cc.ParticleSystemQuad:create("particle/effect_eggpool.plist")
    particle:setPosition(size.width/2, size.height/2)
    self.layer:addChild(particle)
    
    --一闪
    local particle = cc.ParticleSystemQuad:create("particle/effect_eggtrans.plist")
    particle:setPosition(size.width/2, size.height/2)
    self.layer:addChild(particle)
    --]]
    
    --[[
    --碎纸
    local particle = cc.ParticleSystemQuad:create("particle/effect_firework_paper.plist")
    particle:setPosition(size.width/2, size.height/2)
    self.layer:addChild(particle)
    --]]
    
    --[[
    local particle = cc.ParticleSystemQuad:create("particle/effect_fire_101.plist")
    particle:setPosition(100, size.height/2)
    self.layer:addChild(particle)
    
    local moveRight = cc.MoveTo:create(1,cc.p(400,size.height/2))
    local moveLeft = cc.MoveTo:create(1,cc.p(100,size.height/2))
    local seq = cc.Sequence:createWithTwoActions(moveRight, moveLeft)
    particle:runAction(cc.RepeatForever:create(seq))
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
        self.reviveLayer:removeFromParent(true)
        self.reviveLayer = nil
    end
    
    local winSize = cc.Director:getInstance():getWinSize()
    
    self.reviveLayer = cc.Layer:create()
    self.layer:addChild(self.reviveLayer)
    
    --精灵
    local spriteHero = cc.Sprite:create("images/juren.png")
    spriteHero:setPosition(cc.p(winSize.width/2,winSize.height/2))
    self.reviveLayer:addChild(spriteHero)
    
    local heroSize = spriteHero:getContentSize()
    
    --四道光线
    for i=1,4 do
        
        local spriteLine = cc.Sprite:create("images/revive/2.png")
        spriteLine:setAnchorPoint(cc.p(0.5,0))
        spriteLine:setPosition(cc.p(heroSize.width/2,heroSize.height/2))
        spriteLine:setRotation(90*i)
        spriteHero:addChild(spriteLine)
        
        --缩小动画
        local scaleTo = cc.EaseIn:create(cc.ScaleTo:create(0.5,0.1),2)
        spriteLine:runAction(scaleTo)
    end
    
    -- 光圈 和 十字星
    local ring = cc.Sprite:create("images/revive/1.png")
    ring:setOpacity(0)
    ring:setPosition(cc.p(heroSize.width/2,heroSize.height/2))
    spriteHero:addChild(ring)
    
    local star = cc.Sprite:create("images/revive/4.png")
    star:setOpacity(0)
    star:setPosition(cc.p(heroSize.width/2,heroSize.height/2))
    spriteHero:addChild(star)
    
    local delay = cc.DelayTime:create(0.2)
    local fadeIn = cc.FadeIn:create(0)
    local scaleTo = cc.ScaleTo:create(0.3,0.1)

    local actions = CCArray:create()
    actions:addObject(delay)
    actions:addObject(fadeIn)
    actions:addObject(scaleTo)
    
    local seq = cc.Sequence:create(actions)
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
            local spriteItem = cc.Sprite:create(items[index].path)
            spriteItem:setAnchorPoint(cc.p(0.5,0))
            spriteItem:setOpacity(0)
            spriteItem:setPosition(cc.p((heroSize.width-itemTotalWidth)/2+math.random()*itemTotalWidth,heroSize.height/2 - 50))
            spriteHero:addChild(spriteItem)
            
            local totalTime = 0.6
            local delayTime = math.random()*totalTime
            local delay = cc.DelayTime:create(delayTime)
            local fadeIn = cc.FadeIn:create(0.1)
            local fadeOut = cc.FadeOut:create(0.1)
            
            local actions = CCArray:create()
            actions:addObject(delay)
            actions:addObject(fadeIn)
            actions:addObject(fadeOut)
            
            local seq = cc.Sequence:create(actions)
            spriteItem:runAction(seq)
        end
        
        --小星星爆
        local particle = cc.ParticleSystemQuad:create("particle/light.plist")
        particle:setPosition(cc.p(heroSize.width/2,heroSize.height/2 - 50))
        particle:setAutoRemoveOnFinish(true)
        spriteHero:addChild(particle)
        
    end
    
    local delay = cc.DelayTime:create(0.5)
    local callback = CCCallFunc:create(endParticleFunc)
    spriteHero:runAction(cc.Sequence:createWithTwoActions(delay, callback))
    
    
end

function clsParticleViewController:showStaBar()
    local winSize = cc.Director:getInstance():getWinSize()
    
    local endPercent = 100
    local animationTime = 1
    
    --背景条
    local spriteBg = cc.Sprite:create("images/sta/sta_bar_background.png")
    local bgSize = spriteBg:getContentSize()
    
    spriteBg:setPosition(cc.p(winSize.width/2,winSize.height/2))
    self.layer:addChild(spriteBg)
    
    
    --体力条
    local progresBar = CCProgressTimer:create(cc.Sprite:create("images/sta/sta_bar.png"))
    local barSize = progresBar:getContentSize()
    
    progresBar:setAnchorPoint(cc.p(0,0))
    progresBar:setPosition(cc.p((bgSize.width-barSize.width)/2,(bgSize.height-barSize.height)/2))
    progresBar:setType(kCCProgressTimerTypeBar)
    progresBar:setMidpoint(cc.p(0, 0))
    progresBar:setBarChangeRate(cc.p(1, 0))
    progresBar:setPercentage(0)
    spriteBg:addChild(progresBar)
    
    local progresTo = cc.ProgressTo:create(animationTime,endPercent)
    
    local function endParticleFunc()
        
        --小星星爆
        
        local particle = cc.ParticleSystemQuad:create("particle/fireworks2.plist")
        particle:setAutoRemoveOnFinish(true)
        particle:setPosition(cc.p(barSize.width,bgSize.height/2))
        spriteBg:addChild(particle)
        
    end
    
    local callback = CCCallFunc:create(endParticleFunc)
    
    progresBar:runAction(cc.Sequence:createWithTwoActions(progresTo, callback))
    
    --小星星（尾巴）
    local x = progresBar:getPercentage()/100*bgSize.width
    local particleTail = cc.ParticleSystemQuad:create("particle/startail.plist")
    particleTail:setAutoRemoveOnFinish(true)
    particleTail:setPosition(cc.p(x,bgSize.height/2))
    spriteBg:addChild(particleTail)
    
    local moveTo = cc.MoveTo:create(animationTime,cc.p(endPercent/100*bgSize.width,bgSize.height/2))
    
    local function removeTail()
        particleTail:removeFromParent(true)
    end
    
    local callback = CCCallFunc:create(removeTail)
    
    particleTail:runAction(cc.Sequence:createWithTwoActions(moveTo, callback))
    
end
