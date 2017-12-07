global.playerWins = 0;
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
    global.patternWins += 1;
}
else
{
    global.learningWins += 1;
}

