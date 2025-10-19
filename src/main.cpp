#include <ncurses.h>

#include "board.h"

/**
 * @brief Gets user input.
 *
 * @return User string input(move).
 */
std::string get_user_move();

int main()
{
    initscr();
    Board board;
    board.display_board();

    for (int i = 0;; i++)
    {
        std::string move = get_user_move();
        Piece::Side side = (i % 2 == 0) ? Piece::Side::WHITE :
                                          Piece::Side::BLACK;

        board.make_move(move, side);
        board.display_board();
    }

    endwin();
    return 0;
}

std::string get_user_move()
{
    echo();

    int max_x = getmaxx(stdscr);
    int max_y = getmaxy(stdscr);

    int height = 3, width = 23, start_y = (max_y - height - 3),
        start_x = (max_x - width) / 2;
    WINDOW *win = newwin(height, width, start_y, start_x);
    box(win, 0, 0);
    refresh();

    char move[7];
    mvwgetstr(win, 1, 1, move);

    return move;
}
