playerThrow = string_char_at(global.playerHistory, 1);
cpuThrow = string_char_at(global.cpuHistory, 1);

if(playerThrow == cpuThrow)
{
    global.playerResultHistory = global.TIE + global.playerResultHistory;
    global.cpuResultHistory = global.TIE + global.cpuResultHistory;
    global.roundTies += 1;
}
else if(playerThrow == global.ROCK and cpuThrow == global.SCISSORS or playerThrow == global.PAPER and cpuThrow == global.ROCK or playerThrow == global.SCISSORS and cpuThrow == global.PAPER)
{
    global.playerResultHistory = global.WIN + global.playerResultHistory;
    global.roundWins += 1;
    global.cpuResultHistory = global.LOSE + global.cpuResultHistory;
}
else
{
    global.playerResultHistory = global.LOSE + global.playerResultHistory;
    global.cpuResultHistory = global.WIN + global.cpuResultHistory;
    global.roundLosses += 1;
}

if(global.roundWins == global.numWinsNeeded)
{
    global.playerWin = 1;
    room_goto_next();
}
else if(global.roundLosses == global.numWinsNeeded)
{
    global.playerWin = 0;
    room_goto_next();
}
