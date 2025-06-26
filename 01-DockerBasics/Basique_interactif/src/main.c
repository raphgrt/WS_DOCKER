/*
** EPITECH PROJECT, 2023
** My_Sokoban
** File description:
** main.c
*/

#include "../include/sokoban.h"

static void helper(void)
{
    char *help = get_map("help");

    write(1, help, 194);
    free(help);
}

void reset(game_t *game)
{
    map_free(game);
    free(game->coords_res);
    gen_map_array(game->pathname, game);
    set_player_pos(game);
    set_coords_res(game);
}

static void game(const char *pathname)
{
    game_t game;

    game.pathname = pathname;
    gen_map_array(pathname, &game);
    set_player_pos(&game);
    set_coords_res(&game);
    gen_term(&game);
    map_free(&game);
    free(game.coords_res);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (FAIL);
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        helper();
        return (0);
    } else {
        game(argv[1]);
    }
    return (0);
}
