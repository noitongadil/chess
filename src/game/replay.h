#pragma once

#include <string>
#include "game.h"

class Replay : public Game
{
public:
    /**
     * @brief Look at the replay of a game of chess.
     */
    virtual void play() override;

private:
    Board *m_states; ///< Stores each state of the board was in.

    /**
     * @brief Gets user input.
     * @note After the file containing the PGN has been read, the string that
     *       contains the contents will be modified such that all sequences
     *       matching the regex "(\\d+\\.)" will be replaced by a '\n' char.
     *
     * @return A vector of strings containing all moves made in the game.
     */
    std::vector<std::string> get_user_input();

    /**
     * @brief Count how many new lines are in the string @p moves_str.
     *
     * @param moves_str A reference to the string containing all moves of the game.
     * @return The number of new lines in the PGN txt file.
     */
    int count_newlines(const std::string &moves_str);

    /**
     * @brief Stores each move in @p moves_str in an element of a vector.
     *
     * @param moves_str A reference to the string containing all moves of the game.
     * @return Vector of all moves.
     */
    std::vector<std::string> vector_moves(const std::string &moves_str);
};
