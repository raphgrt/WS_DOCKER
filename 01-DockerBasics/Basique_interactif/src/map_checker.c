/*
** EPITECH PROJECT, 2023
** My_Sokoban
** File description:
** map_checker.c
*/

#include "../include/sokoban.h"

static int check_char(char pos)
{
    return pos == 'X' || pos == '#' || pos == ' ' || pos == 'O' || pos == 'P';
}

int map_checker(game_t *game)
{
    int count_res = 0;

    for (int x = 0; x < game->nb_row; x++) {
        for (int y = 0; y < game->nb_col; y++) {
            if (!check_char(game->map[x][y]))
                return 1;
            if (game->map[x][y] == 'O')
                count_res++;
        }
    }
    if (count_res > 0)
        return 0;
    return 1;
}