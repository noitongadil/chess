#pragma once

#include "piece.h"

class Bishop : public Piece
{
public:
    Bishop(Board *board, Side side);

    Bishop(Bishop &other);

    virtual std::vector<std::string> get_moves(int8_t file,
                                               int8_t rank) const override;
};
