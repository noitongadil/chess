#include "pawn.h"
#include "board.h"

Pawn::Pawn(Board *local_board, Position pos, Side side)
    : Piece(local_board, pos, side, 'P')
{
}

std::vector<std::string> Pawn::possible_moves() const
{
    std::vector<std::string> possible_moves;
    std::string move;

    if (m_side == WHITE)
    {
        if (m_pos.rank == 2 && is_blocked(m_pos.rank + 2, m_pos.file))
        {
            move = m_pos.file - 1 + 'a';
            move += std::to_string(m_pos.rank + 2);
            possible_moves.push_back(move);
        }

        if (is_blocked(m_pos.rank + 1, m_pos.file))
        {
            move = m_pos.file - 1 + 'a';
            move += std::to_string(m_pos.rank + 1);
            possible_moves.push_back(move);
        }

        move = m_pos.file - 1 + 'a';
        move += 'x';
        move += m_pos.file + 'a';
        move += std::to_string(m_pos.rank + 1);
        possible_moves.push_back(move);

        move = m_pos.file - 1 + 'a';
        move += 'x';
        move += m_pos.file - 2 + 'a';
        move += std::to_string(m_pos.rank + 1);
        possible_moves.push_back(move);
    }
    else
    {
        if (m_pos.rank == 7)
        {
            move = m_pos.file - 1 + 'a';
            move += std::to_string(m_pos.rank - 2);
            possible_moves.push_back(move);
        }

        if (is_blocked(m_pos.rank + 1, m_pos.file))
        {
            move = m_pos.file - 1 + 'a';
            move += std::to_string(m_pos.rank - 1);
            possible_moves.push_back(move);
        }

        move = m_pos.file - 1 + 'a';
        move += 'x';
        move += m_pos.file + 'a';
        move += std::to_string(m_pos.rank - 1);
        possible_moves.push_back(move);

        move = m_pos.file - 1 + 'a';
        move += 'x';
        move += m_pos.file - 2 + 'a';
        move += std::to_string(m_pos.rank - 1);
        possible_moves.push_back(move);
    }

    return possible_moves;
}
