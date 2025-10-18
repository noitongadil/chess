#pragma once

#include "piece.h"

class Knight : public Piece
{
public:
    Knight(Board *board, Side side);

    virtual std::vector<std::string> get_moves(int8_t file,
                                               int8_t rank) const override;
};
