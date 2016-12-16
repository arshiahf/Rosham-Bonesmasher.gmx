-----------------------------------------------------------------------------------------
--
-- main.lua
--
-----------------------------------------------------------------------------------------

display.setStatusBar( display.HiddenStatusBar )

local composer = require( "composer" )

globVar = {}
local g = globVar

g.rock = "rock"
g.paper = "paper"
g.scissors = "scissors"
g.player =
	{
		"wins" = 0,
		"losses" = 0,

		"rock" = 10,
		"paper" = 15,
		"scissors" = 20,
	}

g.player.win = 
	{
		"rock" = g.player.rock + g.computer.scissors,
		"paper" = g.player.paper + g.computer.rock,
		"scissors" = g.player.scissors + g.computer.paper,
	}

g.computer =
	{
		"wins" = 0,
		"losses" = 0,

		"rock" = 1,
		"paper" = 2,
		"scissors" = 3,
	}

g.computer.win = 
	{
		"rock" = g.computer.rock + g.player.scissors,
		"paper" = g.computer.paper + g.player.rock,
		"scissors" = g.computer.scissors + g.player.paper,
	}

g.tie =
	{
		"count" = 0,

		"rock" = g.player.rock + g.computer.rock,
		"paper" = g.player.rock + g.computer.rock,
		"scissors" = g.player.rock + g.computer.rock,
	}

composer.gotoScene( "menu" )