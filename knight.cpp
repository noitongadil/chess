#include "knight.h"

Knight::Knight(Board *board, Position pos, Side side)
    : Piece(board, pos, side)
{
    m_symb = (side == WHITE) ? 'N' : 'n';
}

std::vector<std::string> Knight::possible_moves() const
{
    std::string move;
    std::vector<std::string> possible_moves;

    // up right
    if (m_pos.file + 1 <= 8 && m_pos.rank + 2 <= 8)
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
    if (m_pos.file + 1 <= 8 && m_pos.rank - 2 >= 1)
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
    if (m_pos.file - 1 >= 1 && m_pos.rank + 2 <= 8)
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
    if (m_pos.file - 1 >= 1 && m_pos.rank - 2 >= 1)
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
    if (m_pos.file + 2 <= 8 && m_pos.rank + 1 <= 8)
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
    if (m_pos.file + 2 <= 8 && m_pos.rank - 1 >= 1)
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
    if (m_pos.file - 2 >= 1 && m_pos.rank + 1 <= 8)
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
    if (m_pos.file - 2 >= 1 && m_pos.rank - 1 >= 1)
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
