#include "board.h"
#include "queen.h"

Queen::Queen(Board *board, Side side)
    : Piece(board, side, 'Q')
{
}

std::vector<std::string> Queen::get_moves(int8_t file, int8_t rank) const
{
    std::vector<std::string> moves;

    // up right
    for (int i = file; i < 8; i++)
    {
        for (int j = rank; j < 8; j++)
        {
            if (m_board->m_grid[i][j] != nullptr)
            {
                if (m_board->m_grid[i][j]->get_side() != m_side)
                {
                    std::string move = "Q";
                    move += 'x';
                    move += i + 'a';
                    move += std::to_string(j + 1);
                    moves.push_back(move);
                    disambiguate(move, i, j, moves);
                }

                i = 9;
                j = 9;
                break;
            }

            std::string move = "Q";
            move += i + 'a';
            move += std::to_string(j + 1);
            moves.push_back(move);
            disambiguate(move, i, j, moves);
        }
    }

    // up left
    for (int i = file; i >= 0; i--)
    {
        for (int j = rank; j < 8; j++)
        {
            if (m_board->m_grid[i][j] != nullptr)
            {
                if (m_board->m_grid[i][j]->get_side() != m_side)
                {
                    std::string move = "Q";
                    move += 'x';
                    move += i + 'a';
                    move += std::to_string(j + 1);
                    moves.push_back(move);
                    disambiguate(move, i, j, moves);
                }

                i = -1;
                j = 9;
                break;
            }

            std::string move = "Q";
            move += i + 'a';
            move += std::to_string(j + 1);
            moves.push_back(move);
            disambiguate(move, i, j, moves);
        }
    }

    // down right
    for (int i = file; i < 8; i++)
    {
        for (int j = rank; j >= 0; j--)
        {
            if (m_board->m_grid[i][j] != nullptr)
            {
                if (m_board->m_grid[i][j]->get_side() != m_side)
                {
                    std::string move = "Q";
                    move += 'x';
                    move += i + 'a';
                    move += std::to_string(j + 1);
                    moves.push_back(move);
                    disambiguate(move, i, j, moves);
                }

                i = 9;
                j = -1;
                break;
            }

            std::string move = "Q";
            move += i + 'a';
            move += std::to_string(j + 1);
            moves.push_back(move);
            disambiguate(move, i, j, moves);
        }
    }

    // down left
    for (int i = file; i >= 0; i--)
    {
        for (int j = rank; j >= 0; j--)
        {
            if (m_board->m_grid[i][j] != nullptr)
            {
                if (m_board->m_grid[i][j]->get_side() != m_side)
                {
                    std::string move = "Q";
                    move += 'x';
                    move += i + 'a';
                    move += std::to_string(j + 1);
                    moves.push_back(move);
                    disambiguate(move, i, j, moves);
                }

                i = -1;
                j = -1;
                break;
            }

            std::string move = "Q";
            move += i + 'a';
            move += std::to_string(j + 1);
            moves.push_back(move);
            disambiguate(move, i, j, moves);
        }
    }

    // up
    for (int j = rank; j < 8; j++)
    {
        if (m_board->m_grid[file][j] != nullptr)
        {
            if (m_board->m_grid[file][j]->get_side() != m_side)
            {
                std::string move = "Q";
                move += 'x';
                move += file + 'a';
                move += std::to_string(j + 1);
                moves.push_back(move);
                disambiguate(move, file, j, moves);
            }

            break;
        }

        std::string move = "Q";
        move += file + 'a';
        move += std::to_string(j + 1);
        moves.push_back(move);
        disambiguate(move, file, j, moves);
    }

    // down
    for (int j = rank; j >= 0; j--)
    {
        if (m_board->m_grid[file][j] != nullptr)
        {
            if (m_board->m_grid[file][j]->get_side() != m_side)
            {
                std::string move = "Q";
                move += 'x';
                move += file + 'a';
                move += std::to_string(j + 1);
                moves.push_back(move);
                disambiguate(move, file, j, moves);
            }

            break;
        }

        std::string move = "Q";
        move += file + 'a';
        move += std::to_string(j + 1);
        moves.push_back(move);
        disambiguate(move, file, j, moves);
    }

    // left
    for (int i = file; i >= 0; i--)
    {
        if (m_board->m_grid[i][rank] != nullptr)
        {
            if (m_board->m_grid[i][rank]->get_side() != m_side)
            {
                std::string move = "Q";
                move += 'x';
                move += i + 'a';
                move += std::to_string(rank + 1);
                moves.push_back(move);
                disambiguate(move, i, rank, moves);
            }

            break;
        }

        std::string move = "Q";
        move += i + 'a';
        move += std::to_string(rank + 1);
        moves.push_back(move);
        disambiguate(move, i, rank, moves);
    }

    // right
    for (int i = file; i >= 0; i--)
    {
        if (m_board->m_grid[i][rank] != nullptr)
        {
            if (m_board->m_grid[i][rank]->get_side() != m_side)
            {
                std::string move = "Q";
                move += 'x';
                move += i + 'a';
                move += std::to_string(rank + 1);
                moves.push_back(move);
                disambiguate(move, i, rank, moves);
            }

            break;
        }

        std::string move = "Q";
        move += i + 'a';
        move += std::to_string(rank + 1);
        moves.push_back(move);
        disambiguate(move, i, rank, moves);
    }

    return moves;
}
