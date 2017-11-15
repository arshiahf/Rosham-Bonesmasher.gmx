//global.playerResultHistory = "";
//global.playerHistory = "";
global.playerWins = 0;
//global.cpuResultHistory = "";
//global.cpuHistory = "";
global.cpuWins = 0;
numRounds = global.cpuvscpuRounds;

rand = random(101);
if(rand < 37)
{
    global.playerHistory = global.ROCK
}
else if(rand < 71)
{
    global.playerHistory = global.PAPER
}
else
{
    global.playerHistory = global.SCISSORS
}

while(global.cpuWins < global.cpuvscpuRounds and global.playerWins < global.cpuvscpuRounds)
{
    PlayerRPSReturn();
    CheckWin();
    CPURPSReturn();
    CheckWin();
}

if(global.playerWins > global.cpuWins)
{
    global.patternWins = global.patternWins + 1;
    //show_debug_message("Pattern wins");
}
else
{
    global.learningWins = global.learningWins + 1;
    //show_debug_message("Learning wins");
}
//show_debug_message("Learning: " + string(global.learningWins) + ", Pattern: " + string(global.patternWins));

