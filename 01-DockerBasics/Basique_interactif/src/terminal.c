/*
** EPITECH PROJECT, 2023
** My_Sokoban
** File description:
** terminal.c
*/

#include "../include/sokoban.h"

static void get_event(game_t *game, int event)
{
    switch (event) {
        case KEY_RIGHT:
            action_handler(game, (coords_t) {0, 1});
            return;
        case KEY_LEFT:
            action_handler(game, (coords_t) {0, -1});
            return;
        case KEY_UP:
            action_handler(game, (coords_t) {-1, 0});
            return;
        case KEY_DOWN:
            action_handler(game, (coords_t) {1, 0});
            return;
        case ' ':
            reset(game);
    }
}

static void print_map(game_t *game)
{
    int row;
    int col;
    int dim1;
    int dim2;

    getmaxyx(stdscr, row, col);
    dim1 = (row - game->nb_row) / 2;
    dim2 = (col - game->nb_col) / 2;
    if (row < game->nb_row || col < game->nb_col) {
        mvprintw(row / 2, dim2, "enlarge the terminal");
    } else {
        for (int x = 0; x < game->nb_row; x++) {
            mvprintw(dim1 + x, dim2, game->map[x]);
        }
    }
}

static int is_finish(game_t *game)
{
    for (int x = 0; game->coords_res[x].x != -1; x++) {
        if (game->coords_res[x].x > 0 && game->coords_res[x].y > 0)
            return 0;
    }
    clear();
    print_map(game);
    return (1);
}

static void loop(game_t *game)
{
    int code;

    refresh();
    while (1) {
        code = getch();
        clear();
        if (is_finish(game))
            break;
        get_event(game, code);
        print_map(game);
        refresh();
    }
    endwin();
}

int gen_term(game_t *game)
{
    WINDOW *window = initscr();

    noecho();
    curs_set(FALSE);
    keypad(window, TRUE);
    loop(game);
    return (0);
}
