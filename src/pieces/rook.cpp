#include "rook.h"
#include "board.h"
#include <string>

Rook::Rook(Board *board, Side side)
    : Piece(board, side, 'R')
{
}

Piece *Rook::copy() const
{
    return new Rook(m_board, m_side);
}

std::vector<std::string> Rook::get_moves(int8_t file, int8_t rank) const
{
    std::vector<std::string> moves;
    moves.reserve(36);
    std::string move;

    // up
    for (int j = rank + 1; j < 8; j++)
    {
        move = "R";
        move += file + 'a';
        move += std::to_string(j + 1);

        if (m_board->m_grid[file][j] != nullptr)
        {
            if (m_board->m_grid[file][j]->get_side() != m_side)
            {
                move.insert(1, 1, 'x');
                moves.emplace_back(move);
            }

            break;
        }

        moves.emplace_back(move);
    }

    // down
    for (int j = rank - 1; j >= 0; j--)
    {
        move = "R";
        move += file + 'a';
        move += std::to_string(j + 1);

        if (m_board->m_grid[file][j] != nullptr)
        {
            if (m_board->m_grid[file][j]->get_side() != m_side)
            {
                move.insert(1, 1, 'x');
                moves.emplace_back(move);
            }

            break;
        }

        moves.emplace_back(move);
    }

    // left
    for (int i = file - 1; i >= 0; i--)
    {
        move = "R";
        move += i + 'a';
        move += std::to_string(rank + 1);

        if (m_board->m_grid[i][rank] != nullptr)
        {
            if (m_board->m_grid[i][rank]->get_side() != m_side)
            {
                move.insert(1, 1, 'x');
                moves.emplace_back(move);
            }

            break;
        }

        moves.emplace_back(move);
    }

    // right
    for (int i = file + 1; i < 8; i++)
    {
        move = "R";
        move += i + 'a';
        move += std::to_string(rank + 1);

        if (m_board->m_grid[i][rank] != nullptr)
        {
            if (m_board->m_grid[i][rank]->get_side() != m_side)
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
