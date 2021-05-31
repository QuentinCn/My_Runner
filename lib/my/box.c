/*
** EPITECH PROJECT, 2020
** box
** File description:
** manage box obstacle
*/

#include "../../include/my_runner.h"

sfTexture *create_texture_box(int left, int top, int width, int height)
{
    sfSprite *sprite = sfSprite_create();
    sfIntRect area = {left, top, width, height};
    sfTexture *text = sfTexture_createFromFile("content/box.png", &area);

    return (text);
}

t_box create_box(t_box box, sfVM video)
{
    sfVector2f pos = {video.width, 2.55 * video.height / 3};

    box.Tbox1 = create_texture_box(27, 47, 69, 67);
    box.Sbox = sfSprite_create();
    box.scale.x = 1.4;
    box.scale.y = 1.4;
    box.size.x = 69;
    box.size.y = 67;
    sfSprite_setScale(box.Sbox, box.scale);
    sfSprite_setPosition(box.Sbox, pos);
    sfSprite_setTexture(box.Sbox, box.Tbox1, 1);
    return (box);
}
