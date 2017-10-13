if(global.lastResult == global.TIE)
{
    instance = instance_create(x, y, throwTie0);
}
else if(global.lastResult == global.WIN)
{
    instance = instance_create(x, y, throwWin0);    
}
else
{
    instance = instance_create(x, y, throwLose0);    
}

with(instance)
{
    alarm[0] = 1;
}
