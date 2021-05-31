/*
** EPITECH PROJECT, 2020
** shock
** File description:
** manage shock
*/

#include "../../include/my_runner.h"

static int check_for_jump(t_list list)
{
    sfIntRect jump_size = sfSprite_getTextureRect(list.jump.Sjump);
    sfVector2f jump_pos = sfSprite_getPosition(list.jump.Sjump);
    sfIntRect box_size = sfSprite_getTextureRect(list.box.Sbox);
    sfVector2f box_pos = sfSprite_getPosition(list.box.Sbox);

    jump_size.width *= sfSprite_getScale(list.jump.Sjump).x;
    jump_size.height *= sfSprite_getScale(list.jump.Sjump).y;
    jump_size.width -= 25;
    if ((jump_pos.x + jump_size.width >= box_pos.x && jump_pos.y +
    jump_size.height >= box_pos.y && jump_pos.x + jump_size.width <= box_pos.x +
    box_size.width) || (jump_pos.x >= box_pos.x && jump_pos.x <= box_pos.x +
    box_size.width && jump_pos.y + jump_size.height >= box_pos.y)) {
        do_explosion(list);
        return (1);
    }
    return (0);
}

static int check_for_run(t_list list)
{
    sfIntRect run_size = sfSprite_getTextureRect(list.run.Srun);
    sfVector2f run_pos = sfSprite_getPosition(list.run.Srun);
    sfIntRect box_size = sfSprite_getTextureRect(list.box.Sbox);
    sfVector2f box_pos = sfSprite_getPosition(list.box.Sbox);

    run_size.width *= sfSprite_getScale(list.run.Srun).x;
    run_size.width -= 25;
    run_size.height *= sfSprite_getScale(list.run.Srun).y;
    if ((run_pos.x + run_size.width >= box_pos.x && run_pos.y + run_size.height
        >= box_pos.y && run_pos.x <= box_pos.x + box_size.width) ||
        (run_pos.x >= box_pos.x && run_pos.x <= box_pos.x + box_size.width &&
            run_pos.y + run_size.height >= box_pos.y)) {
        do_explosion(list);
        return (1);
    }
    return (0);
}

int check_for_shock(t_list list)
{
    if ((sfKeyboard_isKeyPressed(sfKeySpace) &&
        sfSprite_getPosition(list.run.Srun).x <= 250) || list.j != 0) {
        if (check_for_jump(list) == 1)
            return (1);
    } else {
        if (check_for_run(list) == 1)
            return (1);
    }
    return (0);
}
