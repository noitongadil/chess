#include <fstream> // for getting input from file
#include <regex> // for input/move validation
#include <vector> // for vectors
#include <iostream> // cout
#include <ncurses.h>

#include "board.h"

void replaySystem();

std::vector<std::string> parseInput();

int countNewLines(const std::string *str);

void movesInVector(std::string moves_str, std::vector<std::string> &moves);

std::string get_user_move();

int main()
{
    replaySystem();
    return 0;
}

void replaySystem()
{
    Board board;
    board.print_board();
    for (int i = 0; ; i++)
    {
        std::string move = get_user_move();
        Piece::Side side = (i % 2 == 0) ? Piece::WHITE : Piece::BLACK;
        std::cout << std::endl;
        std::cout << "move: " << move << std::endl
                  << "move num: " << i + 1 << std::endl;

        board.pass_move(move, side);
        board.print_board();
    }
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

std::vector<std::string> parseInput()
{
    std::fstream game_file("game.txt");
    std::string moves_str;
    getline(game_file, moves_str);

    std::regex move_num("(\\d+\\.)");
    moves_str = std::regex_replace(moves_str, move_num, "\n");

    int size = countNewLines(&moves_str);

    std::vector<std::string> moves(size * 2, "");
    movesInVector(moves_str, moves);
    return moves;
}

int countNewLines(const std::string *moves_str)
{
    int count = 0;
    for (char c : *moves_str)
    {
        if (c == '\n')
        {
            count++;
        }
    }
    return count;
}

void movesInVector(std::string moves_str, std::vector<std::string> &moves)
{
    int move_num = 0;

    std::regex valid_move(
        "(([RNBKQ])?([a-h])?([1-8])?(x)?([a-h][1-8])(\\+|\\#)?)"
        "|((O-O)(-O)?)"
        "|(([a-h][1-8])(=)([RNBQ]))");
    for (int i = 0; i < moves_str.length(); i++)
    {
        if (moves_str[i] == '\n')
        {
            if (i == 0)
            {
                continue;
            }

            if (std::regex_match(moves[move_num], valid_move) == false)
            {
                fprintf(stderr, "invalid move\n");
            }

            move_num++;
        }
        else if (moves_str[i] == '\0')
        {
            return;
        }
        else if (moves_str[i] == ' ')
        {
            if (moves_str[i + 1] == '\n')
            {
                continue;
            }

            move_num++;
            continue;
        }
        else
        {
            moves[move_num] += moves_str[i];
        }
    }
}
