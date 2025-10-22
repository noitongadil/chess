#include <ncurses.h>

#include "board.h"
#include "piece.h"
#include "piece.h"
#include "king.h"
#include "bishop.h"
#include "rook.h"
#include "knight.h"
#include "queen.h"
#include "pawn.h"

Board::Board()
{
    m_grid[4][0] = new King(this, Piece::Side::WHITE);
    m_grid[4][7] = new King(this, Piece::Side::BLACK);

    m_grid[3][0] = new Queen(this, Piece::Side::WHITE);
    m_grid[3][7] = new Queen(this, Piece::Side::BLACK);

    m_grid[2][0] = new Bishop(this, Piece::Side::WHITE);
    m_grid[5][0] = new Bishop(this, Piece::Side::WHITE);
    m_grid[2][7] = new Bishop(this, Piece::Side::BLACK);
    m_grid[5][7] = new Bishop(this, Piece::Side::BLACK);

    m_grid[1][0] = new Knight(this, Piece::Side::WHITE);
    m_grid[6][0] = new Knight(this, Piece::Side::WHITE);
    m_grid[1][7] = new Knight(this, Piece::Side::BLACK);
    m_grid[6][7] = new Knight(this, Piece::Side::BLACK);

    m_grid[0][0] = new Rook(this, Piece::Side::WHITE);
    m_grid[7][0] = new Rook(this, Piece::Side::WHITE);
    m_grid[0][7] = new Rook(this, Piece::Side::BLACK);
    m_grid[7][7] = new Rook(this, Piece::Side::BLACK);

    for (int file = 0; file < 8; file++)
    {
        m_grid[file][1] = new Pawn(this, Piece::Side::WHITE);
    }

    for (int file = 0; file < 8; file++)
    {
        m_grid[file][6] = new Pawn(this, Piece::Side::BLACK);
    }
}

Board::~Board()
{
    for (int file = 0; file < 8; file++)
    {
        for (int rank = 0; rank < 8; rank++)
        {
            if (m_grid[file][rank] != nullptr)
            {
                delete m_grid[file][rank];
                m_grid[file][rank] = nullptr;
            }
        }
    }
}

void Board::display_board()
{
    cbreak();

    if (has_colors() == false)
    {
        fprintf(stderr, "your terminal does not support colors\n");
        endwin();
        return;
    }

    int max_x = getmaxx(stdscr);
    int max_y = getmaxy(stdscr);

    int height = 10;
    int width = 19;
    int start_y = (max_y - height) / 2;
    int start_x = (max_x - width) / 2;

    WINDOW *win = newwin(height, width, start_y, start_x);
    box(win, 0, 0);
    refresh();

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);

    for (int rank = 1; rank <= 8; rank++)
    {
        mvprintw(start_y + rank, start_x - 1, "%d", 9 - rank);
    }

    for (int file = 1; file <= 8; file++)
    {
        mvprintw(start_y + height, start_x + file * 2, "%c", 'a' - 1 + file);
    }

    for (int file = 0; file < 8; file++)
    {
        for (int rank = 0; rank < 8; rank++)
        {
            if (m_grid[file][rank] == nullptr)
            {
                continue;
            }

            if (m_grid[file][rank]->get_side() == Piece::Side::WHITE)
            {
                wattron(win, COLOR_PAIR(1));
            }
            else
            {
                wattron(win, COLOR_PAIR(2));
            }

            mvwprintw(win, 8 - rank, (file + 1) * 2, "%c",
                      m_grid[file][rank]->get_symb());
        }
    }

    wrefresh(win);
    wclear(win);
}

bool Board::make_move(std::string &move, Piece::Side side)
{
    int mv_len = move.length();

    int dest_file = move[mv_len - 2] - 'a';
    int dest_rank = move[mv_len - 1] - '1';

    if (move[mv_len - 1] == '+')
    {
        m_checked = true;
        dest_file = move[mv_len - 3] - 'a';
        dest_rank = move[mv_len - 2] - '1';

        move.erase(move.end() - 1);
    }
    else if (move[mv_len - 1] == '#')
    {
        m_mated = true;
        dest_file = move[mv_len - 3] - 'a';
        dest_rank = move[mv_len - 2] - '1';

        move.erase(move.end() - 1);
    }

    enum class Castle : char
    {
        SHORT,
        LONG,
        NONE,
    } castle = Castle::NONE;

    if (move == "O-O")
    {
        castle = Castle::SHORT;
    }
    else if (move == "O-O-O")
    {
        castle = Castle::LONG;
    }

    for (int file = 0; file < 8; file++)
    {
        for (int rank = 0; rank < 8; rank++)
        {
            if (m_grid[file][rank] == nullptr ||
                m_grid[file][rank]->get_side() != side)
            {
                continue;
            }

            std::vector<std::string> moves =
                m_grid[file][rank]->get_moves(file, rank);

            for (auto loc_move : moves)
            {
                if (loc_move == move)
                {
                    switch (castle)
                    {
                    case Castle::SHORT: {
                        auto king = m_grid[file][rank];
                        m_grid[file + 1][rank] = m_grid[7][rank];
                        m_grid[file + 2][rank] = king;
                        m_grid[file][rank] = nullptr;
                        m_grid[7][rank] = nullptr;
                        return true;
                    }

                    case Castle::LONG: {
                        auto king = m_grid[file][rank];
                        m_grid[file - 1][rank] = m_grid[0][rank];
                        m_grid[file - 2][rank] = king;
                        m_grid[file][rank] = nullptr;
                        m_grid[0][rank] = nullptr;
                        return true;
                    }

                    default:
                        break;
                    }

                    if (m_grid[dest_file][dest_rank] != nullptr)
                    {
                        delete m_grid[dest_file][dest_rank];
                    }

                    m_grid[dest_file][dest_rank] = m_grid[file][rank];
                    m_grid[file][rank] = nullptr;

                    return true;
                }
            }
        }
    }

    return false;
}
