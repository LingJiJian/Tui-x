require "extern"
require "tagMap/Tag_recombineui"

Recombineui = class("Recombineui",function()
	return TuiBase:create()
end)

Recombineui.__index = Recombineui
local __instance = nil

function Recombineui:create()
	local ret = Recombineui.new()
	__instance = ret
	TuiManager:getInstance():parseScene(ret,"panel_recombine",PATH_RECOMBINEUI)
	ret:onLoadComplete()
	return ret
end

function Recombineui:getControl(tagPanel,tagControl)
	local ret = nil
	ret = self:getPanel(tagPanel):getChildByTag(tagControl)
	return ret
end

function Recombineui:getPanel(tagPanel)
	local ret = nil
	if tagPanel == Tag_recombineui.PANEL_RECOMBINE then
		ret = self:getChildByTag(tagPanel)
	end
	return ret
end

---------------logic----------------------------

local function event_btn_back(p_sender)
	
	local scene = Welcomeui:create()
	cc.Director:getInstance():replaceScene(
		cc.TransitionFade:create(0.5, scene, cc.c3b(0,255,255)))
end

local function event_btn_click(p_sender)
	print("tag : "..tolua.cast(p_sender,"cc.cocoswidget::CWidget"):getUserTag())
end

local function event_adapt_gpvbag(p_convertview, idx)
	local pCell = p_convertview
	local btn = nil
	if pCell == nil then
		pCell = CGridPageViewCell:new()

		TuiManager:getInstance():parseCell(pCell, "cell_grid", PATH_RECOMBINEUI)
		btn = pCell:getChildByTag(Tag_recombineui.BTN_GRID)
		btn:setOnClickScriptHandler(event_btn_click)
	else
		btn = pCell:getChildByTag(Tag_recombineui.BTN_GRID)
	end
	tolua.cast(btn,"cc.cocoswidget::CWidget"):setUserTag(idx)
	return pCell
end

function Recombineui:onLoadComplete()
	--º”‘ÿÕÍ≥…
	local btnBack = self:getControl(Tag_recombineui.PANEL_RECOMBINE,Tag_recombineui.BTN_BACK)
	btnBack:setOnClickScriptHandler(event_btn_back)
	
	local gpvBag = self:getControl(Tag_recombineui.PANEL_RECOMBINE,Tag_recombineui.GPV_BAG)
	gpvBag:setDataSourceAdapterScriptHandler(event_adapt_gpvbag)
	gpvBag:reloadData()
	
end