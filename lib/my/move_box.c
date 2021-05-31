/*
** EPITECH PROJECT, 2021
** move_box
** File description:
** allow to mmove the box and the copy
*/

#include "../../include/my_runner.h"

int find_place(t_list *list)
{
    float pos = -1;
    float pos_box = sfSprite_getPosition(list->copy).x;
    float size = sfSprite_getTextureRect(list->copy).width *
        sfSprite_getScale(list->copy).x;

    srand(time(NULL));
    while (pos > 1920 || pos < 0 || (pos + 1920 - pos_box < size * 4.5 && pos +
            1920 - pos_box > size * -4.5)) {
        pos = rand() % 1000;
    }
    return (pos + 1920);
}

int find_place_copy(t_list *list)
{
    float pos = -1;
    float pos_box = sfSprite_getPosition(list->box.Sbox).x;
    float size = sfSprite_getTextureRect(list->box.Sbox).width *
        sfSprite_getScale(list->box.Sbox).x;

    while (pos > 1920 || pos < 0 || (pos + 1920 - pos_box < size * 4.5 && pos +
            1920 - pos_box > size * -4.5)) {
        pos = rand() % 1000;
    }
    return (pos + 1920);
}

void make_box(t_list *list, int *pos, int level)
{
    sfVector2f origin;
    sfVector2f mov = {-1 * (level + 2), 0};

    if (pos[0] == -1) {
        origin.x = find_place(list);
        origin.y = 2.6 * list->video.height / 3;
    } else if (list->k <= pos[0]) {
        origin.x = pos[list->k] * 30;
        origin.y = 2.6 * list->video.height / 3;
    }
    sfRenderWindow_drawSprite(list->game, list->box.Sbox, NULL);
    sfSprite_move(list->box.Sbox, mov);
    if ((sfSprite_getPosition(list->box.Sbox).x < -72 || list->k == 1) &&
            (list->k <= pos[0] || pos[0] == -1)) {
        sfSprite_setPosition(list->box.Sbox, origin);
        list->k += 1;
    }
}

void make_copy(t_list *list, int *pos, int level)
{
    sfVector2f origin;
    sfVector2f mov = {-1 * (level + 2), 0};

    if (pos[0] == -1) {
        origin.x = find_place_copy(list);
        origin.y = 2.6 * list->video.height / 3;
    } else if (list->k <= pos[0]){
        origin.x = pos[list->k] * 30;
        origin.y = 2.6 * list->video.height / 3;
    }
    sfRenderWindow_drawSprite(list->game, list->copy, NULL);
    sfSprite_move(list->copy, mov);
    if ((sfSprite_getPosition(list->copy).x < -72 || list->k == 2) &&
        (list->k <= pos[0] || pos[0] == -1)) {
        sfSprite_setPosition(list->copy, origin);
        list->k += 1;
    }
}
