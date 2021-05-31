/*
** EPITECH PROJECT, 2020
** menu
** File description:
** manage menu
*/

#include "../../include/my_runner.h"

int check_clic(sfRenderWindow *menu, sfText *button)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(menu);
    sfVector2f button_pos = sfText_getPosition(button);
    unsigned int button_size = sfText_getCharacterSize(button);

    if (sfMouse_isButtonPressed(sfMouseLeft) == 0)
        return (0);
    if (mouse_pos.x < button_pos.x || mouse_pos.y < button_pos.y ||
    mouse_pos.x > button_pos.x + button_size * 2 || mouse_pos.y > button_pos.y
    + button_size)
        return (0);
    return (1);
}

sfRW *draw_text(sfRW *menu, sfText *play, sfText *level, sfText *exit)
{
    sfRenderWindow_drawText(menu, play, NULL);
    sfRenderWindow_drawText(menu, level, NULL);
    sfRenderWindow_drawText(menu, exit, NULL);
    return (menu);
}

int menu(t_list *list)
{
    sfEvent event;
    sfText *play = create_play_button(play, list->video);
    sfText *level = create_level_button(level, list->video);
    sfText *exit = create_exit_button(exit, list->video);

    while (sfRenderWindow_isOpen(list->game)) {
        while (sfRenderWindow_pollEvent(list->game, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(list->game);
        }
        if (check_clic(list->game, play)) {
            return (1);
        } else if (check_clic(list->game, level)) {
            return (2);
        } else if (check_clic(list->game, exit)) {
            sfRenderWindow_destroy(list->game);
            return (0);
        }
        sfRenderWindow_clear(list->game, sfTransparent);
        list->game = draw_back(&list->back, list->game, list->video, 6);
        list->game = draw_text(list->game, play, level, exit);
        sfRenderWindow_display(list->game);
    }
    sfRenderWindow_destroy(list->game);
    return (0);
}
