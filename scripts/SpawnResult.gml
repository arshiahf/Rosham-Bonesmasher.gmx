lastResult = string_char_at(global.playerResultHistory, 0);
playerLast = string_char_at(global.playerHistory, 0);
cpuLast = string_char_at(global.cpuHistory, 0);
playerX = 128;
playerY = 192;
cpuX = 512;
cpuY = 192;
resultX = 320;
resultY = 192;

if(playerLast == global.ROCK)
{
    instancePlayerLast = instance_create(playerX, playerY, rockCuteShow);
}
else if(playerLast = global.PAPER)
{
    instancePlayerLast = instance_create(playerX, playerY, paperCuteShow);
}
else
{
    instancePlayerLast = instance_create(playerX, playerY, scissorsCuteShow);
}

if(cpuLast == global.ROCK)
{
    instanceCPULast = instance_create(cpuX, cpuY, rockCuteShow);
}
else if(cpuLast = global.PAPER)
{
    instanceCPULast = instance_create(cpuX, cpuY, paperCuteShow);
}
else
{
    instanceCPULast = instance_create(cpuX, cpuY, scissorsCuteShow);
}

if(lastResult == global.TIE)
{
    instanceResult = instance_create(resultX, resultY, throwTie0);
}
else if(lastResult == global.WIN)
{
    instanceResult = instance_create(resultX, resultY, throwWin0);
}
else
{
    instanceResult = instance_create(resultX, resultY, throwLose0);
}

with(instanceCPULast)
{
    alarm[0] = 30;
}

with(instancePlayerLast)
{
    alarm[0] = 30;
}

with(instanceResult)
{
    alarm[0] = 30;
}
