/*
** EPITECH PROJECT, 2021
** score
** File description:
** manage the player's score
*/

#include "../../include/my_runner.h"

t_score create_score(t_score score, sfVM video)
{
    sfFont *font = sfFont_createFromFile("content/Shaka_Pow.ttf");
    int size = 60;

    score.score_pos.x = video.width - size / 1.7;
    score.score_pos.y = 0;
    score.point = sfText_create();
    sfText_setString(score.point, "0");
    sfText_setFont(score.point, font);
    sfText_setCharacterSize(score.point, size);
    sfText_setPosition(score.point, score.score_pos);
    sfText_setColor(score.point, sfColor_fromRGB(0, 0, 0));
    score.counter = 0;
    score.len = 1;
    return (score);
}

sfText *create_high_score(t_score score, sfVM video)
{
    int fd = open("content/high_score", O_RDONLY);
    struct stat sb;
    char *buffer;
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("content/Shaka_Pow.ttf");
    int size = 0;

    stat("content/high_score", &sb);
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    size = read(fd, buffer, sb.st_size);
    buffer[size] = '\0';
    sfText_setString(text, buffer);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 60);
    sfText_setPosition(text, (sfVector2f) {video.width / 2 + 600, 100});
    sfText_setColor(text, sfColor_fromRGB(65, 0, 65));
    close(fd);
    return (text);
}

void modify_high_score(sfText *text, sfText *old)
{
    int fd = open("content/high_score", O_RDWR | O_CREAT, 755);

    if (my_getnbr(sfText_getString(text)) > my_getnbr(sfText_getString(old)))
        write(fd, sfText_getString(text), my_strlen(sfText_getString(text)));
    close(fd);
}

sfRW *display_score(t_list *list)
{
    sfText_setString(list->score.point, my_itoc(list->score.counter));
    if (list->i % 4 == 0)
        list->score.counter += 1;
    list->score.score_pos.x = list->video.width -
        my_strlen(my_itoc(list->score.counter)) * 34;
    sfText_setPosition(list->score.point, list->score.score_pos);
    sfRenderWindow_drawText(list->game, list->score.point, NULL);
    return (list->game);
}
