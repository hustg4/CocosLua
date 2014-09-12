--[[
	description:按钮，支持在scrollview中显示
	author:qiuwenbo
	date:01/24/2014
]]

class("clsButton", clsNode)

clsButton.__create = clsButton.create

clsButton.target = nil
clsButton.selector = nil

clsButton.m_bSelected = false
clsButton.m_bEnabled = true
clsButton.m_scaleOnTouch = false        --点击时是否缩放

clsButton.m_pNormalImage = nil
clsButton.m_pSelectedImage = nil
clsButton.m_pDisabledImage = nil


local TAG_ACTION_SCALE = 9988765         --点击时缩放action的tag

function clsButton:create( normalImage, selectedImage, disabledImage, target, selector)
	local button = clsButton:__create()
	button:setAnchorPoint(cc.p(0.5, 0.5))
    button:initWithNormalImage(normalImage, selectedImage, disabledImage, target, selector)

    return button
end

function clsButton:initWithNormalImage( normalImage, selectedImage, disabledImage, target, selector )
	local normalSprite = nil
    local selectedSprite = nil
    local disabledSprite = nil

    if normalImage then 
    	normalSprite = cc.Sprite:create(normalImage)
    end 

    if selectedImage then 
    	selectedSprite = cc.Sprite:create(selectedImage)
    end

    if disabledImage then 
    	disabledSprite = cc.Sprite:create(disabledImage)
    end 

	return self:initWithNormalSprite( normalSprite, selectedSprite, disabledSprite, target, selector)
end

function clsButton:initWithNormalSprite( normalSprite, selectedSprite, disabledSprite, target, selector)

	self.target = target
	self.selector = selector

	self.touchLayer = cc.Layer:create()
    self.touchLayer:registerScriptTouchHandler(cl.makeScriptHandler(self,self.onTouch))
    self.touchLayer:setTouchEnabled(true)
    self:addChild(self.touchLayer)

	self:setNormalImage(normalSprite)
	self:setSelectedImage(selectedSprite)
	self:setDisabledImage(disabledSprite)

	if self.m_pNormalImage then 
		self:setContentSize(self.m_pNormalImage:getContentSize())
	end

	return true
end

function clsButton:setNormalImage( pImage )
	if pImage ~= self.m_pNormalImage then 
		if pImage then 
			pImage:setAnchorPoint(cc.p(0, 0))
			self:addChild(pImage)
		end

		if self.m_pNormalImage then 
			self:removeChild(self.m_pNormalImage, true)
		end 

		self.m_pNormalImage = pImage

		self:setContentSize(self.m_pNormalImage:getContentSize())
		self:updateImagesVisibility() 
	end 
end

function clsButton:setSelectedImage( pImage )
	if pImage ~= self.m_pSelectedImage then 
		if pImage then 
			pImage:setAnchorPoint(cc.p(0, 0))
			self:addChild(pImage)
		end

		if self.m_pSelectedImage then 
			self:removeChild(self.m_pSelectedImage, true)
		end 

		self.m_pSelectedImage = pImage

		self:setContentSize(self.m_pSelectedImage:getContentSize())
		self:updateImagesVisibility() 
	end 
end

function clsButton:setDisabledImage( pImage )
	if pImage ~= self.m_pDisabledImage then 
		if pImage then 
			pImage:setAnchorPoint(cc.p(0, 0))
			self:addChild(pImage)
		end

		if self.m_pDisabledImage then 
			self:removeChild(self.m_pDisabledImage, true)
		end 

		self.m_pDisabledImage = pImage

		self:setContentSize(self.m_pDisabledImage:getContentSize())
		self:updateImagesVisibility() 
	end 
end

function clsButton:isSelected()
	return self.m_bSelected
end

function clsButton:isEnable()
	return self.m_bEnabled
end

function clsButton:isScaleOnTouch()
    return self.m_scaleOnTouch
end

function clsButton:setScaleOnTouch(scaleOnTouch)
    self.m_scaleOnTouch = scaleOnTouch
end

function clsButton:selected()
	self.m_bSelected = true

	if self.m_pNormalImage then 
		if self.m_pDisabledImage then 
			self.m_pDisabledImage:setVisible(false)
		end

		if self.m_pSelectedImage then 
			self.m_pNormalImage:setVisible(false)
			self.m_pSelectedImage:setVisible(true)
		else
			self.m_pNormalImage:setVisible(true)
		end  
	end
    
    if self:isScaleOnTouch() then
        local action = self:getActionByTag(TAG_ACTION_SCALE)
        if action then
            self:stopAction(action)
        end
        local actionScale = cc.ScaleTo:create(0.1,1.2)
        actionScale:setTag(TAG_ACTION_SCALE)
        self:runAction(actionScale)
    end
    
end

function clsButton:unselected()
	self.m_bSelected = false

	if self.m_pNormalImage then 
		self.m_pNormalImage:setVisible(true)

		if self.m_pSelectedImage then 
			self.m_pSelectedImage:setVisible(false)
		end 

		if self.m_pDisabledImage then 
			self.m_pDisabledImage:setVisible(false)
		end  
	end
    
    if self:isScaleOnTouch() then
        local action = self:getActionByTag(TAG_ACTION_SCALE)
        if action then
            self:stopAction(action)
        end
        local actionScale = cc.ScaleTo:create(0.1,1)
        actionScale:setTag(TAG_ACTION_SCALE)
        self:runAction(actionScale)
    end
    
end

function clsButton:setEnabled( enabled )
	
	if self.m_bEnabled ~= enabled then 
		self.m_bEnabled = enabled
		self:updateImagesVisibility()
	end 
end

function clsButton:updateImagesVisibility()
	if self.m_bEnabled then 
		if self.m_pNormalImage then 
			self.m_pNormalImage:setVisible(true)
		end 

		if self.m_pSelectedImage then 
			self.m_pSelectedImage:setVisible(false)
		end 

		if self.m_pDisabledImage then 
			self.m_pDisabledImage:setVisible(false)
		end 
	else 
		if self.m_pDisabledImage then 
			if self.m_pNormalImage then 
				self.m_pNormalImage:setVisible(false)
			end

			if self.m_pSelectedImage then 
				self.m_pSelectedImage:setVisible(false)
			end

			if self.m_pDisabledImage then 
				self.m_pDisabledImage:setVisible(true)
			end 
		else 
			if self.m_pNormalImage then 
				self.m_pNormalImage:setVisible(true)
			end

			if self.m_pSelectedImage then 
				self.m_pSelectedImage:setVisible(false)
			end

			if self.m_pDisabledImage then 
				self.m_pDisabledImage:setVisible(false)
			end
		end 
	end 
end

--处理触摸层接受touch事件
function clsButton:onTouch(eventType, x, y)
    if self:isEnable() then
        if eventType == "began" then
            return self:onTouchBegan(x, y)
        elseif eventType == "moved" then
            return self:onTouchMoved(x, y)
        else
            return self:onTouchEnded(x, y)
        end
    end
end

function clsButton:onTouchBegan(x, y)

    self.shouldSelect = true

    local isTouched = self:isTouched(x, y)

    if isTouched == true then 
    	self:selected()
    else 
    	self:unselected()
    end 

    return true
end

function clsButton:onTouchMoved(x, y)

    --一旦点击有移动过，则不选择怪物
    self.shouldSelect = false

    local isTouched = self:isTouched(x, y)

    if isTouched == true then
    	self:selected()
    else 
    	self:unselected()
    end
end

function clsButton:onTouchEnded(x, y)
	self:unselected()

	if self.shouldSelect == true then
		local isTouched = self:isTouched(x, y)
		if isTouched == true and self.selector and self.target then
			self.selector(self.target, self:getTag(), self) 	
		end 
	end 
end

--判断点击是否在范围内
function clsButton:isTouched( x, y )
	local originInScene = self:convertToWorldSpace(cc.p(0, 0))

	if x - originInScene.x >= 0 and x - (originInScene.x + self:getContentSize().width) <= 0 and y - originInScene.y >= 0 and y - (originInScene.y + self:getContentSize().height) <= 0 then
		return true
	end

	return false 
end