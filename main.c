/*
** EPITECH PROJECT, 2020
** main
** File description:
** main my_runner
*/

#include "include/my_runner.h"

void info_my_runner(void)
{
    my_putstr("Finite runner created with CSFML.\n\nUSAGE\n");
    my_putstr(" ./my_runner map.txt\n\n\nOPTIONS\n -i\t\tlaunch the game");
    my_putstr("in infinity mode.\n -h\t\tprint the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n SPACE_KEY\tjump.\n P_KEY\t\ttake a break.");
    my_putstr("\n ESCAPE_KEY\tstop the break.\n");
}

char *complete_buffer(char *buffer, int fd)
{
    int size;
    struct stat sb;

    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    size = read(fd, buffer, sb.st_size);
    buffer[size] = '\0';
    return (buffer);
}

int main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    char *buffer;

    if (handle_error(ac, av) == -1) {
        my_putstr("bad argument, retry with -h\n");
        return (84);
    }
    if (fd != -1) {
        buffer = complete_buffer(buffer, fd);
        my_runner(buffer);
    } else if (av[1][1] == 'i' && av[1][2] == '\0')
        my_runner("none");
    else if (av[1][1] == 'h' && av[1][2] == '\0')
        info_my_runner();
    else
        my_putstr("bad argument, retry with -h\n");
    free(buffer);
    close(fd);
    return (0);
}
