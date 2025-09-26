#include <fstream> // for getting input from file
#include <regex> // for input/move validation
#include <vector> // for vectors
#include <iostream> // cout

#include "board.h"

void replaySystem();

std::vector<std::string> parseInput();

int countNewLines(const std::string *str);

void movesInVector(std::string moves_str, std::vector<std::string> &moves);

int main()
{
    replaySystem();
    return 0;
}

void replaySystem()
{
    std::vector<std::string> moves = parseInput();

    Board board;
    board.print_board();
    for (int i = 0; i < moves.size(); i++)
    {
        Piece::Side side = (i % 2 == 0) ? Piece::WHITE : Piece::BLACK;
        std::cout << std::endl;
        std::cout << "move: " << moves[i] << std::endl
                  << "move num: " << i + 1 << std::endl;

        board.pass_move(moves[i], side);
        board.print_board();
    }
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
