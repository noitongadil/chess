#pragma once

#include "piece.h"

class Bishop : public Piece
{
public:
    /**
     * @brief Default constructor.
     */
    Bishop(Board *board, Side side);

    /**
     * @brief Get all moves a piece can make given a starting position.
     *
     * @param file The file the piece is on.
     * @param rank The rank the piece is on.
     * @return A vector of type std::string containing all possible moves
     *         for a piece.
     */
    virtual std::vector<std::string> get_moves(int8_t file,
                                               int8_t rank) const override;

    /**
     * @brief A "deep" copy of a piece.
     */
    virtual Piece *copy() const override;
};
