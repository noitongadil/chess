#pragma once

#include "piece.h"

class Bishop : public Piece
{
public:
    Bishop(Board *board, Position pos, Side side);

    Bishop(Bishop &other);

    virtual std::vector<std::string> possible_moves() const override;

private:
    void rec_helper(std::vector<std::string> &possible_moves, Position curr_pos,
                    std::string dir, bool start = false) const;
};
