#pragma once

#include <string>
#include <vector>

class Board;

class Piece
{
public:
    enum class Side : char
    {
        WHITE,
        BLACK,
        NONE,
    };

protected:
    /**
     * @brief Default constructor.
     */
    Piece(Board *board, Side side, char symb);

public:
    /**
     * @brief Destructor.
     */
    virtual ~Piece() = default;

    /**
     * @brief Returns all the possible moves of a piece.
     *
     * @param file The file the piece is on.
     * @param rank The rank the piece is on.
     * @return A vector of strings containing all possible moves.
     */
    virtual std::vector<std::string> get_moves(int8_t file,
                                               int8_t rank) const = 0;

    /**
     * @brief Returns the symbol of a piece.
     */
    char get_symb();

    /**
     * @brief Returns the side of a piece.
     */
    Side get_side();

    Piece(const Piece &other) = delete;
    Piece(Piece &&other) = delete;

protected:
    Board *m_board; ///< Pointer to the board being played on.
    Side m_side; ///< Side of piece.
    char m_symb; ///< Symbol of piece.

    /**
     * @brief Disambiguates all possible moves of a piece.
     *
     * @param move The move to disambiguate.
     * @param possible_moves Reference to the vector of possible moves.
     */
    void disambiguate(std::string move, int8_t file, int8_t rank,
                      std::vector<std::string> &possible_moves) const;
};
