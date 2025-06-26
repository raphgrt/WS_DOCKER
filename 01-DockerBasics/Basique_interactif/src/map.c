/*
** EPITECH PROJECT, 2023
** My_Sokoban
** File description:
** map.c
*/

#include "../include/sokoban.h"

static size_t get_size_file(char const *pathname)
{
    struct stat file;
    int err = stat(pathname, &file);

    if (err == -1)
        exit(FAIL);
    return (file.st_size);
}

char *get_map(const char *pathname)
{
    char *map;
    int fd = open(pathname, O_RDONLY);
    size_t length = get_size_file(pathname);

    if (fd == -1)
        exit(84);
    map = malloc(sizeof(char) * length + 1);
    read(fd, map, length);
    close(fd);
    map[length] = '\0';
    return (map);
}

static void set_dimensions(game_t *game, char *file)
{
    game->nb_col = 1;
    game->nb_row = 1;
    for (int x = 0; file[x] != '\n'; x++)
        game->nb_col++;
    for (int x = 0; file[x]; x++) {
        if (file[x] == '\n')
            game->nb_row++;
    }
}

static void create_array(game_t *game)
{
    game->map = (char **)malloc(sizeof(char *) * game->nb_row);
    if (game->map == NULL)
        exit(84);
    for (int index = 0; index < game->nb_row; index++) {
        game->map[index] = (char *)malloc(sizeof(char) * game->nb_col);
        if (game->map[index] == NULL)
            exit(84);
    }
}

static void init_array(game_t *game, char *file)
{
    int x = 0;
    int y = 0;

    for (int index = 0; file[index]; index++) {
        if (file[index] == '\n') {
            x++;
            y = 0;
        } else {
            game->map[x][y] = file[index];
            y++;
        }
    }
}

int gen_map_array(const char *path, game_t *game)
{
    char *file = get_map(path);

    set_dimensions(game, file);
    create_array(game);
    init_array(game, file);
    free(file);
    return (0);
}

void map_free(game_t *game)
{
    for (int index = 0; index < game->nb_row; index++)
        free(game->map[index]);
    free(game->map);
}
