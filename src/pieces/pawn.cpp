#include "pawn.h"
#include "board.h"

Pawn::Pawn(Board *board, Side side)
    : Piece(board, side, 'P')
{
}

Piece *Pawn::copy() const
{
    return new Pawn(m_board, m_side);
}

std::vector<std::string> Pawn::get_moves(int8_t file, int8_t rank) const
{
    std::vector<std::string> moves;
    moves.reserve(4);
    std::string move;

    if (m_side == Side::WHITE)
    {
        if (rank == 1 && m_board->m_grid[file][rank + 2] == nullptr)
        {
            move = file + 'a';
            move += std::to_string(rank + 3);
            moves.push_back(move);
        }

        if (rank + 1 < 8 && m_board->m_grid[file][rank + 1] == nullptr)
        {
            move = file + 'a';
            move += std::to_string(rank + 2);
            moves.push_back(move);
        }

        if (file + 1 < 8 && rank + 1 < 8 &&
            m_board->m_grid[file + 1][rank + 1] != nullptr)
        {
            move = file + 'a';
            move += 'x';
            move += file + 1 + 'a';
            move += std::to_string(rank + 2);
            moves.push_back(move);
        }

        if (file > 0 && rank + 1 < 8 &&
            m_board->m_grid[file - 1][rank + 1] != nullptr)
        {
            move = file + 'a';
            move += 'x';
            move += file - 1 + 'a';
            move += std::to_string(rank + 2);
            moves.push_back(move);
        }
    }
    else
    {
        if (rank == 6 && m_board->m_grid[file][rank - 2] == nullptr)
        {
            move = file + 'a';
            move += std::to_string(rank - 1);
            moves.push_back(move);
        }

        if (rank > 0 && m_board->m_grid[file][rank - 1] == nullptr)
        {
            move = file + 'a';
            move += std::to_string(rank);
            moves.push_back(move);
        }

        if (file + 1 < 8 && rank > 0 &&
            m_board->m_grid[file + 1][rank - 1] != nullptr)
        {
            move = file + 'a';
            move += 'x';
            move += file + 1 + 'a';
            move += std::to_string(rank);
            moves.push_back(move);
        }

        if (file > 0 && rank > 0 &&
            m_board->m_grid[file - 1][rank - 1] != nullptr)
        {
            move = file + 'a';
            move += 'x';
            move += file - 1 + 'a';
            move += std::to_string(rank);
            moves.push_back(move);
        }
    }

    moves.shrink_to_fit();
    return moves;
}
