/*
** EPITECH PROJECT, 2021
** loose
** File description:
** manage with looses
*/

#include "../../include/my_runner.h"

sfRW *draw_back_static(t_back *back, sfRW *game, sfVM video)
{
    sfVector2f origin = {0, 0};

    sfRenderWindow_drawSprite(game, back->S4, NULL);
    sfRenderWindow_drawSprite(game, back->S3, NULL);
    sfRenderWindow_drawSprite(game, back->S2, NULL);
    sfRenderWindow_drawSprite(game, back->S1, NULL);
    return (game);
}

void draw_score(t_list *list)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("content/Shaka_Pow.ttf");

    sfText_setString(text, "score = ");
    sfText_setString(list->score.point, my_itoc(list->score.counter));
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 60);
    sfText_setPosition(text, (sfVector2f) {200, 100});
    sfText_setColor(text, sfColor_fromRGB(65, 0, 65));
    sfText_setPosition(list->score.point, (sfVector2f) {390, 100});
    sfText_setColor(list->score.point, sfColor_fromRGB(65, 0, 65));
    sfRenderWindow_drawText(list->game, text, NULL);
    sfRenderWindow_drawText(list->game, list->score.point, NULL);
}

void draw_high_score(t_list *list)
{
    sfText *text = sfText_create();
    sfText *text2 = create_high_score(list->score, list->video);
    sfFont *font = sfFont_createFromFile("content/Shaka_Pow.ttf");

    sfText_setString(text, "high score = ");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 60);
    sfText_setPosition(text, (sfVector2f) {list->video.width / 2  + 300, 100});
    sfText_setColor(text, sfColor_fromRGB(65, 0, 65));
    sfRenderWindow_drawText(list->game, text, NULL);
    sfRenderWindow_drawText(list->game, text2, NULL);
    modify_high_score(list->score.point, text2);
}

static void draw_all(t_list *list, sfText *play, sfText *level, sfText *exit)
{
    sfRenderWindow_clear(list->game, sfTransparent);
    list->game = draw_back_static(&list->back, list->game, list->video);
    draw_score(&*list);
    draw_high_score(&*list);
    list->game = draw_text(list->game, play, level, exit);
    sfRenderWindow_display(list->game);
}

int loose(t_list *list)
{
    sfText *play = create_play_button(play, list->video);
    sfText *level = create_level_button(level, list->video);
    sfText *exit = create_exit_button(exit, list->video);
    sfEvent event;

    while (sfRenderWindow_isOpen(list->game)) {
        while (sfRenderWindow_pollEvent(list->game, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(list->game);
        }
        if (check_clic(list->game, play))
            return (1);
        if (check_clic(list->game, level))
            return (2);
        else if (check_clic(list->game, exit))
            return (0);
        draw_all(&*list, &*play, &*level, &*exit);
    }
    sfRenderWindow_destroy(list->game);
    return (0);
}
