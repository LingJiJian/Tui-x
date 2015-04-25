require "extern"
require "Cocos2d"
require "Cocos2dConstants"
require "welcome/welcomeui"
require "welcome/dialog/msgBox"
require "showphone/showphoneui"
require "recombine/recombineui"
require "bag/bagui"

-- cclog
cclog = function(...)
    print(string.format(...))
end

_G._scaleResolutionX = TuiManager:getInstance():getScaleResolutionX()
_G._scaleResolutionY = TuiManager:getInstance():getScaleResolutionY()
-- Arp
Arp = function(p)
    p.x = p.x * _G._scaleResolutionX
    p.y = p.y * _G._scaleResolutionY
    return p
end

REGISTER_SCENE_FUNC = function(sceneName,constructFunc)
    CSceneManager:getInstance():registerSceneClassScriptFunc(sceneName,constructFunc)
end

LoadScene = function(sceneName)
    return CSceneManager:getInstance():loadScene(sceneName)
end

-- for CCLuaEngine traceback
function __G__TRACKBACK__(msg)
    cclog("----------------------------------------")
    cclog("LUA ERROR: " .. tostring(msg) .. "\n")
    cclog(debug.traceback())
    cclog("----------------------------------------")
end

local function main()
    collectgarbage("collect")
    -- -- avoid memory leak
    collectgarbage("setpause", 100)
    collectgarbage("setstepmul", 5000)
	
	-- --注册场景
    REGISTER_SCENE_FUNC("MsgBox",MsgBox.create)
    REGISTER_SCENE_FUNC("Showphoneui",Showphoneui.create)
    REGISTER_SCENE_FUNC("Recombineui",Recombineui.create)
    REGISTER_SCENE_FUNC("Bagui",Bagui.create)
    REGISTER_SCENE_FUNC("Welcomeui",Welcomeui.create)

    CSceneManager:getInstance():runWithScene(LoadScene("Welcomeui"))
end

xpcall(main, __G__TRACKBACK__)
