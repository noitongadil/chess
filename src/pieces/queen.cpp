#include "board.h"
#include "queen.h"

Queen::Queen(Board *board, Position pos, Side side)
    : Piece(board, pos, side)
{
    m_symb = (side == WHITE) ? 'Q' : 'q';
}

std::vector<std::string> Queen::possible_moves() const
{
    std::vector<std::string> possible_moves;

    rec_helper(possible_moves, m_pos, "n", true);
    rec_helper(possible_moves, m_pos, "s", true);
    rec_helper(possible_moves, m_pos, "e", true);
    rec_helper(possible_moves, m_pos, "w", true);
    rec_helper(possible_moves, m_pos, "nw", true);
    rec_helper(possible_moves, m_pos, "ne", true);
    rec_helper(possible_moves, m_pos, "sw", true);
    rec_helper(possible_moves, m_pos, "se", true);

    return possible_moves;
}
