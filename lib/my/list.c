/*
** EPITECH PROJECT, 2021
** list
** File description:
** create the list of usefull variable
*/

#include "../../include/my_runner.h"

void create_list2(t_list *list, sfVM video)
{
    t_jump jump = create_jump(jump, video);
    t_box box = create_box(box, video);
    t_score score = create_score(score, video);
    sfSprite *copy = sfSprite_copy(box.Sbox);

    list->jump = jump;
    list->box = box;
    list->score = score;
    list->copy = copy;
}

t_list create_list(t_list list, sfRW *game)
{
    t_back back = create_back(back);
    sfVM video = {back.size.x * back.scale.x, back.size.y * back.scale.y, 32};
    t_run run = create_run(run, video);

    list.back = back;
    list.video = video;
    list.game = game;
    list.run = run;
    create_list2(&list, video);
    list.i = 0;
    list.j = 0;
    list.k = 1;
    list.check_copy = 0;
    sfRenderWindow_setFramerateLimit(list.game, 60);
    return (list);
}
