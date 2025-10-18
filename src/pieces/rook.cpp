#include "rook.h"
#include "board.h"
#include <string>

Rook::Rook(Board *board, Side side)
    : Piece(board, side, 'R')
{
}

std::vector<std::string> Rook::get_moves(int8_t file, int8_t rank) const
{
    std::vector<std::string> moves;
    moves.reserve(18);
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
                disambiguate(move, file, j, moves);
            }

            break;
        }

        moves.emplace_back(move);
        disambiguate(move, file, j, moves);
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
                disambiguate(move, file, j, moves);
            }

            break;
        }

        moves.emplace_back(move);
        disambiguate(move, file, j, moves);
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
                disambiguate(move, i, rank, moves);
            }

            break;
        }

        moves.emplace_back(move);
        disambiguate(move, i, rank, moves);
    }

    // right
    for (int i = file + 1; i >= 0; i--)
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
                disambiguate(move, i, rank, moves);
            }

            break;
        }

        moves.emplace_back(move);
        disambiguate(move, i, rank, moves);
    }

    return moves;
}
