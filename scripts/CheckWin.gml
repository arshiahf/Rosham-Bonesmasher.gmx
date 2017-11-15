playerThrow = string_char_at(global.playerHistory, 1);
cpuThrow = string_char_at(global.cpuHistory, 1);

if(playerThrow == cpuThrow)
{
    global.playerResultHistory = global.TIE + global.playerResultHistory;
    global.cpuResultHistory = global.TIE + global.cpuResultHistory;
    //show_debug_message(global.cpuHistory);
    //show_debug_message(cpuThrow);
    //show_debug_message("You Tied");
    //show_debug_message(playerThrow);
    //show_debug_message(global.playerHistory);
    //show_debug_message(global.difficulty);
    exit;
}
else if(playerThrow == global.ROCK and cpuThrow == global.SCISSORS or playerThrow == global.PAPER and cpuThrow == global.ROCK or playerThrow == global.SCISSORS and cpuThrow == global.PAPER)
{
    global.playerResultHistory = global.WIN + global.playerResultHistory;
    global.playerWins = global.playerWins + 1;
    global.cpuResultHistory = global.LOSE + global.cpuResultHistory;
    //show_debug_message(global.cpuHistory);
    //show_debug_message(cpuThrow);
    //show_debug_message("You Won");
    //show_debug_message(playerThrow);
    //show_debug_message(global.playerHistory);
    //show_debug_message(global.difficulty);
    exit;
}
global.playerResultHistory = global.LOSE + global.playerResultHistory;
global.cpuResultHistory = global.WIN + global.cpuResultHistory;
global.cpuWins = global.cpuWins + 1;
//show_debug_message(global.cpuHistory);
//show_debug_message(cpuThrow);
//show_debug_message("You Lose");
//show_debug_message(playerThrow);
//show_debug_message(global.playerHistory);
//show_debug_message(global.difficulty);
