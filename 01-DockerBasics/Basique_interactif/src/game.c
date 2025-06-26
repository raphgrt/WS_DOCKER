/*
** EPITECH PROJECT, 2023
** My_Sokoban
** File description:
** game.c
*/

#include "../include/sokoban.h"

static void keep_o(char **map, coords_t *coords)
{
    for (int x = 0; coords[x].x != -1; x++) {
        if (coords[x].x > 0 && coords[x].y > 0 &&
            map[coords[x].x][coords[x].y] != 'P')
            map[coords[x].x][coords[x].y] = 'O';
    }
}

static void set_res(coords_t *coords, coords_t coord)
{
    for (int x = 0; coords[x].x != -1; x++)
        if (coords[x].x == coord.x && coords[x].y == coord.y) {
            coords[x].x = -2;
            coords[x].y = -2;
        }
}

static void box_movement(game_t *game, coords_t box_pos, coords_t direction)
{
    coords_t new_box;

    new_box.x = box_pos.x + direction.x;
    new_box.y = box_pos.y + direction.y;
    if (game->map[new_box.x][new_box.y] == 'O')
        set_res(game->coords_res, new_box);
    if (game->map[new_box.x][new_box.y] != '#' &&
        game->map[new_box.x][new_box.y] != 'X') {
        game->map[box_pos.x][box_pos.y] = 'P';
        game->map[new_box.x][new_box.y] = 'X';
    }
}

static void player_movement(char **map, coords_t *p_pos, coords_t new_place)
{
    if (map[new_place.x][new_place.y] != '#' &&
        map[new_place.x][new_place.y] != 'X') {
        map[p_pos->x][p_pos->y] = ' ';
        p_pos->x = new_place.x;
        p_pos->y = new_place.y;
        map[new_place.x][new_place.y] = 'P';
    }
}

int action_handler(game_t *game, coords_t movement)
{
    coords_t new_place;

    new_place.x = game->player_pos.x + movement.x;
    new_place.y = game->player_pos.y + movement.y;
    if (game->map[new_place.x][new_place.y] == 'X')
        box_movement(game, new_place, movement);
    player_movement(game->map, &game->player_pos, new_place);
    keep_o(game->map, game->coords_res);
    return (0);
}
