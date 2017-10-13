playerThrow = string_char_at(global.playerHistory, 1);
cpuThrow = string_char_at(global.cpuHistory, 1);

if(playerThrow == cpuThrow)
{
    global.resultHistory = global.TIE + global.resultHistory;
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
    global.resultHistory = global.WIN + global.resultHistory;
    show_debug_message(global.cpuHistory);
    show_debug_message(cpuThrow);
    show_debug_message("You Won");
    show_debug_message(playerThrow);
    show_debug_message(global.playerHistory);
    show_debug_message(global.difficulty);
    exit;
}
global.resultHistory = global.LOSE + global.resultHistory;
show_debug_message(global.cpuHistory);
show_debug_message(cpuThrow);
show_debug_message("You Lose");
show_debug_message(playerThrow);
show_debug_message(global.playerHistory);
show_debug_message(global.difficulty);
