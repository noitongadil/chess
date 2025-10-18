#include "rook.h"
#include "board.h"
#include <string>

Rook::Rook(Board *board, Side side)
    : Piece(board, side, 'R')
{
}

std::vector<std::string> Rook::get_moves(int8_t file, int8_t rank) const
{
    std::vector<std::string> moves;

    // up
    for (int j = rank + 1; j < 8; j++)
    {
        if (m_board->m_grid[file][j] != nullptr)
        {
            if (m_board->m_grid[file][j]->get_side() != m_side)
            {
                std::string move = "R";
                move += 'x';
                move += file + 'a';
                move += std::to_string(j + 1);
                moves.push_back(move);
                disambiguate(move, file, j, moves);
            }

            break;
        }

        std::string move = "R";
        move += file + 'a';
        move += std::to_string(j + 1);
        moves.push_back(move);
        disambiguate(move, file, j, moves);
    }

    // down
    for (int j = rank - 1; j >= 0; j--)
    {
        if (m_board->m_grid[file][j] != nullptr)
        {
            if (m_board->m_grid[file][j]->get_side() != m_side)
            {
                std::string move = "R";
                move += 'x';
                move += file + 'a';
                move += std::to_string(j + 1);
                moves.push_back(move);
                disambiguate(move, file, j, moves);
            }

            break;
        }

        std::string move = "B";
        move += file + 'a';
        move += std::to_string(j + 1);
        moves.push_back(move);
        disambiguate(move, file, j, moves);
    }

    // left
    for (int i = file - 1; i >= 0; i--)
    {
        if (m_board->m_grid[i][rank] != nullptr)
        {
            if (m_board->m_grid[i][rank]->get_side() != m_side)
            {
                std::string move = "R";
                move += 'x';
                move += i + 'a';
                move += std::to_string(rank + 1);
                moves.push_back(move);
                disambiguate(move, i, rank, moves);
            }

            break;
        }

        std::string move = "R";
        move += i + 'a';
        move += std::to_string(rank + 1);
        moves.push_back(move);
        disambiguate(move, i, rank, moves);
    }

    // right
    for (int i = file + 1; i >= 0; i--)
    {
        if (m_board->m_grid[i][rank] != nullptr)
        {
            if (m_board->m_grid[i][rank]->get_side() != m_side)
            {
                std::string move = "R";
                move += 'x';
                move += i + 'a';
                move += std::to_string(rank + 1);
                moves.push_back(move);
                disambiguate(move, i, rank, moves);
            }

            break;
        }

        std::string move = "R";
        move += i + 'a';
        move += std::to_string(rank + 1);
        moves.push_back(move);
        disambiguate(move, i, rank, moves);
    }

    return moves;
}
