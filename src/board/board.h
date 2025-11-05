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
     * @brief Copy constructor.
     */
    Board(const Board &other);

    /**
     * @brief Copy assignment operator.
     */
    Board &operator=(const Board &other);

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
    bool make_move(std::string &move, Piece::Side side);

    std::array<std::array<Piece *, 8>, 8> m_grid = {}; ///< The grid of pieces.
};
