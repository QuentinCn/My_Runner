/*
** EPITECH PROJECT, 2020
** game
** File description:
** manage gameplay
*/

#include "../../include/my_runner.h"

static int verify_values(t_list *list, int *pos)
{
    if (list->k > pos[0] - 1 &&
        sfSprite_getPosition(list->box.Sbox).x < 0 &&
        sfSprite_getPosition(list->copy).x < 0 && pos[0] != -1) {
        if (list->j > 0)
            destroy_sound(&list->st_sound);
        return (1);
    }
    if (check_for_shock(*list) == 1) {
        if (list->j > 0)
            destroy_sound(&list->st_sound);
        return (1);
    }
    if (check_for_shock_with_copy(*list) == 1) {
        if (list->j > 0)
            destroy_sound(&list->st_sound);
        return (1);
    }
    return (0);
}

static void do_if_keyboard_is_pressed(t_list *list, int level)
{
    if (list->j == 0)
        list->st_sound = play_sound("content/fleche.ogg");
    if (list->j == 34) {
        destroy_sound(&list->st_sound);
    }
    make_jump(&*list, level);
    list->j = (list->j + 1 == 35) ? 0 : list->j + 1;
    sfSprite_setPosition(list->run.Srun,
                        sfSprite_getPosition(list->jump.Sjump));
}

static int do_in_loop(t_list *list, int *pos, int level)
{
    make_box(&*list, pos, level);
    make_copy(&*list, pos, level);
    if ((sfKeyboard_isKeyPressed(sfKeySpace) &&
        sfSprite_getPosition(list->run.Srun).x <= 250) || list->j != 0) {
        do_if_keyboard_is_pressed(&*list, level);
    } else if (sfSprite_getPosition(list->run.Srun).x > 250) {
        list->game = replace_run(&list->run, list->game, list->video, list->i);
        list->jump.pos.x = sfSprite_getPosition(list->run.Srun).x;
    } else {
        list->jump.pos.x = sfSprite_getPosition(list->run.Srun).x;
        list->game = make_run(&list->run, list->game, list->video, list->i);
    }
    list->i = (list->i + 1 == 30) ? 0 : list->i + 1;
    list->game = display_score(&(*list));
    sfRenderWindow_display(list->game);
    if (verify_values(&*list, pos) == 1)
        return (1);
    return (0);
}

static int do_loop(t_list *list, int *pos, int level)
{
    if (sfKeyboard_isKeyPressed(sfKeyP)) {
        while (sfKeyboard_isKeyPressed(sfKeyEscape) != 1) {
            sfRenderWindow_display(list->game);
        }
    }
    sfRenderWindow_clear(list->game, sfTransparent);
    list->game = draw_back(&list->back, list->game, list->video, level);
    do_in_loop(&*list, pos, level);
}

int gameplay(int *pos, int level, t_list *list)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(list->game)) {
        while (sfRenderWindow_pollEvent(list->game, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(list->game);
        }
        if (do_loop(&*list, pos, level) == 1) {
            if (loose(&*list) == 1)
                *list = create_list(*list, &*list->game);
            else if (loose(&*list) == 2) {
                level = find_level(list->game);
                *list = create_list(*list, &*list->game);
            } else
                return (1);
        }
    }
    sfRenderWindow_destroy(list->game);
    return (0);
}
