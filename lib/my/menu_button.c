/*
** EPITECH PROJECT, 2020
** menu_button
** File description:
** manage menu's button
*/

#include "../../include/my_runner.h"

sfText *create_play_button(sfText *play, sfVideoMode video)
{
    sfFont *font = sfFont_createFromFile("content/Shaka_Pow.ttf");
    int size = video.width / 20;
    sfVector2f play_pos = {video.width / 2 - 1.5 * size, video.height /
    2 - 2 * size};

    play = sfText_create();
    sfText_setString(play, "PLAY");
    sfText_setFont(play, font);
    sfText_setCharacterSize(play, size);
    sfText_setPosition(play, play_pos);
    sfText_setColor(play, sfColor_fromRGB(65, 0, 0));
    return (play);
}

sfText *create_level_button(sfText *level, sfVideoMode video)
{
    sfFont *font = sfFont_createFromFile("content/Shaka_Pow.ttf");
    int size = video.width / 20;
    sfVector2f level_pos = {video.width / 2 - 1.6 * size, video.height / 2};

    level = sfText_create();
    sfText_setString(level, "LEVEL");
    sfText_setFont(level, font);
    sfText_setCharacterSize(level, size);
    sfText_setPosition(level, level_pos);
    sfText_setColor(level, sfColor_fromRGB(65, 0, 0));
    return (level);
}

sfText *create_exit_button(sfText *exit, sfVideoMode video)
{
    sfFont *font = sfFont_createFromFile("content/Shaka_Pow.ttf");
    int size = video.width / 20;
    sfVector2f exit_pos = {video.width / 2 - 1.5 * size,
    video.height / 2 + 2 * size};

    exit = sfText_create();
    sfText_setString(exit, "EXIT");
    sfText_setFont(exit, font);
    sfText_setCharacterSize(exit, size);
    sfText_setPosition(exit, exit_pos);
    sfText_setColor(exit, sfColor_fromRGB(65, 0, 0));
    return (exit);
}
