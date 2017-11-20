if(file_exists(global.saveDir + global.playerName))
{
    playerFile = file_text_open_read(global.saveDir + global.playerName);
    global.playerHistory = file_text_read_string(playerFile);
    global.cpuHistory = file_text_read_string(playerFile);
    global.playerResultHistory = file_text_read_string(playerFile);
    global.cpuResultHistory = file_text_read_string(playerFile);
    file_text_close(playerFile);
}
