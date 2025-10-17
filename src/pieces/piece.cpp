#include <string> // for strings

#include "board.h"
#include "piece.h"

Piece::Piece(Board *board, Side side, char symb)
    : m_board(board)
    , m_color(color)
    , m_symb(symb)
{
}

void Piece::disambiguate(std::string move, int8_t file, int8_t rank,
                         std::vector<std::string> &possible_moves) const
{
    move.insert(1, 1, file + 'a');
    possible_moves.push_back(move);
    move.insert(2, std::to_string(rank + 1));
    possible_moves.push_back(move);
}
