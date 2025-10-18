#include "king.h"
#include "board.h"

King::King(Board *board, Side side)
    : Piece(board, side, 'K')
{
}

std::vector<std::string> King::get_moves(int8_t file, int8_t rank) const
{
    std::vector<std::string> moves;
    std::string move;

    // up
    if (rank < 7)
    {
        move = "K";
        move += file + 'a';
        move += std::to_string(rank + 2);

        if (m_board->m_grid[file][rank + 1] == nullptr)
        {
            moves.push_back(move);
        }
        else if (m_board->m_grid[file][rank + 1]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.push_back(move);
        }
    }

    // up right
    if (rank < 7 && file < 7)
    {
        move = "K";
        move += file + 'a';
        move += std::to_string(rank + 2);

        if (m_board->m_grid[file + 1][rank + 1] == nullptr)
        {
            moves.push_back(move);
        }
        else if (m_board->m_grid[file + 1][rank + 1]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.push_back(move);
        }
    }

    // up left
    if (rank < 7 && file > 0)
    {
        move = "K";
        move += file - 1 + 'a';
        move += std::to_string(rank + 2);

        if (m_board->m_grid[file - 1][rank + 1] == nullptr)
        {
            moves.push_back(move);
        }
        else if (m_board->m_grid[file - 1][rank + 1]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.push_back(move);
        }
    }

    // right
    if (file > 0)
    {
        move = "K";
        move += file + 1 + 'a';
        move += std::to_string(rank + 1);

        if (m_board->m_grid[file + 1][rank] == nullptr)
        {
            moves.push_back(move);
        }
        else if (m_board->m_grid[file + 1][rank]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.push_back(move);
        }
    }

    // left
    if (file > 0)
    {
        move = "K";
        move += file - 1 + 'a';
        move += std::to_string(rank + 1);

        if (m_board->m_grid[file - 1][rank] == nullptr)
        {
            moves.push_back(move);
        }
        else if (m_board->m_grid[file - 1][rank]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.push_back(move);
        }
    }

    // down
    if (rank > 0)
    {
        move = "K";
        move += file + 'a';
        move += std::to_string(rank);

        if (m_board->m_grid[file][rank - 1] == nullptr)
        {
            moves.push_back(move);
        }
        else if (m_board->m_grid[file][rank - 1]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.push_back(move);
        }
    }

    // down right
    if (rank > 0 && file < 7)
    {
        move = "K";
        move += file + 1 + 'a';
        move += std::to_string(rank);

        if (m_board->m_grid[file + 1][rank - 1] == nullptr)
        {
            moves.push_back(move);
        }
        else if (m_board->m_grid[file + 1][rank - 1]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.push_back(move);
        }
    }

    // down left
    if (rank > 0 && file > 0)
    {
        move = "K";
        move += file - 1 + 'a';
        move += std::to_string(rank);

        if (m_board->m_grid[file - 1][rank - 1] == nullptr)
        {
            moves.push_back(move);
        }
        else if (m_board->m_grid[file - 1][rank - 1]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.push_back(move);
        }
    }

    return moves;
}
