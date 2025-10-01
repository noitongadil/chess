#include "knight.h"

Knight::Knight(Board *board, Position pos, Side side)
    : Piece(board, pos, side, 'N')
{
}

std::vector<std::string> Knight::possible_moves() const
{
    std::string move;
    std::vector<std::string> possible_moves;

    // up right
    if (is_blocked(m_pos.rank + 2, m_pos.file + 1) && m_pos.rank + 2 <= 8 &&
        m_pos.file + 1 <= 8)
    {
        move = 'N';
        move += m_pos.file + 'a';
        move += std::to_string(m_pos.rank + 2);
        possible_moves.push_back(move);
        disambiguate(move, possible_moves);

        move.insert(1, 1, 'x');
        possible_moves.push_back(move);
        disambiguate(move, possible_moves);
    }

    // down right
    if (is_blocked(m_pos.rank - 2, m_pos.file + 1) && m_pos.rank - 2 >= 1 &&
        m_pos.file + 1 <= 8)
    {
        move = 'N';
        move += m_pos.file + 'a';
        move += std::to_string(m_pos.rank - 2);
        possible_moves.push_back(move);
        disambiguate(move, possible_moves);

        move.insert(1, 1, 'x');
        possible_moves.push_back(move);
        disambiguate(move, possible_moves);
    }

    // up left
    if (is_blocked(m_pos.rank + 2, m_pos.file - 1) && m_pos.rank + 2 <= 8 &&
        m_pos.file - 1 >= 1)
    {
        move = 'N';
        move += m_pos.file - 2 + 'a';
        move += std::to_string(m_pos.rank + 2);
        possible_moves.push_back(move);
        disambiguate(move, possible_moves);

        move.insert(1, 1, 'x');
        possible_moves.push_back(move);
        disambiguate(move, possible_moves);
    }

    // down left
    if (is_blocked(m_pos.rank - 2, m_pos.file - 1) && m_pos.rank - 2 >= 1 &&
        m_pos.file - 1 >= 1)
    {
        move = 'N';
        move += m_pos.file - 2 + 'a';
        move += std::to_string(m_pos.rank - 2);
        possible_moves.push_back(move);
        disambiguate(move, possible_moves);

        move.insert(1, 1, 'x');
        possible_moves.push_back(move);
        disambiguate(move, possible_moves);
    }

    // right up
    if (is_blocked(m_pos.rank + 1, m_pos.file + 2) && m_pos.rank + 1 <= 8 &&
        m_pos.file + 2 <= 8)
    {
        move = 'N';
        move += m_pos.file + 1 + 'a';
        move += std::to_string(m_pos.rank + 1);
        possible_moves.push_back(move);
        disambiguate(move, possible_moves);

        move.insert(1, 1, 'x');
        possible_moves.push_back(move);
        disambiguate(move, possible_moves);
    }

    // right down
    if (is_blocked(m_pos.rank - 1, m_pos.file + 2) && m_pos.rank - 1 >= 1 &&
        m_pos.file + 2 <= 8)
    {
        move = 'N';
        move += m_pos.file + 1 + 'a';
        move += std::to_string(m_pos.rank - 1);
        possible_moves.push_back(move);
        disambiguate(move, possible_moves);

        move.insert(1, 1, 'x');
        possible_moves.push_back(move);
        disambiguate(move, possible_moves);
    }

    // left up
    if (is_blocked(m_pos.rank + 1, m_pos.file - 2) && m_pos.rank + 1 <= 8 &&
        m_pos.file - 2 >= 1)
    {
        move = 'N';
        move += m_pos.file - 3 + 'a';
        move += std::to_string(m_pos.rank + 1);
        possible_moves.push_back(move);
        disambiguate(move, possible_moves);

        move.insert(1, 1, 'x');
        possible_moves.push_back(move);
        disambiguate(move, possible_moves);
    }

    // left down
    if (is_blocked(m_pos.rank - 1, m_pos.file - 2) && m_pos.rank - 1 >= 1 &&
        m_pos.file - 2 >= 1)
    {
        move = 'N';
        move += m_pos.file - 3 + 'a';
        move += std::to_string(m_pos.rank - 1);
        possible_moves.push_back(move);
        disambiguate(move, possible_moves);

        move.insert(1, 1, 'x');
        possible_moves.push_back(move);
        disambiguate(move, possible_moves);
    }

    return possible_moves;
}
