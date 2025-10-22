#pragma once

#include "piece.h"

class King : public Piece
{
public:
    King(Board *board, Side side);

    virtual std::vector<std::string> get_moves(int8_t file,
                                               int8_t rank) const override;
};
