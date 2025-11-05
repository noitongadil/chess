#pragma once

#include "piece.h"

class Rook : public Piece
{
public:
    /**
     * @brief Default constructor.
     */
    Rook(Board *board, Side side);

    /**
     * @brief get all moves a piece can make given a starting position.
     *
     * @param file the file the piece is on.
     * @param rank the rank the piece is on.
     * @return a vector of type std::string containing all possible moves
     *         for a piece.
     */
    virtual std::vector<std::string> get_moves(int8_t file,
                                               int8_t rank) const override;

    /**
     * @brief A "deep" copy of a piece.
     */
    virtual Piece *copy() const override;
};
