/*
** EPITECH PROJECT, 2020
** ninja
** File description:
** manage the ninja
*/

#include "../../include/my_runner.h"

sfTexture *create_texture_run(int left, int top, int width, int height)
{
    sfIntRect area = {left, top, width, height};
    sfTexture *text = sfTexture_createFromFile("content/run.png", &area);

    return (text);
}

t_run create_run(t_run run, sfVM video)
{
    sfVector2f pos = {250, 2.36 * video.height / 3};

    run.Trun1 = create_texture_run(67 * 0, 0, 64, 64);
    run.Trun2 = create_texture_run(67 * 1, 0, 64, 64);
    run.Trun3 = create_texture_run(67 * 2, 0, 64, 64);
    run.Trun4 = create_texture_run(67 * 3, 0, 64, 64);
    run.Trun5 = create_texture_run(67 * 4, 0, 64, 64);
    run.Trun6 = create_texture_run(67 * 5, 0, 64, 64);
    run.Srun = sfSprite_create();
    run.scale.x = 2.5;
    run.scale.y = 2.5;
    sfSprite_setScale(run.Srun, run.scale);
    sfSprite_setPosition(run.Srun, pos);
    return (run);
}

sfRW *make_run(t_run *run, sfRW *game, sfVM video, int i)
{
    if (i == 0)
        sfSprite_setTexture(run->Srun, run->Trun1, 1);
    if (i == 5)
        sfSprite_setTexture(run->Srun, run->Trun2, 1);
    if (i == 10)
        sfSprite_setTexture(run->Srun, run->Trun3, 1);
    if (i == 15)
        sfSprite_setTexture(run->Srun, run->Trun4, 1);
    if (i == 20)
        sfSprite_setTexture(run->Srun, run->Trun5, 1);
    if (i == 25)
        sfSprite_setTexture(run->Srun, run->Trun6, 1);
    sfRenderWindow_drawSprite(game, run->Srun, NULL);
    return (game);
}

sfRW *replace_run(t_run *run, sfRW *game, sfVM video, int i)
{
    sfVector2f mov = {-3, 0};

    if (i == 0)
        sfSprite_setTexture(run->Srun, run->Trun1, 1);
    if (i == 5)
        sfSprite_setTexture(run->Srun, run->Trun2, 1);
    if (i == 10)
        sfSprite_setTexture(run->Srun, run->Trun3, 1);
    if (i == 15)
        sfSprite_setTexture(run->Srun, run->Trun4, 1);
    if (i == 20)
        sfSprite_setTexture(run->Srun, run->Trun5, 1);
    if (i == 25)
        sfSprite_setTexture(run->Srun, run->Trun6, 1);
    sfSprite_move(run->Srun, mov);
    sfRenderWindow_drawSprite(game, run->Srun, NULL);
    return (game);
}
