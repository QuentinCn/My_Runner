/*
** EPITECH PROJECT, 2021
** switch_my_runner
** File description:
** switch which is in my_runner
*/

#include "../../include/my_runner.h"

void do_case_1(int level, char *buffer, int *pos, t_list *list)
{
    if (!find_number_pos(buffer))
        gameplay((int[1]) {-1}, level, &*list);
    else
        gameplay(pos, level, &*list);
}

void do_case_2(int level, char *buffer, int *pos, t_list *list)
{
    if (!find_number_pos(buffer))
        gameplay((int[1]) {-1}, level, &*list);
    else
        gameplay(pos, level, &*list);
}

int do_switch_my_runner(int level, char *buffer, int *pos, t_list *list)
{
    switch (menu(&*list)) {
    case 1:
        do_case_1(level, buffer, pos, &*list);
        return (0);
    case 2:
        level = find_level(&*list->game);
        if (level == 0)
            return (0);
        do_case_2(level, buffer, pos, &*list);
        return (0);
    }
}
