--[[
 description:demo
 author:cokey
 date:2014/04/26
 --]]

class("clsDemoViewController",clsViewController)

clsDemoViewController.layer = nil

function clsDemoViewController:load()
    self:showView()
end

function clsDemoViewController:showView()
    local winSize = cc.Director:getInstance():getWinSize()
    self.layer = cc.Layer:create()
    
    --(1)横向TableView
    local tableView = cc.TableView:create(cc.size(480,65))
    tableView:setDirection(cc.SCROLLVIEW_DIRECTION_HORIZONTAL)
    tableView:setPosition(cc.p(0, 0))
    tableView:setDelegate()
    self.layer:addChild(tableView)
    --registerScriptHandler functions must be before the reloadData funtion
    tableView:registerScriptHandler(MakeScriptHandler(self,self.numberOfCellsInTableView),cc.NUMBER_OF_CELLS_IN_TABLEVIEW)  
    tableView:registerScriptHandler(MakeScriptHandler(self,self.scrollViewDidScroll),cc.SCROLLVIEW_SCRIPT_SCROLL)
    tableView:registerScriptHandler(MakeScriptHandler(self,self.scrollViewDidZoom),cc.SCROLLVIEW_SCRIPT_ZOOM)
    tableView:registerScriptHandler(MakeScriptHandler(self,self.tableCellTouched),cc.TABLECELL_TOUCHED)
    tableView:registerScriptHandler(MakeScriptHandler(self,self.cellSizeForTable),cc.TABLECELL_SIZE_FOR_INDEX)
    tableView:registerScriptHandler(MakeScriptHandler(self,self.tableCellAtIndex),cc.TABLECELL_SIZE_AT_INDEX)
    tableView:reloadData()

    --(2)纵向TableView
    tableView = cc.TableView:create(cc.size(65, 320))
    tableView:setDirection(cc.SCROLLVIEW_DIRECTION_VERTICAL)
    tableView:setPosition(cc.p(winSize.width - 65, 0))
    tableView:setDelegate()
    tableView:setVerticalFillOrder(cc.TABLEVIEW_FILL_TOPDOWN)
    self.layer:addChild(tableView)
    tableView:registerScriptHandler(MakeScriptHandler(self,self.scrollViewDidScroll),cc.SCROLLVIEW_SCRIPT_SCROLL)
    tableView:registerScriptHandler(MakeScriptHandler(self,self.scrollViewDidZoom),cc.SCROLLVIEW_SCRIPT_ZOOM)
    tableView:registerScriptHandler(MakeScriptHandler(self,self.tableCellTouched),cc.TABLECELL_TOUCHED)
    tableView:registerScriptHandler(MakeScriptHandler(self,self.cellSizeForTable),cc.TABLECELL_SIZE_FOR_INDEX)
    tableView:registerScriptHandler(MakeScriptHandler(self,self.tableCellAtIndex),cc.TABLECELL_SIZE_AT_INDEX)
    tableView:registerScriptHandler(MakeScriptHandler(self,self.numberOfCellsInTableView),cc.NUMBER_OF_CELLS_IN_TABLEVIEW)
    tableView:reloadData()
    
    --(3)ScrollView
    local scrollView = cc.ScrollView:create()
    scrollView:setViewSize(cc.size(winSize.width/2,winSize.height/2))
    scrollView:setPosition(cc.p(65,winSize.height/2 - 65))
    local flowersprite =  cc.Sprite:create("images/flower.jpg")
    if nil ~= flowersprite then
        scrollView:setContainer(flowersprite)
        scrollView:updateInset()
    end
    scrollView:setDirection(cc.SCROLLVIEW_DIRECTION_BOTH)
    scrollView:setClippingToBounds(true)
    scrollView:setBounceable(true)
    scrollView:setDelegate()
    scrollView:registerScriptHandler(MakeScriptHandler(self,self.scrollViewDidScroll),cc.SCROLLVIEW_SCRIPT_SCROLL)
    scrollView:registerScriptHandler(MakeScriptHandler(self,self.scrollViewDidZoom),cc.SCROLLVIEW_SCRIPT_ZOOM)
    self.layer:addChild(scrollView)
    
    --(4)EditText
    local function editBoxTextEventHandle(strEventName,pSender)
		local edit = pSender
		local strFmt 
		if strEventName == "began" then
			strFmt = string.format("editBox %p DidBegin !", edit)
			print(strFmt)
		elseif strEventName == "ended" then
			strFmt = string.format("editBox %p DidEnd !", edit)
			print(strFmt)
		elseif strEventName == "return" then
			strFmt = string.format("editBox %p was returned !",edit)
			if edit == EditName then
				TTFShowEditReturn:setString("Name EditBox return !")
			elseif edit == EditPassword then
				TTFShowEditReturn:setString("Password EditBox return !")
			elseif edit == EditEmail then
				TTFShowEditReturn:setString("Email EditBox return !")
			end
			print(strFmt)
		elseif strEventName == "changed" then
			strFmt = string.format("editBox %p TextChanged, text: %s ", edit, edit:getText())
			print(strFmt)
		end
	end
    local editName = cc.EditBox:create(cc.size(240, 40), cc.Scale9Sprite:create("images/yellow_edit.png"))
    editName:setPosition(cc.p(240, 200))
    editName:setAnchorPoint(cc.p(0.5, 0.5))
    editName:setPlaceHolder("Email:")
    editName:setInputMode(cc.EDITBOX_INPUT_MODE_EMAILADDR)
    editName:registerScriptEditBoxHandler(editBoxTextEventHandle)
    self.layer:addChild(editName)

    local editPassword = cc.EditBox:create(cc.size(240, 40), cc.Scale9Sprite:create("images/yellow_edit.png"))
    editPassword:setPosition(cc.p(240, 100))
    editPassword:setAnchorPoint(cc.p(0.5, 0.5))
    editPassword:setFontColor(cc.c3b(0,255,0))
    editPassword:setPlaceHolder("Password:")
    editPassword:setMaxLength(6)
    editPassword:setInputFlag(cc.EDITBOX_INPUT_FLAG_PASSWORD)
    editPassword:setInputMode(cc.EDITBOX_INPUT_MODE_SINGLELINE)
    self.layer:addChild(editPassword)
    
    self:getScene():addChild(self.layer)
end

function clsDemoViewController:scrollViewDidScroll(view)
    --print("scrollViewDidScroll")
end

function clsDemoViewController:scrollViewDidZoom(view)
    --print("scrollViewDidZoom")
end

function clsDemoViewController:tableCellTouched(table,cell)
    print("cell touched at index: " .. cell:getIdx())
end

function clsDemoViewController:cellSizeForTable(table,idx) 
    --return 格子高度，格子宽度
    return 65,70
end

function clsDemoViewController:tableCellAtIndex(table, idx)
    local strValue = string.format("%d",idx)
    local cell = table:dequeueCell()
    local label = nil
    if nil == cell then
        cell = cc.TableViewCell:new()
        local sprite = cc.Sprite:create("images/bird.png")
        sprite:setAnchorPoint(cc.p(0,0))
        sprite:setPosition(cc.p(0,0))
        cell:addChild(sprite)

        label = cc.LabelTTF:create(strValue, "Helvetica", 20.0)
        label:setAnchorPoint(cc.p(0,0))
        label:setPosition(cc.p(0,0))
        label:setTag(123)
        cell:addChild(label)
    else
        label = cell:getChildByTag(123)
        if nil ~= label then
            label:setString(strValue)
        end
    end

    return cell
end

function clsDemoViewController:numberOfCellsInTableView(table)
   return 25
end

function clsDemoViewController:unload()
end