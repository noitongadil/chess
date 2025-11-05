#include "knight.h"
#include "board.h"

Knight::Knight(Board *board, Side side)
    : Piece(board, side, 'N')
{
}

Piece *Knight::copy() const
{
    return new Knight(m_board, m_side);
}

std::vector<std::string> Knight::get_moves(int8_t file, int8_t rank) const
{
    std::vector<std::string> moves;
    moves.reserve(32);
    std::string move;

    // up right
    if (file + 1 < 8 && rank + 2 < 8)
    {
        move = 'N';
        move += file + 1 + 'a';
        move += std::to_string(rank + 3);

        if (m_board->m_grid[file + 1][rank + 2] == nullptr)
        {
            moves.emplace_back(move);
        }
        else if (m_board->m_grid[file + 1][rank + 2]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.emplace_back(move);
        }
    }

    // up left
    if (file - 1 >= 0 && rank + 2 < 8)
    {
        move = 'N';
        move += file - 1 + 'a';
        move += std::to_string(rank + 3);

        if (m_board->m_grid[file - 1][rank + 2] == nullptr)
        {
            moves.emplace_back(move);
        }
        else if (m_board->m_grid[file - 1][rank + 2]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.emplace_back(move);
        }
    }

    // down right
    if (file + 1 < 8 && rank - 2 >= 0)
    {
        move = 'N';
        move += file + 1 + 'a';
        move += std::to_string(rank - 1);

        if (m_board->m_grid[file + 1][rank - 2] == nullptr)
        {
            moves.emplace_back(move);
        }
        else if (m_board->m_grid[file + 1][rank - 2]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.emplace_back(move);
        }
    }

    // down left
    if (file - 1 >= 0 && rank - 2 >= 0)
    {
        move = 'N';
        move += file - 1 + 'a';
        move += std::to_string(rank - 1);

        if (m_board->m_grid[file - 1][rank - 2] == nullptr)
        {
            moves.emplace_back(move);
        }
        else if (m_board->m_grid[file - 1][rank - 2]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.emplace_back(move);
        }
    }

    // right up
    if (file + 2 < 8 && rank + 1 < 8)
    {
        move = 'N';
        move += file + 2 + 'a';
        move += std::to_string(rank + 2);

        if (m_board->m_grid[file + 2][rank + 1] == nullptr)
        {
            moves.emplace_back(move);
        }
        else if (m_board->m_grid[file + 2][rank + 1]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.emplace_back(move);
        }
    }

    // right down
    if (file + 2 < 8 && rank - 1 >= 0)
    {
        move = 'N';
        move += file + 2 + 'a';
        move += std::to_string(rank);

        if (m_board->m_grid[file + 2][rank - 1] == nullptr)
        {
            moves.emplace_back(move);
        }
        else if (m_board->m_grid[file + 2][rank - 1]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.emplace_back(move);
        }
    }

    // left up
    if (file - 2 >= 0 && rank + 1 < 8)
    {
        move = 'N';
        move += file - 2 + 'a';
        move += std::to_string(rank + 2);

        if (m_board->m_grid[file - 2][rank + 1] == nullptr)
        {
            moves.emplace_back(move);
        }
        else if (m_board->m_grid[file - 2][rank + 1]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.emplace_back(move);
        }
    }

    // left down
    if (file - 2 >= 0 && rank - 1 >= 0)
    {
        move = 'N';
        move += file - 2 + 'a';
        move += std::to_string(rank);

        if (m_board->m_grid[file - 2][rank - 1] == nullptr)
        {
            moves.emplace_back(move);
        }
        else if (m_board->m_grid[file - 2][rank - 1]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.emplace_back(move);
        }
    }

    disambiguate_moves(file, rank, moves);
    moves.shrink_to_fit();
    return moves;
}
