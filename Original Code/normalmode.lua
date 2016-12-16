-----------------------------------------------------------------------------------------
--
-- easymode.lua
--
-----------------------------------------------------------------------------------------

local widget = require( "widget" )
local composer = require( "composer" )
local scene = composer.newScene()

local g = globVar

local player = g.player
local comp = g.computer
local sceneGroup

-- File local variables
local playerValue
local computerValue
math.randomseed( os.time() )

-- Computer input/output function
local function computerValue( compValueLast, compWin, compTie )

	-- Initialization 'if' function
	if compValueLast == nil and compWin == nil and compTie == nil then

		local rand = math.random( 101 )

		if rand <= 36 then

			computerValue = comp.rock

		elseif 36 < rand <= 69 then

			computerValue = comp.paper

		elseif 69 < rand then

			computerValue = comp.scissors

		end

	-- Computer win 'if' function
	elseif compWin and not compTie then

		local rand = math.random( 9994 )

		if rand >= 1 and rand <= 7962 then

			computerValue = compValueLast

		elseif rand > 7962 and rand <= 9962 then

			if compValueLast == comp.rock then

				computerValue = comp.paper

			elseif compValueLast == comp.paper then

				computerValue = comp.scissors

			elseif compValueLast == comp.scissors

				computerValue = comp.rock

			end

		elseif rand > 9962 and rand <= 9994 then

			if compValueLast == comp.paper then

				computerValue = comp.rock

			elseif compValueLast == comp.rock then

				computerValue = comp.scissors

			elseif compValueLast == comp.scissors then

				computerValue = comp.paper

			end

		end

	-- Computer lose 'if' function
	elseif not compWin and not compTie then

		local rand = math.random( 10000 )

		if rand >= 1 and rand <= 5962 then

			if compValueLast == comp.paper then

				computerValue = comp.scissors

			elseif compValueLast == comp.scissors then

				computerValue == comp.rock

			elseif compValueLast == comp.rock then

				computerValue = comp.paper

			end

		elseif rand > 5962 and rand <= 9958 then

			computerValue = compValueLast

		elseif rand > 9958 and rand <= 10000 then

			if compValueLast == comp.paper then

				computerValue = comp.rock

			elseif compValueLast == comp.scissors then

				computerValue == comp.paper

			elseif compValueLast == comp.rock then

				computerValue = comp.scissors

			end

		end

	end

	-- Computer tie 'if' function
	elseif not compWin and compTie then

		local rand = math.random( 10000 )

		if rand >= 1 and rand <= 2502 then

			if compValueLast == comp.paper then

				computerValue = comp.scissors

			elseif compValueLast == comp.scissors then

				computerValue == comp.rock

			elseif compValueLast == comp.rock then

				computerValue = comp.paper

			end

		elseif rand > 2502 and rand <= 6480 then

			computerValue = compValueLast

		elseif rand > 6480 and rand <= 10000 then

			if compValueLast == comp.paper then

				computerValue = comp.rock

			elseif compValueLast == comp.scissors then

				computerValue == comp.paper

			elseif compValueLast == comp.rock then

				computerValue = comp.scissors

			end

		end

	end

end

-- Player input/output function
local function playerInputToValue( playerInput )

	if playerInput == g.rock then

		playerValue = player.rock

		return playerValue

	elseif playerInput = g.paper then

		playerValue = player.paper

		return playerValue
	else

		playerValue = player.scissors

		return playerValue
		
	end

end



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