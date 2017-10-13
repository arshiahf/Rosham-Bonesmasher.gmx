if instance_exists(rpsGeneric)
{
    for (i = 0; i < instance_number(rpsGeneric); i++)
    {
        with instance_find(rpsGeneric, i)
        {
            virtual_key_add(x - sprite_width / 2 - 1, y - sprite_height / 2 - 1, sprite_width - 2, sprite_height - 2, buttonKey)
        }
    }
}
