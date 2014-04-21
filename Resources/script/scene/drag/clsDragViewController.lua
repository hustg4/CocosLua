
--[[
 description:drag
 author:wxf
 date:2013/06/26
 --]]


class("clsDragViewController",clsViewController)

clsDragViewController.layer=nil
clsDragViewController.icon=nil
clsDragViewController.pageControl=nil
clsDragViewController.scrollView=nil
clsDragViewController.scrollViewPageNum = 4

clsDragViewController.isTestDrag = false

--clsDragViewController.isTestScrollView = true
clsDragViewController.isTestScrollViewPageControl = false
clsDragViewController.isTestScrollViewIndicator = 2  --0:not show 1: show 2: show custum

clsDragViewController.isTestRadioMenu = false
clsDragViewController.isTestPickerView = false
clsDragViewController.isTestCheckBox = true

clsDragViewController.isTestLongPress = false

function clsDragViewController:load()
    --Notifier:addObserver(NotifyEvent.UI.ShowLoginView,self,self.showView)
    self:showView()
end

function clsDragViewController:movedImage(filename)

    --sample: move item self
    --return nil
    
    --sample: move a copy
    ----[[
    local sprite = nil
    if filename then
        sprite = CCSprite:create("images/"..filename);
    else
        sprite = CCSprite:create("images/cat.png");
    end
    sprite:setAnchorPoint(cc.p(0,0))

    sprite:runAction(CCRotateTo:create(0.1,0));
    local rotLeft = CCRotateBy:create(0.1, -4.0);
    local rotCenter = CCRotateBy:create(0.1, 0.0);
    local rotRight = CCRotateBy:create(0.1, 4.0);
    

    local array =  CCArray:create();--  (rotLeft,rotCenter,rotRight,rotCenter,nil);
    array:addObject(rotLeft);
    array:addObject(rotCenter);
    array:addObject(rotRight);
    array:addObject(rotCenter);

    --local array =  CCArray:create(rotLeft,rotCenter,rotRight,rotCenter,nil);
    
    local rotSeq = CCSequence:create(array);
    sprite:runAction(CCRepeatForever:create(rotSeq));

    return sprite;
    --]]--
end

function clsDragViewController:testRadioMenu()
    local pointArray = CCPointArray:create(4);
    for i = 1,4 do
        local p = cc.p(i * 40 , i * 40);
        pointArray:addControlPoint(p)
    end
    local radioMenu = CCRadioMenu:create(pointArray, "images/bird.png", "images/cat.png");
    radioMenu:setScriptDelegate(self)
    self.layer:addChild(radioMenu);
end

function clsDragViewController:addScrollView()
    local images = {"bird.png", "cat.png", "dog.png","turtle.png"}
    local layer = CCLayerColor:create(ccc4(57, 109, 111, 255));
    
    local scrollView = CCScrollView:create(CCSizeMake(400,80), layer)
    scrollView:setScriptDelegate(self)
    

    
    scrollView:setDirection(kCCScrollViewDirectionHorizontal)
    
    
    scrollView:setContentSize(CCSizeMake(400 * self.scrollViewPageNum, 80));
    layer:setContentSize(scrollView:getContentSize());
    scrollView:setPosition(cc.p(50,100));
    
    for i = 1,#images do
        local filename = images[i]
        local sprite = CCSprite:create("images/"..filename);
        sprite:setPosition(cc.p(20 + (i - 1) * 400, 10));
        scrollView:addChild(sprite,2)
    end

    self.layer:addChild(scrollView);
    self.scrollView = scrollView;
end

function clsDragViewController:testPageControl()
    
    if not self.scrollView then
        self:addScrollView()

    end
    self.scrollView:setPagingEnabled(true)
    -- add page Control


    local pageControl = CCPageControl:create("images/icon/ccpagecontrol_full_dot.png","images/icon/ccpagecontrol_empty_dot.png");
    pageControl:setHidesForSinglePage(true);
    pageControl:setNumberOfPages(self.scrollViewPageNum);
    pageControl:setPosition(cc.p(200 ,50));
    self.pageControl = pageControl
    
    self.layer:addChild(pageControl)
    
    
end

function clsDragViewController:testScrollIndictor()
    
    
    if not self.scrollView then
        self:addScrollView()
    end
    
    
    self.scrollView:setPagingEnabled(false)

    if self.isTestScrollViewIndicator == 1 then
        self.scrollView:setShowScrollIndicator(true)
    elseif  self.isTestScrollViewIndicator == 2 then
        print ("test 2");
        local tmpSprite = CCSprite:create("images/icon/scroll_indicator_h.png");
        local tmpSize = tmpSprite:getContentSize();
        local fullRect = CCRectMake(0,0, tmpSize.width, tmpSize.height);
        local insetRect = CCRectMake(16, 7,tmpSize.width-16*2, tmpSize.height-7*2);
        
        local pSprite = CCScale9Sprite:create("images/icon/scroll_indicator_h.png",fullRect,insetRect);
        pSprite:setContentSize(CCSizeMake(100,14));
        self.scrollView:setScrollIndicator(pSprite);

    end
    
end

function clsDragViewController:testDrag()
    --ask director the window size
    local size = CCDirector:getInstance():getWinSize()
    
    --(1)sprites
    local images = {"bird.png", "cat.png", "dog.png","turtle.png"};
    
    for i = 1,#images do
        local filename = images[i]
        --local sprite = CCSprite:create("images/"..filename);
        local sprite = self:movedImage(filename)
        local dragableItem = CCDragableItem:create(sprite)
        dragableItem:setMovedImage(self:movedImage(filename))
        dragableItem:setTag(i)
        dragableItem:setScriptDelegate(self)
        --print(dragableItem);

        local offsetFraction = i/(#images+1)
        dragableItem:setPosition(20 , offsetFraction * size.height);
        self.layer:addChild(dragableItem);
        
    end
    
    
    
    self.icon = CCSprite:create("images/editbox.png")
    self.icon:setPosition(size.width/2, size.height/2)
    self.layer:addChild(self.icon)
end

function clsDragViewController:testPickerView()
    local picker_view = CCPickerView:create()
    picker_view:setScriptDataSource(self)
    picker_view:setScriptDelegate(self)
    picker_view:selectRow(1,0,false)
    --self.picker_view = tolua.cast(self.picker_view,"CCNode")
    picker_view:setPosition(cc.p(273,150))
    
    self.layer:addChild(picker_view)
    print("!!!!!!!!!!!!!!!",picker_view)
end

function clsDragViewController:testCheckBox()
    local checkbox = CCControlCheckBox:create("images/icon/default_checkbox_checked.png","images/icon/default_checkbox_unchecked.png","setting")
    checkbox:addScriptDelegateForControlEvent(self,CCControlEventValueChanged)
    checkbox = tolua.cast(checkbox,"CCNode")
    checkbox:setPosition(cc.p(200,200))
    self.layer:addChild(checkbox)
end

function clsDragViewController:testLongPress()
    
    local s = CCSprite:create("images/cat.png")
    s:setPosition(cc.p(300,200))
    self.layer:addChild(s)
    local lpRecognizer = CCLongPressGestureRecognizer:create()
    lpRecognizer:setScriptDelegate(self)
    s:addChild( lpRecognizer )
end

function clsDragViewController:showView()
    self.layer = CCLayer:create()
    self:getScene():addChild(self.layer)
    
    
    if self.isTestDrag then
        self:testDrag()
    end
    
    if self.isTestRadioMenu then
        self:testRadioMenu()
    end
    
    if self.isTestScrollViewPageControl then
        self:testPageControl()
    end
    
    if self.isTestScrollViewIndicator ~= 0 then
        self:testScrollIndictor()
    end
    
    if self.isTestPickerView then
        self:testPickerView()
    end
   
    if self.isTestCheckBox then
        self:testCheckBox()
    end
    
    if self.isTestLongPress then
        self:testLongPress()
    end
end

--DragableItem delegate
function clsDragViewController:onClicked(item)
    print("clsDragViewController:on clsDragViewController:onClicked", item:getPositionX(),item:getPositionY());
end

function clsDragViewController:onDragBegan(item)
    print("clsDragViewController:on DragBegan", item:getPositionX(),item:getPositionY());
end

function clsDragViewController:onDragging(item,x,y)
    print("clsDragViewController:on Dragging",item,x,y)
end

function clsDragViewController:onDragEnded(item,x,y)
    print("clsDragViewController:on Drag ended",x,y);
    local movedNode = item:getMovedImage();
    if movedNode == nil then
          movedNode = item
    end

    local rect = CCRectMake(x - movedNode:getAnchorPointInPoints().x, y - movedNode:getAnchorPointInPoints().y, movedNode:getContentSize().width, movedNode:getContentSize().height)
    

    if rect:intersectsRect( self.icon:boundingBox()) then
        print("keep")
        --sample: move item self
        --item:setPosition(self.icon:getPosition())
    
        --sample: move a copy
        ----[[
         self.icon:addChild(self:movedImage())
         item:setEnabled(false)
        --]]--
    end
end



function clsDragViewController:onClicked(item)
    print("clsDragViewController:on clicked", item);
    if (item:getTag() == 4) then
        ReplaceScene(clsUpdateScene)
    end
end

function clsDragViewController:onItemClicked(radioMenu,index)
    print("clsDragViewController:on item clicked",  radioMenu, index, radioMenu:getSelectedIndex());
end

function clsDragViewController:scrollViewDidScrollToPage(scrollView,page,totalPage)
    self.pageControl:setCurrentPage(page);
end




--pickerview delegate

function clsDragViewController:numberOfComponentsInPickerView(pickerView)
    return 1
end

function clsDragViewController:numberOfRows(pickerView,component)
    return 40
end

function clsDragViewController:node(pickerView,row,componet,reusingNode)
    local str  = tostring(row + 1)
    local label = CCLabelTTF:create(str,"Helvetica",12)
    return label
end


function clsDragViewController:didSelect(pickerView, row,component)
    print("didSelect row = %d, component = %d", row, component);
end


function clsDragViewController:rowHeightForComponent(pickerview, component)
    return 18
end


function  clsDragViewController:widthForComponent(pickerview, component)
    
    return 95
    
end

function clsDragViewController:spaceBetweenComponents(pickerView)
    return 10
end


function clsDragViewController:sizeOfPickerView(pickerView)
    local size = CCSize(45 - 5, 63 - 5)
    
    return size
end


function clsDragViewController:overlayImage(pickerView)
    --local sprite = CCSprite:create("ui/FuBenSaoDang/3slots.png");
    local sprite = CCSprite:create("images/bg_pickerView.png");
    print("sprete " , sprite)
    
    return sprite;
end


--checkbox delegate
function  clsDragViewController:onControlEvent(control, event)
    local checkbox = tolua.cast(control,"CCControlCheckBox");
    local bool=checkbox:isChecked()
    print("is checkbox checked:", bool)
end


-- gesture recognizer

function  clsDragViewController:onGestureRecognized(g)
    local node =  g:getParent();
    print  ("onGestureRecognized node ",node);
end




function  clsDragViewController:onGestureEnded(g)
    
    local node =  g:getParent();
    print  ("onLongPressEnded node ", node);
end
