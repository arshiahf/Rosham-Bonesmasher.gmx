lastResult = string_char_at(global.playerResultHistory, 1);

show_debug_message("Last result is: " + lastResult);

if(lastResult == global.TIE)
{
    instance = instance_create(x, y, throwTie0);
}
else if(lastResult == global.WIN)
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
