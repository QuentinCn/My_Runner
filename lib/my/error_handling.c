/*
** EPITECH PROJECT, 2021
** error_handling
** File description:
** handle error
*/

#include "../../include/my_runner.h"

int check_file(char **av, int fd)
{
    char *buffer;
    struct stat sb;
    int size = 0;

    stat(av[1], &sb);
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    size = read(fd, buffer, sb.st_size);
    buffer[size] = '\0';
    for (int i = 0; buffer[i] != '\0'; i += 1) {
        if (buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != '\0' &&
            buffer[i] != '2' && buffer[i] != '1') {
            free(buffer);
            return (-1);
        }
    }
}

int handle_error(int ac, char **av)
{
    int fd;

    if (ac != 2)
        return (-1);
    if (av[1][0] == '-') {
        if (av[1][1] != 'h' && av[1][1] != 'i')
            return (-1);
    } else {
        fd = open(av[1], O_RDONLY);
        if (fd == -1)
            return (-1);
        if (check_file(av, fd) == -1)
            return (-1);
    }
    return (0);
}
