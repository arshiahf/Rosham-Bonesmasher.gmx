if(global.tieLast == 1)
{
    show_debug_message("You Tied");
    show_debug_message(global.playerHistory);
    show_debug_message(global.difficulty);
    exit;
}
else if(global.winLast == 0 and global.tieLast == 0)
{
    show_debug_message("You Won");
    show_debug_message(global.playerHistory);
    show_debug_message(global.difficulty);
    exit;
}
show_debug_message("You Lose");
show_debug_message(global.playerHistory);
show_debug_message(global.difficulty);
