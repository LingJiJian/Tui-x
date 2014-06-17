require "extern"
require "tagMap/Tag_welcomeui"

MsgBox = class("MsgBox",function()
	return TuiBase:create()
end)

MsgBox.__index = MsgBox
local __instance = nil

function MsgBox:create()
	local ret = MsgBox.new()
	TuiManager:getInstance():parseScene(ret,"panel_msgbox",PATH_WELCOMEUI)
	ret:onLoadComplete()
	__instance = ret
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

---------------logic----------------------------
local btnClose 		= nil
local labAtlasNum 	= nil
local progHp  		= nil
local sliderTest 	= nil

local function event_btn_close(p_sender)

    local action = cc.CallFunc:create(function(sender,table)
		__instance:getParent():getChildByTag(Tag_welcomeui.PANEL_WELCOME):setModalable(false)
		__instance:removeFromParent()
    end)
    __instance:runAction(action)
end

local function event_prog_hp(p_sender, n_value)
	labAtlasNum:setString(n_value)
	print("progTest :"..n_value)
end

local function event_slider_test(p_sender, n_value)
	print("sliderTest :"..n_value)
	progHp:setValue(n_value)
end

function MsgBox:onLoadComplete()

	--注册事件
	labAtlasNum = self:getControl(Tag_welcomeui.PANEL_MSGBOX,Tag_welcomeui.LABATLAS_NUM)

	btnClose = self:getControl(Tag_welcomeui.PANEL_MSGBOX,Tag_welcomeui.BTN_CLOSE)
	btnClose:setOnClickScriptHandler(event_btn_close)

	progHp = self:getControl(Tag_welcomeui.PANEL_MSGBOX,Tag_welcomeui.PROG_HP)
	progHp:setShowValueLabel(true)
	progHp:setOnValueChangedScriptHandler(event_prog_hp)

	sliderTest = self:getControl(Tag_welcomeui.PANEL_MSGBOX,Tag_welcomeui.SLIDER_TEST)
	sliderTest:setOnValueChangedScriptHandler(event_slider_test)

end