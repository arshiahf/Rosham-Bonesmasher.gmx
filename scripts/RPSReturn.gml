compThrow = external_call(global.rpsReturn, global.difficulty, global.playerHistory, global.winLast, global.tieLast);
playerThrow = string_char_at(global.playerHistory, 1);

show_debug_message(compThrow);

if(compThrow == playerThrow)
{
    global.winLast = 0;
    global.tieLast = 1;
    exit;
}
else if((compThrow == global.ROCK and playerThrow == global.SCISSORS) or (compThrow == global.PAPER and playerThrow == global.ROCK) or (compThrow == global.SCISSORS and playerThrow == global.PAPER))
{
    global.winLast = 1;
    global.tieLast = 0;
    exit;
}

global.winLast = 0;
global.tieLast = 0;
