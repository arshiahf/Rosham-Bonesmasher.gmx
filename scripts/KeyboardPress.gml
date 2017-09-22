if(keyboard_check_pressed(buttonKey))
{
    global.playerHistory = throw + global.playerHistory;
    RPSReturn();
    CheckWin();
}
