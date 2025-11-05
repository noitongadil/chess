#pragma once

#include <string>
#include "board.h"

class Game
{
public:
    /**
     * @brief Play a game of chess.
     */
    virtual void play();

private:
    /**
     * @brief Gets user input.
     *
     * @return User string input(move).
     */
    std::string get_user_input();

protected:
    /**
     * @brief Checks if a move is valid or not.
     *
     * @param move Move to validate.
     * @return True if valid and false if not.
     */
    bool validate_move(const std::string &move);

private:
    Board m_board; ///< The board the game is played on.
};
