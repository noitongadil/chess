#pragma once

#include "piece.h"

class King : public Piece
{
public:
    King(Board *board, Position pos, Side side);

    virtual std::vector<std::string> possible_moves() const override;


private:
    bool isBlocked(Side side, int file, int rank) const;

    void castle();
};
