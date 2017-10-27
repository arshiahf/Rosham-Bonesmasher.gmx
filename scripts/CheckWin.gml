playerThrow = string_char_at(global.playerHistory, 1);
cpuThrow = string_char_at(global.cpuHistory, 1);

if(playerThrow == cpuThrow)
{
    global.playerResultHistory = global.TIE + global.resultHistory;
    global.cpuResultHistory = global.TIE + global.resultHistory;
    show_debug_message(global.cpuHistory);
    show_debug_message(cpuThrow);
    show_debug_message("You Tied");
    show_debug_message(playerThrow);
    show_debug_message(global.playerHistory);
    show_debug_message(global.difficulty);
    exit;
}
else if(playerThrow == global.ROCK and cpuThrow == global.SCISSORS or playerThrow == global.PAPER and cpuThrow == global.ROCK or playerThrow == global.SCISSORS and cpuThrow == global.PAPER)
{
    global.playerResultHistory = global.WIN + global.resultHistory;
    global.cpuResultHistory = global.LOSE + global.resultHistory;
    show_debug_message(global.cpuHistory);
    show_debug_message(cpuThrow);
    show_debug_message("You Won");
    show_debug_message(playerThrow);
    show_debug_message(global.playerHistory);
    show_debug_message(global.difficulty);
    exit;
}
global.playerResultHistory = global.LOSE + global.resultHistory;
global.cpuResultHistory = global.WIN + global.resultHistory;
show_debug_message(global.cpuHistory);
show_debug_message(cpuThrow);
show_debug_message("You Lose");
show_debug_message(playerThrow);
show_debug_message(global.playerHistory);
show_debug_message(global.difficulty);
