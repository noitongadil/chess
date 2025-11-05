#include <string>
#include <vector>

#include "king.h"
#include "board.h"

King::King(Board *board, Side side)
    : Piece(board, side, 'K')
{
}

Piece *King::copy() const
{
    return new King(m_board, m_side);
}

std::vector<std::string> King::get_moves(int8_t file, int8_t rank) const
{
    std::vector<std::string> moves;
    moves.reserve(20);
    std::string move;

    // up
    if (rank < 7)
    {
        move = "K";
        move += file + 'a';
        move += std::to_string(rank + 2);

        if (m_board->m_grid[file][rank + 1] == nullptr)
        {
            moves.emplace_back(move);
        }
        else if (m_board->m_grid[file][rank + 1]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.emplace_back(move);
        }
    }

    // up right
    if (rank < 7 && file < 7)
    {
        move = "K";
        move += file + 1 + 'a';
        move += std::to_string(rank + 2);

        if (m_board->m_grid[file + 1][rank + 1] == nullptr)
        {
            moves.emplace_back(move);
        }
        else if (m_board->m_grid[file + 1][rank + 1]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.emplace_back(move);
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
            moves.emplace_back(move);
        }
        else if (m_board->m_grid[file - 1][rank + 1]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.emplace_back(move);
        }
    }

    // right
    if (file < 7)
    {
        move = "K";
        move += file + 1 + 'a';
        move += std::to_string(rank + 1);

        if (m_board->m_grid[file + 1][rank] == nullptr)
        {
            moves.emplace_back(move);
        }
        else if (m_board->m_grid[file + 1][rank]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.emplace_back(move);
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
            moves.emplace_back(move);
        }
        else if (m_board->m_grid[file - 1][rank]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.emplace_back(move);
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
            moves.emplace_back(move);
        }
        else if (m_board->m_grid[file][rank - 1]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.emplace_back(move);
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
            moves.emplace_back(move);
        }
        else if (m_board->m_grid[file + 1][rank - 1]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.emplace_back(move);
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
            moves.emplace_back(move);
        }
        else if (m_board->m_grid[file - 1][rank - 1]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.emplace_back(move);
        }
    }

    if ((rank == 0 || rank == 7) && file == 4)
    {
        bool x = true;
        for (int i = file + 1; i < 7; i++)
        {
            if (m_board->m_grid[i][rank] != nullptr)
            {
                x = false;
                break;
            }
        }

        if (x)
        {
            move = "O-O";
            moves.emplace_back(move);
        }

        for (int i = file - 1; i > 0; i--)
        {
            if (m_board->m_grid[i][rank] != nullptr)
            {
                x = false;
                break;
            }
        }

        if (x)
        {
            move = "O-O-O";
            moves.emplace_back(move);
        }
    }

    moves.shrink_to_fit();
    return moves;
}
