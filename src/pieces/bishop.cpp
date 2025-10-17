#include <string>
#include <vector>

#include "board.h"
#include "bishop.h"

Bishop::Bishop(Board *board, Side side)
    : Piece(board, side, 'B')
{
}

std::vector<std::string> Bishop::get_moves(int8_t file, int8_t rank) const
{
    std::vector<std::string> moves;
    moves.reserve(36);
    std::string move;

    // up right
    for (int i = file + 1, j = rank + 1; i < 8 && j < 8; i++, j++)
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
            }

            break;
        }

        moves.emplace_back(move);
    }

    // up left
    for (int i = file - 1, j = rank + 1; i >= 0 && j < 8; i--, j++)
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
            }

            break;
        }

        moves.emplace_back(move);
    }

    // down right
    for (int i = file + 1, j = rank - 1; i < 8 && j >= 0; i++, j++)
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
            }

            break;
        }

        moves.emplace_back(move);
    }

    // down left
    for (int i = file - 1, j = rank - 1; i >= 0 && j >= 0; i--, j--)
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
            }

            break;
        }

        moves.emplace_back(move);
    }

    disambiguate_moves(file, rank, moves);
    moves.shrink_to_fit();
    return moves;
}
