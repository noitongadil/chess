#pragma once

#include <iostream>
#include <string>
#include <vector>

class Board;

class Piece
{
public:
    /**
     * @brief Moves a piece.
     *
     * @param dest_file The file to move to.
     * @param dest_rank The rank to move to.
     * @param taking If a move is taking or not.
     */
    void make_move(int16_t dest_file, int16_t dest_rank, bool taking);

    /// @brief Returns all the possible moves of a piece.
    virtual std::vector<std::string> possible_moves() const = 0;

    /// @brief Destructor.
    virtual ~Piece() = default;

    Piece(const Piece &other) = delete;
    Piece(Piece &&other) = delete;

    enum Side : char
    {
        WHITE,
        BLACK
    };

    struct Position
    {
        int16_t rank;
        int16_t file;

        Position(int16_t rank, int16_t file);

        bool operator==(Position &other);
    };

    Position m_pos; ///< Position of the piece.
    Board *m_board; ///< Pointer to the board being played on.
    Side m_side; ///< The side the piece belongs to.
    char m_symb;

protected:
    /// @brief Default constructor.
    Piece(Board *board, Position pos, Side side, char symb);

    /**
     * @brief Disambiguates all possible moves of a piece.
     *
     * @param move The move to disambiguate.
     * @param possible_moves Reference to the vector of possible moves.
     */
    void disambiguate(std::string move,
                      std::vector<std::string> &possible_moves) const;

    void rec_helper(std::vector<std::string> &possible_moves, Position curr_pos,
                    std::string dir, bool start = false) const;

    bool is_blocked(int16_t rank, int16_t file) const;
};
