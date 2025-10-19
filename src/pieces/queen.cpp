#include "board.h"
#include "queen.h"

Queen::Queen(Board *board, Side side)
    : Piece(board, side, 'Q')
{
}

std::vector<std::string> Queen::get_moves(int8_t file, int8_t rank) const
{
    std::vector<std::string> moves;
    moves.reserve(36);
    std::string move;

    // up
    for (int j = rank + 1; j < 8; j++)
    {
        move = "Q";
        move += file + 'a';
        move += std::to_string(j + 1);

        if (m_board->m_grid[file][j] != nullptr)
        {
            if (m_board->m_grid[file][j]->get_side() != m_side)
            {
                move.insert(1, 1, 'x');
                moves.emplace_back(move);
                disambiguate(move, file, j, moves);
            }

            break;
        }

        moves.emplace_back(move);
        disambiguate(move, file, j, moves);
    }

    // down
    for (int j = rank - 1; j >= 0; j--)
    {
        move = "Q";
        move += file + 'a';
        move += std::to_string(j + 1);

        if (m_board->m_grid[file][j] != nullptr)
        {
            if (m_board->m_grid[file][j]->get_side() != m_side)
            {
                move.insert(1, 1, 'x');
                moves.emplace_back(move);
                disambiguate(move, file, j, moves);
            }

            break;
        }

        moves.emplace_back(move);
        disambiguate(move, file, j, moves);
    }

    // left
    for (int i = file - 1; i >= 0; i--)
    {
        move = "Q";
        move += i + 'a';
        move += std::to_string(rank + 1);

        if (m_board->m_grid[i][rank] != nullptr)
        {
            if (m_board->m_grid[i][rank]->get_side() != m_side)
            {
                move.insert(1, 1, 'x');
                moves.emplace_back(move);
                disambiguate(move, i, rank, moves);
            }

            break;
        }

        moves.emplace_back(move);
        disambiguate(move, i, rank, moves);
    }

    // right
    for (int i = file + 1; i < 8; i++)
    {
        move = "Q";
        move += i + 'a';
        move += std::to_string(rank + 1);

        if (m_board->m_grid[i][rank] != nullptr)
        {
            if (m_board->m_grid[i][rank]->get_side() != m_side)
            {
                move.insert(1, 1, 'x');
                moves.emplace_back(move);
                disambiguate(move, i, rank, moves);
            }

            break;
        }

        moves.emplace_back(move);
        disambiguate(move, i, rank, moves);
    }

    // up right
    for (int i = file + 1, j = rank + 1; i < 8 && j < 8; i++, j++)
    {
        move = "Q";
        move += i + 'a';
        move += std::to_string(j + 1);

        if (m_board->m_grid[i][j] != nullptr)
        {
            if (m_board->m_grid[i][j]->get_side() != m_side)
            {
                move.insert(1, 1, 'x');
                moves.emplace_back(move);
                disambiguate(move, i, j, moves);
            }

            break;
        }

        moves.emplace_back(move);
        disambiguate(move, i, j, moves);
    }

    // up left
    for (int i = file - 1, j = rank + 1; i >= 0 && j < 8; i--, j++)
    {
        move = "Q";
        move += i + 'a';
        move += std::to_string(j + 1);

        if (m_board->m_grid[i][j] != nullptr)
        {
            if (m_board->m_grid[i][j]->get_side() != m_side)
            {
                move.insert(1, 1, 'x');
                moves.emplace_back(move);
                disambiguate(move, i, j, moves);
            }

            break;
        }

        moves.emplace_back(move);
        disambiguate(move, i, j, moves);
    }

    // down right
    for (int i = file + 1, j = rank - 1; i < 8 && j >= 0; i++, j++)
    {
        move = "Q";
        move += i + 'a';
        move += std::to_string(j + 1);

        if (m_board->m_grid[i][j] != nullptr)
        {
            if (m_board->m_grid[i][j]->get_side() != m_side)
            {
                move.insert(1, 1, 'x');
                moves.emplace_back(move);
                disambiguate(move, i, j, moves);
            }

            break;
        }

        moves.emplace_back(move);
        disambiguate(move, i, j, moves);
    }

    // down left
    for (int i = file - 1, j = rank - 1; i >= 0 && j >= 0; i--, j--)
    {
        move = "Q";
        move += i + 'a';
        move += std::to_string(j + 1);
        if (m_board->m_grid[i][j] != nullptr)
        {
            if (m_board->m_grid[i][j]->get_side() != m_side)
            {
                move.insert(1, 1, 'x');
                moves.emplace_back(move);
                disambiguate(move, i, j, moves);
            }

            break;
        }

        moves.emplace_back(move);
        disambiguate(move, i, j, moves);
    }

    moves.shrink_to_fit();
    return moves;
}
