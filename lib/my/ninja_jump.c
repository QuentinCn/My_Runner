/*
** EPITECH PROJECT, 2020
** ninja
** File description:
** manage the ninja
*/

#include "../../include/my_runner.h"

sfTexture *create_texture_jump(int left, int top, int width, int height)
{
    sfSprite *sprite = sfSprite_create();
    sfIntRect area = {left, top, width, height};
    sfTexture *text = sfTexture_createFromFile("content/jump.png",
    &area);

    return (text);
}

t_jump create_jump(t_jump jump, sfVM video)
{
    jump.Sjump = sfSprite_create();
    jump.Tjump2 = create_texture_jump(58 * 1, 0, 55, 78);
    jump.Tjump3 = create_texture_jump(58 * 2, 0, 58, 55);
    jump.Tjump4 = create_texture_jump(58 * 3, 0, 58, 36);
    jump.Tjump5 = create_texture_jump(58 * 4, 0, 58, 57);
    jump.Tjump6 = create_texture_jump(58 * 5, 0, 58, 40);
    jump.Tjump7 = create_texture_jump(58 * 6, 0, 58, 54);
    jump.Tjump8 = create_texture_jump(58 * 7, 0, 58, 68);
    jump.scale.x = 2.5;
    jump.scale.y = 2.5;
    jump.pos.x = 250;
    jump.pos.y = 2.35 * video.height / 3;
    sfSprite_setScale(jump.Sjump, jump.scale);
    sfSprite_setPosition(jump.Sjump, jump.pos);
    return (jump);
}

void move_jump(t_jump *jump, int *j, int level)
{
    switch (level) {
    case 4:
        jump->pos.y = (*j < 17) ? jump->pos.y - 15: jump->pos.y + 14.15;
        jump->pos.x += 3;
        break;
    case 8:
        jump->pos.y = (*j < 17) ? jump->pos.y - 15: jump->pos.y + 14.15;
        jump->pos.x += 1.5;
        break;
    case 12:
        jump->pos.y = (*j < 17) ? jump->pos.y - 15: jump->pos.y + 14.15;
        jump->pos.x += 0.5;
        break;
    }
}

void make_jump(t_list *list, int level)
{
    if (list->j == 0)
        sfSprite_setTexture(list->jump.Sjump, list->jump.Tjump2, 1);
    if (list->j == 5)
        sfSprite_setTexture(list->jump.Sjump, list->jump.Tjump3, 1);
    if (list->j == 10)
        sfSprite_setTexture(list->jump.Sjump, list->jump.Tjump4, 1);
    if (list->j == 15)
        sfSprite_setTexture(list->jump.Sjump, list->jump.Tjump5, 1);
    if (list->j == 20)
        sfSprite_setTexture(list->jump.Sjump, list->jump.Tjump6, 1);
    if (list->j == 25)
        sfSprite_setTexture(list->jump.Sjump, list->jump.Tjump7, 1);
    if (list->j == 30)
        sfSprite_setTexture(list->jump.Sjump, list->jump.Tjump8, 1);
    move_jump(&list->jump, &list->j, level);
    sfSprite_setPosition(list->jump.Sjump, list->jump.pos);
    sfRenderWindow_drawSprite(list->game, list->jump.Sjump, NULL);
}
