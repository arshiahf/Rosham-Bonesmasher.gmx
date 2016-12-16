-----------------------------------------------------------------------------------------
--
-- menu.lua
--
-----------------------------------------------------------------------------------------

local widget = require( "widget" )
local composer = require( "composer" )
local scene = composer.newScene()

local g = globVar

local sceneGroup

-- CREATE FUNCTION
local function scene:create(event)

	sceneGroup = self.view

end

-- SHOW FUNCTION
local function scene:show(event)



end

-- HIDE FUNCTION
local function scene:hide(event)



end

-- DESTROY FUNCTION
local function scene:destroy(event)

end

scene:addEventListener( "create", scene )
scene:addEventListener( "show", scene )
scene:addEventListener( "hide", scene )
scene:addEventListener( "destroy", scene )

return scene