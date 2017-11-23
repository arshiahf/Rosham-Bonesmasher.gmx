global.learningWins = 0;
global.patternWins = 0;
for(i = 0; i < 10000; i++)
{
    if(i % 20 == 0)
    {
        global.playerResultHistory = "";
        global.playerHistory = "";
        global.cpuResultHistory = "";
        global.cpuHistory = "";
    }
    CPUvsCPU();
}
show_message("Learning: " + string(global.learningWins) + ", Pattern: " + string(global.patternWins));

