/*
** EPITECH PROJECT, 2023
** My_Sokoban
** File description:
** map_handler.c
*/

#include "../include/sokoban.h"

static int row_runner(char **map, int nb_col, int i, char comp)
{
    for (int j = 0; j < nb_col; j++) {
        if (map[i][j] == comp) {
            return j;
        }
    }
    return (-1);
}

static unsigned int count_res(game_t *game)
{
    unsigned int count = 0;

    for (int i = 0; i < game->nb_row; i++) {
        if (row_runner(game->map, game->nb_col, i, 'O') != -1)
            count++;
    }
    return (count);
}

void set_coords_res(game_t *game)
{
    int len = count_res(game);
    int index = 0;
    int j;

    game->coords_res = malloc(sizeof(coords_t) * len + 1);
    for (int i = 0; i < game->nb_row; i++) {
        j = row_runner(game->map, game->nb_col, i, 'O');
        if (j >= 0) {
            game->coords_res[index].x = i;
            game->coords_res[index].y = j;
            index++;
        }
    }
    game->coords_res[len] = (coords_t){-1, -1};
}

void set_player_pos(game_t *game)
{
    int j;

    game->player_pos.x = -1;
    game->player_pos.y = -1;
    for (int i = 0; i < game->nb_row; i++) {
        j = row_runner(game->map, game->nb_col, i, 'P');
        if (j >= 0) {
            game->player_pos.x = i;
            game->player_pos.y = j;
            break;
        }
    }
}
