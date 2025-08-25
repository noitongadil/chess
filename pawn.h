#pragma once

#include "piece.h"

class Pawn : public Piece
{
public:
    Pawn(Board *board, Position pos, Side side);

    virtual std::vector<std::string> possible_moves() const override;
};
