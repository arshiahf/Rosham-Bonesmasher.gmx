if(keyboard_check_pressed(buttonKey) and os_type != os_ios and os_type != os_android and os_type != os_winphone)
{
    global.playerHistory = throw + global.playerHistory;
    RPSReturn();
    CheckWin();
}
