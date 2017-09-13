if instance_exists(rpsGeneric)
{
    for (i = 0; i < instance_number(rpsGeneric); i++)
    {
        with instance_find(rpsGeneric, i)
        {
            virtual_key_add(x, y, sprite_width, sprite_height, buttonKey)
        }
    }
}
