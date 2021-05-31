/*
** EPITECH PROJECT, 2021
** change_explosion_texture
** File description:
** change the explosion's texture
*/

#include "../../include/my_runner.h"

t_explosion change_text_1(t_explosion explosion, int i)
{
    switch (i) {
    case (0):
        sfSprite_setTexture(explosion.Sexplosion, explosion.T1, 1);
        return (explosion);
    case (7):
        sfSprite_setTexture(explosion.Sexplosion, explosion.T2, 1);
        return (explosion);
    case (14):
        sfSprite_setTexture(explosion.Sexplosion, explosion.T3, 1);
        return (explosion);
    case (21):
        sfSprite_setTexture(explosion.Sexplosion, explosion.T4, 1);
        return (explosion);
    case (28):
        sfSprite_setTexture(explosion.Sexplosion, explosion.T5, 1);
        return (explosion);
    }
}

t_explosion change_text_2(t_explosion explosion, int i)
{
    switch (i) {
    case (35):
        sfSprite_setTexture(explosion.Sexplosion, explosion.T6, 1);
        return (explosion);
    case (42):
        sfSprite_setTexture(explosion.Sexplosion, explosion.T7, 1);
        return (explosion);
    case (49):
        sfSprite_setTexture(explosion.Sexplosion, explosion.T8, 1);
        return (explosion);
    case (56):
        sfSprite_setTexture(explosion.Sexplosion, explosion.T9, 1);
        return (explosion);
    case (63):
        sfSprite_setTexture(explosion.Sexplosion, explosion.T10, 1);
        return (explosion);
    case (70):
        sfSprite_setTexture(explosion.Sexplosion, explosion.T11, 1);
        return (explosion);
    }
}
