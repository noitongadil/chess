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
