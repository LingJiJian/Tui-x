require "extern"
require "tagMap/Tag_map"

Mapui = class("Mapui",function()
	return TuiBase:create()
end)

Mapui.__index = Mapui
local __instance = nil

function Mapui:create()
	local ret = Mapui.new()
	__instance = ret
	ret:setOnLoadSceneScriptHandler(function() ret:onLoadScene() end)
	return ret
end

function Mapui:getControl(tagPanel,tagControl)
	local ret = nil
	ret = self:getPanel(tagPanel):getChildByTag(tagControl)
	return ret
end

function Mapui:getPanel(tagPanel)
	local ret = nil
	if tagPanel == Tag_map.PANEL_MAP then
		ret = self:getChildByTag(tagPanel)
	end
	return ret
end

local function event_btn_back(p_sender)
	
	CSceneManager:getInstance():replaceScene(
		CCSceneExTransitionFade:create(0.5,LoadScene("Welcomeui")))
end


function Mapui:onLoadScene()

	TuiManager:getInstance():parseScene(self,"panel_map",PATH_MAP)

	local mapView = self:getControl(Tag_map.PANEL_MAP,Tag_map.MAP_TEST)
	mapView:setRole(cc.Sprite:create("map/img_icon.png"),cc.p(0,0),5)
    
    local btnBack = self:getControl(Tag_map.PANEL_MAP,Tag_map.BTN_BACK)
	btnBack:setOnClickScriptHandler(event_btn_back)
end