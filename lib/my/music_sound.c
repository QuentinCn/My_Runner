/*
** EPITECH PROJECT, 2021
** music_sound
** File description:
** play a music or a sound
*/

#include "../../include/my_runner.h"

t_sound play_sound(char *filename)
{
    t_sound st_sound;

    st_sound.buffer = sfSoundBuffer_createFromFile(filename);
    st_sound.sound = sfSound_create();
    sfSound_setBuffer(st_sound.sound, st_sound.buffer);
    sfSound_setVolume(st_sound.sound, 100);
    sfSound_play(st_sound.sound);
    return (st_sound);
}

void destroy_sound(t_sound *st_sound)
{
    sfSoundBuffer_destroy(st_sound->buffer);
    sfSound_destroy(st_sound->sound);
}

sfMusic *play_music(char *filename)
{
    sfMusic *music = sfMusic_createFromFile(filename);

    sfMusic_setVolume(music, 50);
    sfMusic_setLoop(music, 1);
    sfMusic_play(music);
    return (music);
}
