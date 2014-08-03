require "extern"
require "tagMap/Tag_showphoneui"

Showphoneui = class("Showphoneui",function()
	return TuiBase:create()
end)

Showphoneui.__index = Showphoneui
local __instance = nil

function Showphoneui:create()
	local ret = Showphoneui.new()
	__instance = ret
	cc.SpriteFrameCache:getInstance():addSpriteFramesWithFile("showphone/showphoneui.plist")
	TuiManager:getInstance():parseScene(ret,"panel_showphone",PATH_SHOWPHONEUI)
	ret:onLoadComplete()
	return ret
end

function Showphoneui:getControl(tagPanel,tagControl)
	local ret = nil
	ret = self:getPanel(tagPanel):getChildByTag(tagControl)
	return ret
end

function Showphoneui:getPanel(tagPanel)
	local ret = nil
	if tagPanel == Tag_showphoneui.PANEL_SHOWPHONE then
		ret = self:getChildByTag(tagPanel)
	end
	return ret
end

---------------logic----------------------------
local circleMenu = nil

local function event_circleMenu_click(p_sender)
	print("click tag:"..p_sender:getTag())
	
	local scene = Welcomeui:create()
	cc.Director:getInstance():replaceScene(
		cc.TransitionFade:create(0.5, scene, cc.c3b(0,255,255)))
end

function Showphoneui:onLoadComplete()
	--加载完成
	circleMenu = self:getControl(Tag_showphoneui.PANEL_SHOWPHONE,Tag_showphoneui.CIRCLEMENU_SHOWPHONE)
	circleMenu:setOnClickScriptHandler(event_circleMenu_click)
	
end