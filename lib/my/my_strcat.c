/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** concate two string
*/

#include "../../include/my_runner.h"

char *my_strcat(char *str1, char const *str2)
{
    int len = my_strlen(str1);

    for (int i = 0; str2[i] != '\0'; i += 1, len += 1) {
        str1[len] = str2[i];
    }
    str1[len] = '\0';
    return (str1);
}
