#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <regex>
#include <sstream>
#include <ncurses.h>
#include <string.h>

#include "replay.h"

/**
 * @brief Count how many new lines are in the string @p moves_str.
 *
 * @param moves_str A reference to the string containing all moves of the game.
 * @return The number of new lines in the PGN txt file.
 */
int count_new_lines(const std::string &moves_str);

/**
 * @brief Accepts user input.
 */
inline char io_helper();

void Replay::play()
{
    Board board;

    std::vector<std::string> moves = get_user_input();
    int num_moves = moves.size();
    m_states = new Board[num_moves + 1];

    for (int i = 0; i < num_moves; i++)
    {
        m_states[i] = board;
        Piece::Side side = (i % 2 == 0) ? Piece::Side::WHITE :
                                          Piece::Side::BLACK;

        if (board.make_move(moves[i], side) != true)
        {
            fprintf(stderr, "move %s was not made\n", moves[i].c_str());
        }
    }

    int max_x = getmaxx(stdscr);
    int max_y = getmaxy(stdscr);

    int height = 3;
    int width = 40;
    int start_y = (max_y / 2) - height + 8;
    int start_x = (max_x - width) / 2;

    int user_input = 0;
    int curr_state = 0;

    while (curr_state >= 0 && curr_state < num_moves)
    {
        m_states[curr_state].display_board();
        user_input = io_helper();

        switch (user_input)
        {
        case 'n':
            curr_state++;
            break;
        case 'p':
            curr_state--;
            break;
        case 'q':
            curr_state = -1;
            break;
        default:
            mvprintw(start_y, start_x,
                     "valid options are: (n)ext, (p)rev, (q)uit.");
            break;
        }
    }

    delete[] m_states;
}

std::vector<std::string> Replay::get_user_input()
{
    // getting the PGN
    std::fstream game_file("game.txt");
    std::string moves_str;
    getline(game_file, moves_str);

    // regex is a digit followed by a literal dot
    std::regex move_num("(\\d+\\.)");
    moves_str = std::regex_replace(moves_str, move_num, "\n");

    std::vector<std::string> moves = vector_moves(moves_str);
    return moves;
}

std::vector<std::string> Replay::vector_moves(const std::string &moves_str)
{
    std::vector<std::string> moves;
    int num_lines = count_new_lines(moves_str);
    moves.reserve(num_lines * 2);

    std::stringstream ss(moves_str);
    std::string move;

    while (ss >> move)
    {
        if (validate_move(move) == false)
        {
            fprintf(stderr, "invalid move detected in file: %s\n",
                    move.c_str());
        }
        else
        {
            moves.emplace_back(move);
        }
    }

    return moves;
}

inline char io_helper()
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

    char choice[10];
    mvwgetstr(win, 1, 1, choice);

    return *(char *)choice;
}

inline int count_new_lines(const std::string &moves_str)
{
    int count = 0;
    for (char c : moves_str)
    {
        if (c == '\n')
        {
            count++;
        }
    }

    return count;
}
