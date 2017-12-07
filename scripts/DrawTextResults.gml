tieText = instance_find(ties0, 0);
winText = instance_find(playerWins0, 0);
lossText = instance_find(cpuWins0, 0);

draw_set_font(font0);
draw_text(tieText.x, tieText.y + 32, string(global.roundTies));
draw_text(winText.x, winText.y + 32, string(global.roundWins));
draw_text(lossText.x, lossText.y + 32, string(global.roundLosses));
