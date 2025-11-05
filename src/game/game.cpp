#include <cstdio>
#include <ncurses.h>
#include <stdio.h>
#include <regex>

#include "game.h"
#include "board.h"

void Game::play()
{
    for (int i = 0;; i++)
    {
        m_board.display_board();
        Piece::Side side = (i % 2 == 0) ? Piece::Side::WHITE :
                                          Piece::Side::BLACK;

        std::string move = get_user_input();
        if (m_board.make_move(move, side) != true)
        {
            fprintf(stderr, "move was not made\n");
        }
    }
}

std::string Game::get_user_input()
{
    echo();

    int max_x = getmaxx(stdscr);
    int max_y = getmaxy(stdscr);

    int height = 3;
    int width = 23;
    int start_y = (max_y / 2) - height + 5;
    int start_x = (max_x - width) / 2;

    WINDOW *win = newwin(height, width, start_y, start_x);
    box(win, 0, 0);
    refresh();

    char move[7];

    mvwgetstr(win, 1, 1, move);
    std::string stdmove = move;
    while (validate_move(stdmove) == false)
    {
        mvwgetstr(win, 1, 1, move);
        stdmove = move;
    }

    return move;
}

bool Game::validate_move(const std::string &move)
{
    std::regex valid_move(
        "(([RNBKQ])?([a-h])?([1-8])?(x)?([a-h][1-8])(\\+|\\#)?)"
        "|((O-O)(-O)?)"
        "|(([a-h][1-8])(=)([RNBQ]))");

    return std::regex_match(move, valid_move);
}
