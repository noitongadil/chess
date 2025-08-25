#include "rook.h"
#include "board.h"
#include <string>

Rook::Rook(Board *board, Position pos, Side side)
    : Piece(board, pos, side)
{
    m_symb = (side == WHITE) ? 'R' : 'r';
}

std::vector<std::string> Rook::possible_moves() const
{
    std::vector<std::string> possible_moves;

    rec_helper(possible_moves, m_pos, "n", true);
    rec_helper(possible_moves, m_pos, "s", true);
    rec_helper(possible_moves, m_pos, "e", true);
    rec_helper(possible_moves, m_pos, "w", true);

    return possible_moves;
}

void Rook::rec_helper(std::vector<std::string> &possible_moves,
                      Position curr_pos, std::string dir, bool start) const
{
    if (!start)
    {
        for (auto &piece : m_board->m_pieces)
        {
            if (piece->m_pos.file == curr_pos.file &&
                piece->m_pos.rank == curr_pos.rank)
            {
                if (piece->m_side == m_side)
                {
                    return;
                }

                std::string move = "R";
                move += 'x';
                move += curr_pos.file - 1 + 'a';
                move += std::to_string(curr_pos.rank);
                possible_moves.push_back(move);
                disambiguate(move, possible_moves);
                return;
            }
        }

        std::string move = "R";
        move += curr_pos.file - 1 + 'a';
        move += std::to_string(curr_pos.rank);
        possible_moves.push_back(move);
        disambiguate(move, possible_moves);
    }

    if (dir == "n")
    {
        if (curr_pos.rank >= 8)
        {
            return;
        }

        curr_pos.rank++;
        rec_helper(possible_moves, curr_pos, dir);
    }
    else if (dir == "s")
    {
        if (curr_pos.rank <= 1)
        {
            return;
        }

        curr_pos.rank--;
        rec_helper(possible_moves, curr_pos, dir);
    }
    else if (dir == "w")
    {
        if (curr_pos.file <= 1)
        {
            return;
        }

        curr_pos.file--;
        rec_helper(possible_moves, curr_pos, dir);
    }
    else
    {
        if (curr_pos.file >= 8)
        {
            return;
        }

        curr_pos.file++;
        rec_helper(possible_moves, curr_pos, dir);
    }

    return;
}
