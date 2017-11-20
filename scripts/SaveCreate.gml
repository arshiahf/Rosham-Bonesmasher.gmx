if(global.playerName != "")
{
    playerFile = file_text_open_write(global.saveDir + global.playerName);
    
    file_text_write_string(playerFile, global.playerHistory);
    file_text_writeln(playerFile);
    file_text_write_string(playerFile, global.cpuHistory);
    file_text_writeln(playerFile);
    file_text_write_string(playerFile, global.playerResultHistory);
    file_text_writeln(playerFile);
    file_text_write_string(playerFile, global.cpuResultHistory);
    
    file_text_close(playerFile);
}
