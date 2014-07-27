require "Cocos2d"
require "Cocos2dConstants"
require "welcome/welcomeui.lua"

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

-- for CCLuaEngine traceback
function __G__TRACKBACK__(msg)
    cclog("----------------------------------------")
    cclog("LUA ERROR: " .. tostring(msg) .. "\n")
    cclog(debug.traceback())
    cclog("----------------------------------------")
end

local function main()
    collectgarbage("collect")
    -- avoid memory leak
    collectgarbage("setpause", 100)
    collectgarbage("setstepmul", 5000)
	
    local scene = Welcomeui:create()
    cc.Director:getInstance():runWithScene(scene)
end


xpcall(main, __G__TRACKBACK__)
