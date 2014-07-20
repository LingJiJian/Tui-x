require "Cocos2d"
require "Cocos2dConstants"
require "welcome/welcomeui.lua"

-- cclog
cclog = function(...)
    print(string.format(...))
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
