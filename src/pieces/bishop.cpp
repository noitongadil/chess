#include "board.h"
#include <string>
#include "bishop.h"

Bishop::Bishop(Board *board, Side side)
    : Piece(board, side, 'B')
{
}

std::vector<std::string> Bishop::get_moves(int8_t file, int8_t rank) const
{
    std::vector<std::string> moves;

    // up right
    for (int i = file; i < 8; i++)
    {
        for (int j = rank; j < 8; j++)
        {
            if (m_board->m_grid[i][j] != nullptr)
            {
                if (m_board->m_grid[i][j]->get_side() != m_side)
                {
                    std::string move = "B";
                    move += 'x';
                    move += i + 'a';
                    move += std::to_string(j + 1);
                    moves.push_back(move);
                    disambiguate(move, i, j, moves);
                }

                i = 9;
                j = 9;
                break;
            }

            std::string move = "B";
            move += i + 'a';
            move += std::to_string(j + 1);
            moves.push_back(move);
            disambiguate(move, i, j, moves);
        }
    }

    // up left
    for (int i = file; i >= 0; i--)
    {
        for (int j = rank; j < 8; j++)
        {
            if (m_board->m_grid[i][j] != nullptr)
            {
                if (m_board->m_grid[i][j]->get_side() != m_side)
                {
                    std::string move = "B";
                    move += 'x';
                    move += i + 'a';
                    move += std::to_string(j + 1);
                    moves.push_back(move);
                    disambiguate(move, i, j, moves);
                }

                i = -1;
                j = 9;
                break;
            }

            std::string move = "B";
            move += i + 'a';
            move += std::to_string(j + 1);
            moves.push_back(move);
            disambiguate(move, i, j, moves);
        }
    }

    // down right
    for (int i = file; i < 8; i++)
    {
        for (int j = rank; j >= 0; j--)
        {
            if (m_board->m_grid[i][j] != nullptr)
            {
                if (m_board->m_grid[i][j]->get_side() != m_side)
                {
                    std::string move = "B";
                    move += 'x';
                    move += i + 'a';
                    move += std::to_string(j + 1);
                    moves.push_back(move);
                    disambiguate(move, i, j, moves);
                }

                i = 9;
                j = -1;
                break;
            }

            std::string move = "B";
            move += i + 'a';
            move += std::to_string(j + 1);
            moves.push_back(move);
            disambiguate(move, i, j, moves);
        }
    }

    // down left
    for (int i = file; i >= 0; i--)
    {
        for (int j = rank; j >= 0; j--)
        {
            if (m_board->m_grid[i][j] != nullptr)
            {
                if (m_board->m_grid[i][j]->get_side() != m_side)
                {
                    std::string move = "B";
                    move += 'x';
                    move += i + 'a';
                    move += std::to_string(j + 1);
                    moves.push_back(move);
                    disambiguate(move, i, j, moves);
                }

                i = -1;
                j = -1;
                break;
            }

            std::string move = "B";
            move += i + 'a';
            move += std::to_string(j + 1);
            moves.push_back(move);
            disambiguate(move, i, j, moves);
        }
    }

    return moves;
}
