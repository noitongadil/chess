#pragma once

#include <iostream>
#include "piece.h"

class Board
{
public:
    /// @brief Default constructor.
    Board();

    /// @brief Prints the board.
    void print_board();

    /**
         * @brief Passes the move along to the correct piece.
         *
         * @param move The move to pass along.
         * @param side The side the move was made from.
         * @param gamestats The stats of the game to keep track of.
         */
    void pass_move(std::string &move, Piece::Side side);

    std::vector<Piece *> m_pieces; ///< Container to hold all the pieces.
};
