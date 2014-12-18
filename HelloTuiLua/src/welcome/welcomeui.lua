require "tagMap/Tag_welcomeui"

Welcomeui = class("Welcomeui",function()
	return TuiBase:create()
end)

Welcomeui.__index = Welcomeui
local __instance = nil

function Welcomeui:create()
	local ret = Welcomeui.new()
	__instance = ret
	ret:setOnLoadSceneScriptHandler(function() ret:onLoadScene() end)
	return ret
end

function Welcomeui:getControl(tagPanel,tagControl)
	local ret = nil
	ret = self:getPanel(tagPanel):getChildByTag(tagControl)
	return ret
end

function Welcomeui:getPanel(tagPanel)
	local ret = nil
	if tagPanel == Tag_welcomeui.PANEL_WELCOME then
		ret = self:getChildByTag(tagPanel)
	end
	return ret
end

---------------logic----------------------------
local btnGo =  			nil
local animCoin = 		nil
local armBtnTest = 		nil
local listGoods = 		nil
local tgvOption = 		nil
local munStepTest = 	nil
local ckbTest =			nil
local ctvlLeft = 		nil
local editLogin = 		nil
local window =	  		nil
local btnShowPhone =	nil

local function event_ctvl_left(p_sender, fx, fy)
	local x, y = animCoin:getPosition()
	animCoin:setPosition( cc.pAdd( cc.p(x,y) , Arp(cc.p(fx,fy))) )
end

local function event_armbtn_test(p_sender)
	CSceneManager:getInstance():replaceScene(
		CCSceneExTransitionFade:create(0.5,LoadScene("Bagui")))
end

local function event_btn_pay(p_sender)
	local layout = p_sender:getParent()
	print("pay index:"..layout:getTag())
end

local function event_tgv_option(p_sender, b_checked)
	print("tgvOption "..type(b_checked))
end

local function event_numStep_test(p_sender, n_value)
	print("numStep :"..n_value)
end

local function event_ckb_test(p_sender,b_checked)
	print("ckbTest:"..type(b_checked))
end

local function event_edit_login(strEventName,pSender)
	if strEventName == "return" then
		print(pSender:getText())
	end
end

local function event_btn_go(p_sender)
	CSceneManager:getInstance():runUIScene(LoadScene("MsgBox"))
end

local function event_btn_showphone(p_sender)
	CSceneManager:getInstance():replaceScene(
		CCSceneExTransitionFade:create(0.5,LoadScene("Showphoneui")))
end

function Welcomeui:onLoadScene()

	cc.SpriteFrameCache:getInstance():addSpriteFrames("main/mainui.plist")
	TuiManager:getInstance():parseScene(self,"panel_welcome",PATH_WELCOMEUI)
	--注册事件
	window = self:getPanel(Tag_welcomeui.PANEL_WELCOME)

 	animCoin = self:getControl(Tag_welcomeui.PANEL_WELCOME,Tag_welcomeui.ANIM_COIN)

 	ctvlLeft = self:getControl(Tag_welcomeui.PANEL_WELCOME,Tag_welcomeui.CTLV_LEFT)
	ctvlLeft:setOnControlScriptHandler(event_ctvl_left)

 	armBtnTest = self:getControl(Tag_welcomeui.PANEL_WELCOME,Tag_welcomeui.ARMBTN_TEST2)
 	armBtnTest:setOnClickScriptHandler(event_armbtn_test)

 	listGoods = self:getControl(Tag_welcomeui.PANEL_WELCOME,Tag_welcomeui.LIST_GOODS)
 	local cout = listGoods:getNodeCount()
 	for i=0,cout-1 do
 		local item = listGoods:getNodeAtIndex(i)
 		local btnPlay = item:getChildByTag(Tag_welcomeui.BTN_ITEMPAY)
 		btnPlay:setOnClickScriptHandler(event_btn_pay)
 	end

 	tgvOption = self:getControl(Tag_welcomeui.PANEL_WELCOME,Tag_welcomeui.TGV_OPTION)
 	tgvOption:setOnCheckScriptHandler(event_tgv_option)

 	munStepTest = self:getControl(Tag_welcomeui.PANEL_WELCOME,Tag_welcomeui.NUMSTEP_TEST)
 	munStepTest:setOnValueChangedScriptHandler(event_numStep_test)

 	ckbTest = self:getControl(Tag_welcomeui.PANEL_WELCOME,Tag_welcomeui.CKB_TEST)
 	ckbTest:setOnCheckScriptHandler(event_ckb_test)

 	editLogin = self:getControl(Tag_welcomeui.PANEL_WELCOME,Tag_welcomeui.EDIT_LOGIN)
 	editLogin:registerScriptEditBoxHandler(event_edit_login)

 	btnGo = self:getControl(Tag_welcomeui.PANEL_WELCOME,Tag_welcomeui.BTN_OK)
 	btnGo:setOnClickScriptHandler(event_btn_go)

 	btnShowPhone = self:getControl(Tag_welcomeui.PANEL_WELCOME,Tag_welcomeui.BTN_SHOWPHONE)
 	btnShowPhone:setOnClickScriptHandler(event_btn_showphone)
end 

