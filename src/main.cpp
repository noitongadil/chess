#include <ncurses.h>
#include <regex>

#include "board.h"

/**
 * @brief Gets user input.
 *
 * @return User string input(move).
 */
std::string get_user_move();

/**
 * @brief Checks if a move is valid or not.
 *
 * @param move Move to validate.
 * @return True if valid and false if not.
 */
bool validate_move(std::string &move);

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

        while (board.make_move(move, side) == false)
        {
            move = get_user_move();
        }

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

    int height = 3;
    int width = 23;
    int start_y = (max_y - height - 3);
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

bool validate_move(std::string &move)
{
    std::regex valid_move(
        "(([RNBKQ])?([a-h])?([1-8])?(x)?([a-h][1-8])(\\+|\\#)?)"
        "|((O-O)(-O)?)"
        "|(([a-h][1-8])(=)([RNBQ]))");

    return std::regex_match(move, valid_move);
}
