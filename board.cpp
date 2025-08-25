#include "piece.h"
#include "board.h"
#include "piece.h"
#include "king.h"
#include "bishop.h"
#include "rook.h"
#include "knight.h"
#include "queen.h"
#include "pawn.h"

Board::Board()
{
    auto w_king = new King(this, Piece::Position(1, 5), Piece::WHITE);
    auto b_king = new King(this, Piece::Position(8, 5), Piece::BLACK);
    m_pieces.push_back(w_king);
    m_pieces.push_back(b_king);

    auto w_queen = new Queen(this, Piece::Position(1, 4), Piece::WHITE);
    auto b_queen = new Queen(this, Piece::Position(8, 4), Piece::BLACK);
    m_pieces.push_back(w_queen);
    m_pieces.push_back(b_queen);

    auto w_bishop_r = new Bishop(this, Piece::Position(1, 3), Piece::WHITE);
    auto w_bishop_l = new Bishop(this, Piece::Position(1, 6), Piece::WHITE);
    auto b_bishop_r = new Bishop(this, Piece::Position(8, 3), Piece::BLACK);
    auto b_bishop_l = new Bishop(this, Piece::Position(8, 6), Piece::BLACK);

    m_pieces.push_back(w_bishop_r);
    m_pieces.push_back(w_bishop_l);
    m_pieces.push_back(b_bishop_r);
    m_pieces.push_back(b_bishop_l);

    auto w_knight_l = new Knight(this, Piece::Position(1, 2), Piece::WHITE);
    auto w_knight_r = new Knight(this, Piece::Position(1, 7), Piece::WHITE);
    auto b_knight_l = new Knight(this, Piece::Position(8, 2), Piece::BLACK);
    auto b_knight_r = new Knight(this, Piece::Position(8, 7), Piece::BLACK);

    m_pieces.push_back(w_knight_l);
    m_pieces.push_back(w_knight_r);
    m_pieces.push_back(b_knight_l);
    m_pieces.push_back(b_knight_r);

    auto w_rook_l = new Rook(this, Piece::Position(1, 1), Piece::WHITE);
    auto w_rook_r = new Rook(this, Piece::Position(1, 8), Piece::WHITE);
    auto b_rook_l = new Rook(this, Piece::Position(8, 1), Piece::BLACK);
    auto b_rook_r = new Rook(this, Piece::Position(8, 8), Piece::BLACK);

    m_pieces.push_back(w_rook_l);
    m_pieces.push_back(w_rook_r);
    m_pieces.push_back(b_rook_l);
    m_pieces.push_back(b_rook_r);

    for (int i = 1; i <= 8; i++)
    {
        auto pawn = new Pawn(this, Piece::Position(2, i), Piece::WHITE);
        m_pieces.push_back(pawn);
    }

    for (int i = 1; i <= 8; i++)
    {
        auto pawn = new Pawn(this, Piece::Position(7, i), Piece::BLACK);
        m_pieces.push_back(pawn);
    }
}

void Board::print_board()
{
    bool printed = false;

    for (int rank = 8; rank >= 1; rank--)
    {
        for (int file = 1; file <= 8; file++)
        {
            printed = false;

            for (auto &piece : m_pieces)
            {
                if (piece->m_pos.file == file && piece->m_pos.rank == rank)
                {
                    printf("%c ", piece->m_symb);
                    printed = true;
                    break;
                }
            }

            if (!printed)
            {
                std::cout << "- ";
            }
        }
        std::cout << std::endl;
    }
}

void Board::pass_move(std::string &move, Piece::Side side)
{
    int mv_len = move.length();

    int dest_file = move[mv_len - 2] - 'a' + 1;
    int dest_rank = move[mv_len - 1] - '0';

    bool taking = false;

    if (move[mv_len - 1] == '+' || move[mv_len - 1] == '#')
    {
        dest_file = move[mv_len - 3] - 'a' + 1;
        dest_rank = move[mv_len - 2] - '0';

        move.erase(move.end() - 1);
    }

    if (move == "O-O")
    {
        dest_file = 9;
        dest_rank = 9;
    }
    else if (move == "O-O-O")
    {
        dest_file = -1;
        dest_rank = -1;
    }

    for (char c : move)
    {
        if (c == 'x')
        {
            taking = true;
            break;
        }
    }

    for (auto &piece : m_pieces)
    {
        if (piece->m_side != side)
        {
            continue;
        }

        std::vector<std::string> possible_moves = piece->possible_moves();
        for (std::string &pos_move : possible_moves)
        {
            if (pos_move == move)
            {
                piece->make_move(dest_file, dest_rank, taking);
                return;
            }
        }
    }
}
