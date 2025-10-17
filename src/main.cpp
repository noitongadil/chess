#include <fstream> // for getting input from file
#include <regex> // for input/move validation
#include <vector> // for vectors
#include <iostream> // cout
#include <ncurses.h>

#include "board.h"

std::string get_user_move();

int main()
{
    Board board;
    board.display_board();

    for (int i = 0;; i++)
    {
        std::string move = get_user_move();
        Piece::Side side = (i % 2 == 0) ? Piece::WHITE : Piece::BLACK;
        std::cout << std::endl;
        std::cout << "move: " << move << std::endl
                  << "move num: " << i + 1 << std::endl;

        board.make_move(move, side);
        board.display_board();
    }

    return 0;
}

std::string get_user_move()
{
    initscr();
    echo();

    int max_x = getmaxx(stdscr);
    int max_y = getmaxy(stdscr);

    int height = 3, width = 23, start_y = (max_y - height - 3),
        start_x = (max_x - width) / 2;
    WINDOW *win = newwin(height, width, start_y, start_x);
    box(win, 0, 0);
    refresh();

    char move[10];
    mvwgetstr(win, 1, 1, move);

    endwin();
    return move;
}
