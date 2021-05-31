/*
** EPITECH PROJECT, 2020
** explosion
** File description:
** manage explosion
*/

#include "../../include/my_runner.h"

sfTexture *create_texture_explosion(int left, int top, int width, int height)
{
    sfSprite *sprite = sfSprite_create();
    sfIntRect area = {left, top, width, height};
    sfTexture *text = sfTexture_createFromFile("content/box.png", &area);

    return (text);
}

t_explosion create_explosion(t_explosion explosion, sfVM video, t_list *list)
{
    sfVector2f pos = sfSprite_getPosition(list->box.Sbox);

    explosion.T1 = create_texture_explosion(125 * 1, 166 * 0, 125, 166);
    explosion.T2 = create_texture_explosion(125 * 2, 166 * 0, 125, 166);
    explosion.T3 = create_texture_explosion(125 * 3, 166 * 0, 125, 166);
    explosion.T4 = create_texture_explosion(125 * 0, 166 * 1, 125, 166);
    explosion.T5 = create_texture_explosion(125 * 1, 166 * 1, 125, 166);
    explosion.T6 = create_texture_explosion(125 * 2, 166 * 1, 125, 166);
    explosion.T7 = create_texture_explosion(125 * 3, 166 * 1, 125, 166);
    explosion.T8 = create_texture_explosion(125 * 0.2, 166 * 2, 125, 166);
    explosion.T9 = create_texture_explosion(125 * 1.2, 166 * 2, 125, 166);
    explosion.T10 = create_texture_explosion(125 * 2.2, 166 * 2, 125, 166);
    explosion.T11 = create_texture_explosion(125 * 3.2, 166 * 2, 125, 166);
    explosion.Sexplosion = sfSprite_create();
    explosion.scale.x = 1.2;
    explosion.scale.y = 1.2;
    sfSprite_setScale(explosion.Sexplosion, explosion.scale);
    sfSprite_setPosition(explosion.Sexplosion, pos);
    return (explosion);
}

void do_explosion(t_list list)
{
    t_explosion explo = create_explosion(explo, list.video, &list);
    sfIntRect area = {60, 295, 65, 67};
    sfTexture *texture = sfTexture_createFromFile("content/ninja.png", &area);
    t_sound st_sound = play_sound("content/explosion2.ogg");

    sfSprite_setTexture(list.run.Srun, texture, 1);
    sfSprite_setPosition(explo.Sexplosion, sfSprite_getPosition(list.box.Sbox));
    for (int i = 0; i < 75; i += 1) {
        sfRenderWindow_clear(list.game, sfTransparent);
        sfSprite_rotate(list.run.Srun, -2);
        explo = change_text_1(explo, i);
        explo = change_text_2(explo, i);
        list.game = draw_back_static(&list.back, list.game, list.video);
        sfRenderWindow_drawSprite(list.game, explo.Sexplosion, NULL);
        sfRenderWindow_drawSprite(list.game, list.run.Srun, NULL);
        sfRenderWindow_drawText(list.game, list.score.point, NULL);
        sfSprite_move(list.run.Srun, (sfVector2f) {-12, -1});
        sfRenderWindow_display(list.game);
    }
    destroy_sound(&st_sound);
}

void do_explosion_with_copy(t_list list)
{
    t_explosion explosion = create_explosion(explosion, list.video, &list);
    sfIntRect area = {60, 295, 65, 67};
    sfTexture *texture = sfTexture_createFromFile("content/ninja.png", &area);
    t_sound st_sound = play_sound("content/explosion2.ogg");

    sfSprite_setTexture(list.run.Srun, texture, 1);
    sfSprite_setPosition(explosion.Sexplosion, sfSprite_getPosition(list.copy));
    for (int i = 0; i < 75; i += 1) {
        sfRenderWindow_clear(list.game, sfTransparent);
        sfSprite_rotate(list.run.Srun, -2);
        explosion = change_text_1(explosion, i);
        explosion = change_text_2(explosion, i);
        list.game = draw_back_static(&list.back, list.game, list.video);
        sfRenderWindow_drawSprite(list.game, explosion.Sexplosion, NULL);
        sfRenderWindow_drawSprite(list.game, list.run.Srun, NULL);
        sfRenderWindow_drawText(list.game, list.score.point, NULL);
        sfSprite_move(list.run.Srun, (sfVector2f) {-12, -1});
        sfRenderWindow_display(list.game);
    }
    destroy_sound(&st_sound);
}
