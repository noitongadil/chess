#include "board.h"
#include "bishop.h"

Bishop::Bishop(Board *board, Position pos, Side side)
    : Piece(board, pos, side, 'B')
{
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
