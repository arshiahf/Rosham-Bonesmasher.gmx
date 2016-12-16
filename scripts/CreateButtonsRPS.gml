var xLoc = room_width 
var yLoc = room_height 
var buttonSize = room_height / 5

{
    for (i = 0; i < instance_number(rpsGeneric); i++)
    {
        button[i] = instance_find(rpsGeneric, i)
    }
}

for (i = 0; i < array_length_1d(button); i++)
{
    virtual_key_add(button[i].x, button[i].y, sprite_width, sprite_height, button[i].buttonKey)
}
