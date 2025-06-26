/*
** EPITECH PROJECT, 2023
** My_Sokoban
** File description:
** sokoban.h
*/

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>

#ifndef MY_SOKOBAN_SOKOBAN_H
    #define MY_SOKOBAN_SOKOBAN_H
    #define FAIL 84
    #define SUCCES 1

typedef struct coords_s {
    int x;
    int y;
} coords_t;

typedef struct game_s {
    char **map;
    int nb_row;
    int nb_col;
    coords_t player_pos;
    coords_t *coords_res;
    const char *pathname;

} game_t;

int gen_map_array(const char *path, game_t *game);
void map_free(game_t *game);

void set_coords_res(game_t *game);
void set_player_pos(game_t *game);

int gen_term(game_t *game);

int action_handler(game_t *game, coords_t movement);
void reset(game_t *game);
char *get_map(const char *pathname);

#endif //MY_SOKOBAN_SOKOBAN_H
