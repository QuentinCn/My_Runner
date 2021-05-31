/*
** EPITECH PROJECT, 2020
** back
** File description:
** manage with the back
*/

#include "../../include/my_runner.h"

sfSprite *create_sprite(sfSprite *sprite, sfTexture *texture, sfVector2f scale)
{
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, 1);
    sfSprite_setScale(sprite, scale);
}

t_back create_back(t_back back)
{
    back.T1 = sfTexture_createFromFile("content/1.png", NULL);
    back.T2 = sfTexture_createFromFile("content/2.png", NULL);
    back.T3 = sfTexture_createFromFile("content/3.png", NULL);
    back.T4 = sfTexture_createFromFile("content/4.png", NULL);
    back.scale.x = 0.9;
    back.scale.y = 0.9;
    back.size = sfTexture_getSize(back.T3);
    back.size.x /= 2;
    back.S1 = create_sprite(back.S1, back.T1, back.scale);
    back.S2 = create_sprite(back.S2, back.T2, back.scale);
    back.S3 = create_sprite(back.S3, back.T3, back.scale);
    back.S4 = create_sprite(back.S4, back.T4, back.scale);
    return (back);
}

sfRW *draw_back(t_back *back, sfRW *game, sfVM video, int level)
{
    sfVector2f origin = {0, 0};

    sfRenderWindow_drawSprite(game, back->S4, NULL);
    sfRenderWindow_drawSprite(game, back->S3, NULL);
    sfSprite_move(back->S3, (sfVector2f) {-1 * (level - 3), 0});
    if (sfSprite_getPosition(back->S3).x + back->size.x * 2 * back->scale.x <
        video.width)
        sfSprite_setPosition(back->S3, origin);
    sfRenderWindow_drawSprite(game, back->S2, NULL);
    sfSprite_move(back->S2, (sfVector2f) {-1 * level, 0});
    if (sfSprite_getPosition(back->S2).x + back->size.x * 2 * back->scale.x <
        video.width)
        sfSprite_setPosition(back->S2, origin);
    sfRenderWindow_drawSprite(game, back->S1, NULL);
    sfSprite_move(back->S1, (sfVector2f) {-1 * (level + 2), 0});
    if (sfSprite_getPosition(back->S1).x + back->size.x * 2 * back->scale.x <
        video.width)
        sfSprite_setPosition(back->S1, origin);
    return (game);
}
