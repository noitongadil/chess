#include "knight.h"
#include "board.h"

Knight::Knight(Board *board, Side side)
    : Piece(board, side, 'N')
{
}

std::vector<std::string> Knight::get_moves(int8_t file, int8_t rank) const
{
    std::vector<std::string> moves;
    std::string move;

    // up right
    if (file + 1 < 8 && rank + 2 < 8)
    {
        move = 'N';
        move += file + 1 + 'a';
        move += std::to_string(rank + 3);

        if (m_board->m_grid[file + 1][rank + 2] == nullptr)
        {
            moves.push_back(move);
            disambiguate(move, file, rank, moves);
        }
        else if (m_board->m_grid[file + 1][rank + 2]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.push_back(move);
            disambiguate(move, file, rank, moves);
        }
    }

    // up left
    if (file - 1 > 0 && rank + 2 < 8)
    {
        move = 'N';
        move += file - 1 + 'a';
        move += std::to_string(rank + 3);

        if (m_board->m_grid[file - 1][rank + 2] == nullptr)
        {
            moves.push_back(move);
            disambiguate(move, file, rank, moves);
        }
        else if (m_board->m_grid[file - 1][rank + 2]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.push_back(move);
            disambiguate(move, file, rank, moves);
        }
    }

    // down right
    if (file + 1 < 8 && rank - 2 > 0)
    {
        move = 'N';
        move += file + 1 + 'a';
        move += std::to_string(rank - 1);

        if (m_board->m_grid[file + 1][rank - 2] == nullptr)
        {
            moves.push_back(move);
            disambiguate(move, file, rank, moves);
        }
        else if (m_board->m_grid[file + 1][rank - 2]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.push_back(move);
            disambiguate(move, file, rank, moves);
        }
    }

    // down left
    if (file - 1 > 0 && rank - 2 > 0)
    {
        move = 'N';
        move += file - 1 + 'a';
        move += std::to_string(rank - 1);

        if (m_board->m_grid[file - 1][rank - 2] == nullptr)
        {
            moves.push_back(move);
            disambiguate(move, file, rank, moves);
        }
        else if (m_board->m_grid[file - 1][rank - 2]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.push_back(move);
            disambiguate(move, file, rank, moves);
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
            moves.push_back(move);
            disambiguate(move, file, rank, moves);
        }
        else if (m_board->m_grid[file + 2][rank + 1]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.push_back(move);
            disambiguate(move, file, rank, moves);
        }
    }

    // right down
    if (file + 2 < 8 && rank - 1 > 0)
    {
        move = 'N';
        move += file + 2 + 'a';
        move += std::to_string(rank);

        if (m_board->m_grid[file + 2][rank - 1] == nullptr)
        {
            moves.push_back(move);
            disambiguate(move, file, rank, moves);
        }
        else if (m_board->m_grid[file + 2][rank - 1]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.push_back(move);
            disambiguate(move, file, rank, moves);
        }
    }

    // left up
    if (file - 2 > 0 && rank + 1 < 8)
    {
        move = 'N';
        move += file - 2 + 'a';
        move += std::to_string(rank + 2);

        if (m_board->m_grid[file - 2][rank + 1] == nullptr)
        {
            moves.push_back(move);
            disambiguate(move, file, rank, moves);
        }
        else if (m_board->m_grid[file - 2][rank + 1]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.push_back(move);
            disambiguate(move, file, rank, moves);
        }
    }

    // left down
    if (file - 2 > 0 && rank - 1 > 0)
    {
        move = 'N';
        move += file - 2 + 'a';
        move += std::to_string(rank);

        if (m_board->m_grid[file - 2][rank - 1] == nullptr)
        {
            moves.push_back(move);
            disambiguate(move, file, rank, moves);
        }
        else if (m_board->m_grid[file - 2][rank - 1]->get_side() != m_side)
        {
            move.insert(1, 1, 'x');
            moves.push_back(move);
            disambiguate(move, file, rank, moves);
        }
    }

    return moves;
}
