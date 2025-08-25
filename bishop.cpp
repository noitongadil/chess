#include "board.h"
#include "bishop.h"

Bishop::Bishop(Board *board, Position pos, Side side)
    : Piece(board, pos, side)
{
    m_symb = (side == WHITE) ? 'B' : 'b';
}

std::vector<std::string> Bishop::possible_moves() const
{
    std::vector<std::string> possible_moves;

    rec_helper(possible_moves, m_pos, "ne", true);
    rec_helper(possible_moves, m_pos, "se", true);
    rec_helper(possible_moves, m_pos, "nw", true);
    rec_helper(possible_moves, m_pos, "sw", true);

    return possible_moves;
}

void Bishop::rec_helper(std::vector<std::string> &possible_moves,
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

                std::string move = "B";
                move += 'x';
                move += curr_pos.file - 1 + 'a';
                move += std::to_string(curr_pos.rank);
                possible_moves.push_back(move);
                disambiguate(move, possible_moves);
                return;
            }
        }

        std::string move = "B";
        move += curr_pos.file - 1 + 'a';
        move += std::to_string(curr_pos.rank);
        possible_moves.push_back(move);
        disambiguate(move, possible_moves);
    }

    if (dir == "nw")
    {
        if (curr_pos.rank >= 8 || curr_pos.file <= 1)
        {
            return;
        }

        curr_pos.rank++;
        curr_pos.file--;
        rec_helper(possible_moves, curr_pos, dir);
    }
    else if (dir == "sw")
    {
        if (curr_pos.rank <= 1 || curr_pos.file <= 1)
        {
            return;
        }

        curr_pos.rank--;
        curr_pos.file--;
        rec_helper(possible_moves, curr_pos, dir);
    }
    else if (dir == "ne")
    {
        if (curr_pos.file <= 1 || curr_pos.rank >= 8)
        {
            return;
        }

        curr_pos.file++;
        curr_pos.rank++;
        rec_helper(possible_moves, curr_pos, dir);
    }
    else
    {
        if (curr_pos.file >= 8 || curr_pos.rank <= 1)
        {
            return;
        }

        curr_pos.file++;
        curr_pos.rank--;
        rec_helper(possible_moves, curr_pos, dir);
    }

    return;
}
