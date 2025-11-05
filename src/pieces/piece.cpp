#include <string> // for strings

#include "board.h"
#include "piece.h"

Piece::Piece(Board *board, Side side, char symb)
    : m_board(board)
    , m_side(side)
    , m_symb(symb)
{
}

void Piece::disambiguate_moves(int8_t file, int8_t rank,
                               std::vector<std::string> &moves) const
{
    auto local_moves = moves;
    for (auto &move : local_moves)
    {
        move.insert(1, 1, file + 'a');
        moves.emplace_back(move);
        move.insert(2, std::to_string(rank + 1));
        moves.emplace_back(move);
    }
}

char Piece::get_symb()
{
    return m_symb;
}

Piece::Side Piece::get_side()
{
    return m_side;
}
