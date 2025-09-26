#pragma once

#include "piece.h"

class Queen : public Piece
{
public:
    Queen(Board *board, Position pos, Side side);

    virtual std::vector<std::string> possible_moves() const override;
};
