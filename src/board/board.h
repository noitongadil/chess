#pragma once

#include <string>
#include "piece.h"

class Board
{
public:
    /**
     * @brief Default constructor.
     */
    Board();

    /**
     * @brief Destructor.
     */
    ~Board();

    /**
     * @brief Prints the board.
     */
    void display_board();

    /**
     * @brief Passes the move along to the correct piece.
     *
     * @param move The move to pass along.
     * @param color The side the move was made from.
     */
    void make_move(std::string &move, Piece::Side side);

    Piece *m_grid[8][8] = {}; ///< The grid of pieces.
};
