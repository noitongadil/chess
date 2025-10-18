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
    moves.reserve(18);
    std::string move;

    // up right
    for (int i = file + 1; i < 8; i++)
    {
        for (int j = rank + 1; j < 8; j++)
        {
            move = "B";
            move += i + 'a';
            move += std::to_string(j + 1);

            if (m_board->m_grid[i][j] != nullptr)
            {
                if (m_board->m_grid[i][j]->get_side() != m_side)
                {
                    move.insert(1, 1, 'x');
                    moves.emplace_back(move);
                    disambiguate(move, i, j, moves);
                }

                i = 9;
                j = 9;
                break;
            }

            moves.emplace_back(move);
            disambiguate(move, i, j, moves);
        }
    }

    // up left
    for (int i = file - 1; i >= 0; i--)
    {
        for (int j = rank + 1; j < 8; j++)
        {
            move = "B";
            move += i + 'a';
            move += std::to_string(j + 1);

            if (m_board->m_grid[i][j] != nullptr)
            {
                if (m_board->m_grid[i][j]->get_side() != m_side)
                {
                    move.insert(1, 1, 'x');
                    moves.emplace_back(move);
                    disambiguate(move, i, j, moves);
                }

                i = -1;
                j = 9;
                break;
            }

            moves.emplace_back(move);
            disambiguate(move, i, j, moves);
        }
    }

    // down right
    for (int i = file + 1; i < 8; i++)
    {
        for (int j = rank - 1; j >= 0; j--)
        {
            move = "B";
            move += i + 'a';
            move += std::to_string(j + 1);

            if (m_board->m_grid[i][j] != nullptr)
            {
                if (m_board->m_grid[i][j]->get_side() != m_side)
                {
                    move.insert(1, 1, 'x');
                    moves.emplace_back(move);
                    disambiguate(move, i, j, moves);
                }

                i = 9;
                j = -1;
                break;
            }

            moves.emplace_back(move);
            disambiguate(move, i, j, moves);
        }
    }

    // down left
    for (int i = file - 1; i >= 0; i--)
    {
        for (int j = rank - 1; j >= 0; j--)
        {
            move = "B";
            move += i + 'a';
            move += std::to_string(j + 1);
            if (m_board->m_grid[i][j] != nullptr)
            {
                if (m_board->m_grid[i][j]->get_side() != m_side)
                {
                    move.insert(1, 1, 'x');
                    moves.emplace_back(move);
                    disambiguate(move, i, j, moves);
                }

                i = -1;
                j = -1;
                break;
            }

            moves.emplace_back(move);
            disambiguate(move, i, j, moves);
        }
    }

    return moves;
}
