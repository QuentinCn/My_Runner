/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** game my runner
*/

#include "include/my_runner.h"

int find_number_pos(char *buffer)
{
    int k = 0;
    int i = 0;
    int j = 0;

    for (; buffer[i] != '2' && buffer[i] != '\0'; i += 1);
    for (; buffer[i] != '\n' && buffer[i] != '\0'; i -= 1);
    i += 1;
    for (; buffer[j + i] != '\n' && buffer[i] != '\0'; j += 1) {
        if (buffer[i + j] == '2') {
            k += 1;
            j += 1;
        }
    }
    return (k);
}

int *find_box_pos(int *pos, char *buffer)
{
    int k = 1;
    int i = 0;
    int j = 0;

    for (; buffer[i] != '2' && buffer[i] != '\0'; i += 1);
    for (; buffer[i] != '\n' && buffer[i] != '\0'; i -= 1);
    i += 1;
    for (; buffer[j + i] != '\n' && buffer[i] != '\0'; j += 1) {
        if (buffer[i + j] == '2') {
            pos[k] = j;
            k += 1;
            j += 1;
        }
    }
    return (pos);
}

int my_runner(char *buffer)
{
    int *pos = malloc(sizeof(int) * (find_number_pos(buffer) + 1));
    int level = 8;
    t_back back = create_back(back);
    sfVM video = {back.size.x * back.scale.x, back.size.y * back.scale.y, 32};
    sfRW *game = sfRenderWindow_create(video, "Game", sfClose, NULL);
    t_list list = create_list(list, &*game);
    sfMusic *music = play_music("content/game_music.ogg");

    pos[0] = find_number_pos(buffer);
    pos = find_box_pos(pos, buffer);
    if (do_switch_my_runner(level, buffer, pos, &list) == 0)
        sfMusic_destroy(music);
}
