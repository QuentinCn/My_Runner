/*
** EPITECH PROJECT, 2021
** level
** File description:
** find the level
*/

#include "../../include/my_runner.h"

static int do_in_loop(sfRW *level, sfText *easy, sfText *normal, sfText *hard)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(level, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(level);
    }
    if (check_clic(level, easy))
        return (4);
    else if (check_clic(level, normal))
        return (8);
    else if (check_clic(level, hard))
        return (12);
    return (0);
}

int find_level(sfRW *level)
{
    t_back back = create_back(back);
    sfVM video = {back.size.x * back.scale.x, back.size.y * back.scale.y, 32};
    sfText *easy = create_play_button(easy, video);
    sfText *normal = create_level_button(normal, video);
    sfText *hard = create_exit_button(hard, video);
    int result;

    sfText_setString(easy, "easy");
    sfText_setString(normal, "normal");
    sfText_setString(hard, "hard");
    while (sfRenderWindow_isOpen(level)) {
        result = do_in_loop(&*level, &*easy, &*normal, &*hard);
        sfRenderWindow_clear(level, sfTransparent);
        level = draw_back(&back, level, video, 6);
        level = draw_text(level, easy, normal, hard);
        sfRenderWindow_display(level);
        if (result != 0)
            return (result);
    }
    return (0);
}
