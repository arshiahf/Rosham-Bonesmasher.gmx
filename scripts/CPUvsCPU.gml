numRounds = argument1;

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

for(i = 0; i < numRounds; i++)
{
    PlayerRPSReturn();
    CheckWin();
    CPURPSReturn();
    CheckWin();
}
