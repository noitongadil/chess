#include <string> // for strings

#include "board.h"
#include "piece.h"

Piece::Piece(Board *board, Position pos, Side side, char symb)
    : m_board(board)
    , m_pos(pos)
    , m_side(side)
    , m_symb(symb)
{
}

Piece::Position::Position(int16_t rank, int16_t file)
    : rank(rank)
    , file(file)
{
}

void Piece::disambiguate(std::string move,
                         std::vector<std::string> &possible_moves) const
{
    move.insert(1, 1, m_pos.file - 1 + 'a');
    possible_moves.push_back(move);
    move.insert(2, std::to_string(m_pos.rank));
    possible_moves.push_back(move);
}

bool Piece::is_blocked(int16_t rank, int16_t file) const
{
    for (auto &piece : m_board->m_pieces)
    {
        if (piece->m_side != m_side)
        {
            return false;
        }

        if (piece->m_pos.rank == rank && piece->m_pos.file == file)
        {
            return true;
        }
    }
    return false;
}

void Piece::make_move(int16_t dest_file, int16_t dest_rank, bool taking)
{
    if (dest_file > 8 && dest_rank > 8)
    {
        for (auto &piece : m_board->m_pieces)
        {
            if ((piece->m_symb == 'R' || piece->m_symb == 'r') &&
                m_side == piece->m_side && piece->m_pos.file == 8)
            {
                piece->m_pos.file = 6;
                m_pos.file = 7;
                return;
            }
        }
    }
    else if (dest_file < 1 && dest_rank < 1)
    {
        for (auto &piece : m_board->m_pieces)
        {
            if ((piece->m_symb == 'R' || piece->m_symb == 'r') &&
                m_side == piece->m_side && piece->m_pos.file == 1)
            {
                piece->m_pos.file = 4;
                m_pos.file = 3;
                return;
            }
        }
    }

    if (!taking)
    {
        m_pos.file = dest_file;
        m_pos.rank = dest_rank;
        return;
    }

    for (auto it = m_board->m_pieces.begin(); it != m_board->m_pieces.end();
         it++)
    {
        if ((*it)->m_pos.file == dest_file && (*it)->m_pos.rank == dest_rank)
        {
            m_board->m_pieces.erase(it);
            m_pos.file = dest_file;
            m_pos.rank = dest_rank;
            break;
        }
    }
}

void Piece::rec_helper(std::vector<std::string> &possible_moves,
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

                std::string move;
                move += m_symb;
                move += 'x';
                move += curr_pos.file - 1 + 'a';
                move += std::to_string(curr_pos.rank);
                possible_moves.push_back(move);

                disambiguate(move, possible_moves);
                return;
            }
        }

        std::string move;
        move += m_symb;
        move += curr_pos.file - 1 + 'a';
        move += std::to_string(curr_pos.rank);
        possible_moves.push_back(move);
        disambiguate(move, possible_moves);
    }

    if (dir == "nw")
    {
        if (curr_pos.file <= 1 || curr_pos.rank >= 8)
        {
            return;
        }

        curr_pos.rank++;
        curr_pos.file--;
        rec_helper(possible_moves, curr_pos, dir);
    }
    else if (dir == "sw")
    {
        if (curr_pos.file <= 1 || curr_pos.rank <= 1)
        {
            return;
        }

        curr_pos.rank--;
        curr_pos.file--;
        rec_helper(possible_moves, curr_pos, dir);
    }
    else if (dir == "ne")
    {
        if (curr_pos.file >= 8 || curr_pos.rank >= 8)
        {
            return;
        }

        curr_pos.file++;
        curr_pos.rank++;
        rec_helper(possible_moves, curr_pos, dir);
    }
    else if (dir == "se")
    {
        if (curr_pos.file >= 8 || curr_pos.rank <= 1)
        {
            return;
        }

        curr_pos.file++;
        curr_pos.rank--;
        rec_helper(possible_moves, curr_pos, dir);
    }
    else if (dir == "n")
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
