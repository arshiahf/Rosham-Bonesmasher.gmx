if(keyboard_check_pressed(buttonKey) and os_type != os_ios and os_type != os_android and os_type != os_winphone)
{
    sprite_index = pressedSprite;
    script_execute(buttonScript);
}
