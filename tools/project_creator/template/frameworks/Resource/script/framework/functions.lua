
--[[
 description:实用功能集合
 author:wp_g4
 date:2013/03/27
 --]]

--JsonObject->LuaTable JsonArray->LuaTable
function JsonToLua(json)
    local luaStr=json:toLuaString()
    local fun,err=loadstring("return "..luaStr)
    if err then
        print(luaStr)
        print(err)
    end
    return fun()
end

--NetResponse.body -> LuaTable
function ResponseBodyToLua(netResponse)
    local body = netResponse:getBody()
    return JsonToLua(body)
end

function ResponseMsgSentToLua(response)
    local msg = tolua.cast(response:getRequest():getBody(),"JSONObject")
    local msgLuaString=msg:toLuaString()
    local fun=loadstring("return "..msgLuaString)
    return fun()
end

--获取布局时的缩放比例
function GetLayoutScale()
    --计算scaleNoBoder与scaleShowAll 算法参见CCEGLViewProtocol
    local screenSize = cc.EGLView:sharedOpenGLView():getFrameSize()
    local designSize = cl.designSize()
    local scaleX = screenSize.width / designSize.width
    local scaleY = screenSize.height / designSize.height
    local scaleNoBoder = math.max(scaleX,scaleY)
    local scaleShowAll = math.min(scaleX,scaleY)
    --游戏使用kResolutionNoBorder模式，但是部分控件需要kResolutionShowAll模式的效果，故
    local scale = scaleShowAll / scaleNoBoder
    return scale
end

--[[
 对node上的子结点进行布局
 1、根据NoBoder模式与ShowAll模式的差异重新缩放
 2、调整坐标，结点的tag里有锚点信息,tag的格式为1axxx,一共5位，
 第二位a表示锚点，按九宫格从左到右，从上到下，依次为
 0 1 2
 3 4 5
 6 7 8
 --]]
function AutoLayout(node)
    local children = node:getChildren()
    if not children then
        return
    end
    
    for i = 1,#children do
        local child = tolua.cast(children[i],"CCNode")
        LayoutNode(child)
    end
end

--[[
 对node本身的大小、坐标进行调整
 --]]
--[[
 对node本身的大小、坐标进行调整
 1、根据NoBoder模式与ShowAll模式的差异重新缩放
 2、调整坐标，结点的tag里有锚点信息,tag的格式为1axxx,一共5位，
 第二位a表示锚点，按九宫格从左到右，从上到下，依次为
 0 1 2
 3 4 5
 6 7 8
 --]]
function LayoutNode(node)
    local TAG_LAYOUT_MIN = 10000
    local designSize = cl.designSize()
    local layoutScale = GetLayoutScale()
    --检查tag是否符合规范，不符合规范的不予处理
    local tag = node:getTag()
    if tag < TAG_LAYOUT_MIN then
        return
    end
    local nodeSize = node:getContentSize()
    --获取tag里的锚点信息
    local anchor = math.mod(math.floor(tag/1000),10)
    local x,y = node:getPosition()
    print("------------>",x,y)
    local anchorPoint = node:getAnchorPoint()
    
    --[[
     print("=======================================")
     print("tag:"..tag)
     print("layoutScale:"..layoutScale)
     print("l:"..VisibleRect:left().x.." r:"..VisibleRect:right().x.." t:"..VisibleRect:top().y.." b:"..VisibleRect:bottom().y)
     print("anchorPoint:",anchorPoint.x,anchorPoint.y)
     print("anchor:"..anchor.." x:"..x.." y:"..y.." w:"..nodeSize.width.." h:"..nodeSize.height)
     --]]
    
    local ax,ay = 0,0
    --x坐标调整
    if math.mod(anchor,3) == 0 then
        --左对齐
        x = VisibleRect:left().x + x
        ax=0
        elseif math.mod(anchor,3) == 1 then
        --居中
        --x = VisibleRect:left().x + x / designSize.width * VisibleRect:getVisibleRect().size.width
        ax=0.5
        else
        --右对齐
        x = VisibleRect:right().x - (designSize.width - x)
        ax=1
    end
    --y坐标调整
    if anchor < 3 then
        --上对齐
        y = VisibleRect:top().y - (designSize.height - y)
        ay=1
        elseif anchor < 6 then
        --居中
        --y = VisibleRect:bottom().y + y / designSize.height * VisibleRect:getVisibleRect().size.height
        ay=0.5
        else
        --下对齐
        y = VisibleRect:bottom().y + y
        ay=0
    end
    
    --设置缩放比例
    
    
    local oldScaleX = node:getScaleX()
    local oldScaleY = node:getScaleY()
    node:setScaleX(layoutScale*oldScaleX)
    node:setScaleY(layoutScale*oldScaleY)
    
    local ow,oh = nodeSize.width*oldScaleX*(1-layoutScale),nodeSize.height*oldScaleY*(1-layoutScale)
    local ox,oy = (node:getAnchorPoint().x-ax)*ow,(node:getAnchorPoint().y-ay)*oh
    x,y = x-ox , y-oy
    
    --[[
     print("x:"..x.." y:"..y.." ow:"..ow.." oh:"..oh.." ox:"..ox.." oy:"..oy)
     print("anchor:"..anchor.." x:"..x.." y:"..y.." w:"..nodeSize.width.." h:"..nodeSize.height)
     print("---------------------------------------")
     --]]
    node:setPosition(cc.p(x,y))
end

--创建菜单
function CreateMenu(...)
    local arg = pairlist(...)
    local menu = cc.Menu:create()
    menu:setPosition(cc.p(0,0))
    for i,item in ipairs(arg) do
        menu:addChild(item)
    end
    return menu
end

--转换ccb中的控件为EditBox
function ReplaceToEditBox(scale9Sprite,tips)
    local position = cc.p(scale9Sprite:getPosition())
    local size = scale9Sprite:getContentSize()

    local parentNode = scale9Sprite:getParent()
    scale9Sprite:retain()
    scale9Sprite:removeFromParent(false)
    
    local editBox = cc.EditBox:create(size,scale9Sprite)
    editBox:setPosition(position)
    editBox:setFont("Thonburi",32)
    editBox:setMaxLength(20)
    editBox:setPlaceholderFont("Thonburi",32)
    editBox:setPlaceHolder(tips)
    parentNode:addChild(editBox)
    
    scale9Sprite:release()
    return editBox
end

--修改sprite的texture
function ChangeSpriteTexture(sprite,imagePath)
    local texture = cc.Director:getInstance():getTextureCache():addImage(imagePath)
    local textureSize = texture:getContentSize()
    sprite:setTexture(texture)
    sprite:setTextureRect({x=0,y=0,width=textureSize.width,height=textureSize.height})
end

--为按钮添加文本
function AddTitleForMenuItem(menuItem,title,fontName,fontSize,tag)
    local size = menuItem:getContentSize()
    local labelTitle = cc.LabelTTF:create(title, fontName, fontSize)
    labelTitle:setPosition(cc.p(size.width/2,size.height/2))
    if tag then
        labelTitle:setTag(tag)
    end
    menuItem:addChild(labelTitle)
end

--设置TableView的dataSource和delegate
function SetDataSourceAndDelegateForTableView(tableView,dataSource,delegate)
    
end

--创建遮罩精灵（遮罩精灵，显示精灵）
function CreateMaskSprite(maskSprite,textureSprite)
    local maskSize = maskSprite:getTexture():getContentSize()
    
    local rt = cc.RenderTexture:create(maskSize.width,maskSize.height)
    
    local mContentSize = maskSprite:getContentSize()
    maskSprite:setPosition(cc.p(mContentSize.width/2,mContentSize.height/2))
    
    local tContentSize = textureSprite:getContentSize()
    textureSprite:setPosition(cc.p(tContentSize.width/2,tContentSize.height/2))
    
    maskSprite:setBlendFunc(gl.ONE,gl.ZERO)
    maskSprite:setFlippedY(true)
    
    textureSprite:setBlendFunc(gl.DST_ALPHA,gl.ZERO)
    textureSprite:setFlippedY(true)
    
    rt:begin()
    maskSprite:visit()
    textureSprite:visit()
    rt:endToLua()
    
    local sprite = rt:getSprite()
    
    local retval = cc.Sprite:createWithTexture(sprite:getTexture())
    return retval
end
