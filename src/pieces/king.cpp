#include "king.h"
#include "board.h"

King::King(Board *board, Position pos, Side side)
    : Piece(board, pos, side, 'K')
{
}

bool King::isBlocked(Side side, int file, int rank) const
{
    for (auto &piece : m_board->m_pieces)
    {
        if (piece->m_pos.file == file && piece->m_pos.rank == rank &&
            piece->m_side == side)
        {
            return true;
        }
    }
    return false;
}

std::vector<std::string> King::possible_moves() const
{
    std::vector<std::string> possible_moves;

    // right
    if (m_pos.file < 8)
    {
        if (!isBlocked(m_side, m_pos.file + 1, m_pos.rank))
        {
            std::string move = "K";
            move += m_pos.file + 'a';
            move += std::to_string(m_pos.rank);
            possible_moves.push_back(move);

            move.insert(1, 1, 'x');
            possible_moves.push_back(move);
        }

        // right up
        if (m_pos.rank < 8)
        {
            if (!isBlocked(m_side, m_pos.file + 1, m_pos.rank + 1))
            {
                std::string move = "K";
                move += m_pos.file + 'a';
                move += std::to_string(m_pos.rank + 1);
                possible_moves.push_back(move);

                move.insert(1, 1, 'x');
                possible_moves.push_back(move);
            }
        }

        // right down
        if (m_pos.rank > 1)
        {
            if (!isBlocked(m_side, m_pos.file + 1, m_pos.rank - 1))
            {
                std::string move = "K";
                move += m_pos.file + 'a';
                move += std::to_string(m_pos.rank - 1);
                possible_moves.push_back(move);

                move.insert(1, 1, 'x');
                possible_moves.push_back(move);
            }
        }
    }

    // up
    if (m_pos.rank < 8)
    {
        if (!isBlocked(m_side, m_pos.file, m_pos.rank + 1))
        {
            std::string move = "K";
            move += m_pos.file - 1 + 'a';
            move += std::to_string(m_pos.rank + 1);
            possible_moves.push_back(move);

            move.insert(1, 1, 'x');
            possible_moves.push_back(move);
        }
    }

    // down
    if (m_pos.rank > 1)
    {
        if (!isBlocked(m_side, m_pos.file, m_pos.rank - 1))
        {
            std::string move = "K";
            move += m_pos.file - 1 + 'a';
            move += std::to_string(m_pos.rank - 1);
            possible_moves.push_back(move);

            move.insert(1, 1, 'x');
            possible_moves.push_back(move);
        }
    }

    // left
    if (m_pos.file > 1)
    {
        if (!isBlocked(m_side, m_pos.file - 1, m_pos.rank))
        {
            std::string move = "K";
            move += m_pos.file - 2 + 'a';
            move += std::to_string(m_pos.rank);
            possible_moves.push_back(move);

            move.insert(1, 1, 'x');
            possible_moves.push_back(move);
        }

        // left up
        if (m_pos.rank < 8)
        {
            if (!isBlocked(m_side, m_pos.file - 1, m_pos.rank + 1))
            {
                std::string move = "K";
                move += m_pos.file - 2 + 'a';
                move += std::to_string(m_pos.rank + 1);
                possible_moves.push_back(move);

                move.insert(1, 1, 'x');
                possible_moves.push_back(move);
            }
        }
    }

    // left down
    if (m_pos.rank > 1)
    {
        if (!isBlocked(m_side, m_pos.file - 1, m_pos.rank - 1))
        {
            std::string move = "K";
            move += (m_pos.file - 2 + 'a');
            move += std::to_string(m_pos.rank - 1);
            possible_moves.push_back(move);

            move.insert(1, 1, 'x');
            possible_moves.push_back(move);
        }
    }

    std::string move = "O-O-O";
    possible_moves.push_back(move);
    move = "O-O";
    possible_moves.push_back(move);

    return possible_moves;
}
