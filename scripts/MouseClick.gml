if(mouseOver)
{
    sprite_index = pressedSprite;
    global.playerHistory = throw + global.playerHistory;
    PlayerRPSReturn();
    CheckWin();
    SpawnResult();
}
