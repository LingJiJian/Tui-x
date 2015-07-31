require "tagMap/Tag_welcomeui"

MsgBox = class("MsgBox",function()
	return TuiBase:create()
end)
MsgBox.__index = MsgBox
function MsgBox:create()
	local ret = MsgBox.new()
	ret:setOnLoadSceneScriptHandler(function() ret:onLoadScene() end)
	ret:setOnMessageScriptHandler(function(msg,obj) ret:onMessage(msg,obj) end)
	return ret
end

function MsgBox:getControl(tagPanel,tagControl)
	local ret = nil
	ret = self:getPanel(tagPanel):getChildByTag(tagControl)
	return ret
end

function MsgBox:getPanel(tagPanel)
	local ret = nil
	if tagPanel == Tag_welcomeui.PANEL_MSGBOX then
		ret = self:getChildByTag(tagPanel)
	end
	return ret
end

---------------------------------------------
function MsgBox:onLoadScene()

	TuiManager:getInstance():parseScene(self,"panel_msgbox",PATH_WELCOMEUI)

	self.labAtlasNum = self:getControl(Tag_welcomeui.PANEL_MSGBOX,Tag_welcomeui.LABATLAS_NUM)

	self.btnClose = self:getControl(Tag_welcomeui.PANEL_MSGBOX,Tag_welcomeui.BTN_CLOSE)
	self.btnClose:setOnClickScriptHandler(function(p_sender)
	  	CSceneManager:getInstance():popUIScene(self)
	  	CCMsgManager:getInstance():PostMessage(125,cc.Node:create())
	end)

	self.progHp = self:getControl(Tag_welcomeui.PANEL_MSGBOX,Tag_welcomeui.PROG_HP)
	self.progHp:setOnValueChangedScriptHandler(function(p_sender, n_value)
		self.labAtlasNum:setString(n_value)
		print("progTest :"..n_value)
	end)

	self.sliderTest = self:getControl(Tag_welcomeui.PANEL_MSGBOX,Tag_welcomeui.SLIDER_TEST)
	self.sliderTest:setOnValueChangedScriptHandler(function(p_sender, n_value)
		print("sliderTest :"..n_value)
		self.progHp:setValue(n_value)
	end)

	self.btn = CButton:create("main/btn_green_normal.png","")
	self.btn:setPosition(cc.p(100,100))
	self.btn:setText("点击")
	self:getPanel(Tag_welcomeui.PANEL_MSGBOX):addChild(self.btn)
	self.btn:setOnClickScriptHandler(function(sender)
		CSceneManager:getInstance():runUIScene(LoadScene("MsgBoxTwo"))
	end)
end

function MsgBox:onMessage(msg,obj)
	print(" onMessage !!!! ",tostring(obj))
end
----------------------------------------------------------------------------------------
MsgBoxTwo = class("MsgBoxTwo",function()
	return TuiBase:create()
end)
function MsgBoxTwo:create()
	local ret = MsgBoxTwo.new()
	ret:setOnLoadSceneScriptHandler(function() ret:onLoadScene() end)
	return ret
end
function MsgBoxTwo:onLoadScene()
	TuiManager:getInstance():parseScene(self,"panel_msgbox",PATH_WELCOMEUI)

	self.panel = self:getChildByTag(Tag_welcomeui.PANEL_MSGBOX)
	self.btn = CButton:create("main/btn_green_normal.png","main/btn_green_select.png")
	self.btn:setPosition(cc.p(100,100))
	self.btn:setText("点击")
	self.btn:setOnClickScriptHandler(function(sender)
		CSceneManager:getInstance():runUIScene(LoadScene("MsgBoxThree"))
	end)
	self.panel:addChild(self.btn)
	self.panel:setScale(0.7)

	self.btnClose = self:getControl(Tag_welcomeui.PANEL_MSGBOX,Tag_welcomeui.BTN_CLOSE)
	self.btnClose:setOnClickScriptHandler(function()
		CSceneManager:getInstance():popUIScene(self)
	end)
end

function MsgBoxTwo:getControl(tagPanel,tagControl)
	return self:getChildByTag(tagPanel):getChildByTag(tagControl)
end

----------------------------------------------------------------------------------------
MsgBoxThree = class("MsgBoxThree",function()
	return TuiBase:create()
end)
function MsgBoxThree:create()
	local ret = MsgBoxThree.new()
	ret:setOnLoadSceneScriptHandler(function() ret:onLoadScene() end)
	return ret
end
function MsgBoxThree:onLoadScene()
	TuiManager:getInstance():parseScene(self,"panel_msgbox",PATH_WELCOMEUI)

	self.panel = self:getChildByTag(Tag_welcomeui.PANEL_MSGBOX)
	self.panel:setScale(0.4)

	self.btnClose = self:getControl(Tag_welcomeui.PANEL_MSGBOX,Tag_welcomeui.BTN_CLOSE)
	self.btnClose:setOnClickScriptHandler(function()
		CSceneManager:getInstance():popUIScene(self)
	end)
end

function MsgBoxThree:getControl(tagPanel,tagControl)
	return self:getChildByTag(tagPanel):getChildByTag(tagControl)
end