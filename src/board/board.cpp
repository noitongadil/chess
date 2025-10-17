#include <ncurses.h>

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
    m_grid[4][0] = new King(this, Piece::Position(1, 5), Piece::WHITE);
    m_grid[5][7] = new King(this, Piece::Position(8, 5), Piece::BLACK);

    m_grid[3][0] = new Queen(this, Piece::Position(1, 4), Piece::WHITE);
    m_grid[3][7] = new Queen(this, Piece::Position(8, 4), Piece::BLACK);

    m_grid[2][0] = new Bishop(this, Piece::Position(1, 3), Piece::WHITE);
    m_grid[5][0] = new Bishop(this, Piece::Position(1, 6), Piece::WHITE);
    m_grid[2][7] = new Bishop(this, Piece::Position(8, 3), Piece::BLACK);
    m_grid[5][7] = new Bishop(this, Piece::Position(8, 6), Piece::BLACK);

    m_grid[1][0] = new Knight(this, Piece::Position(1, 2), Piece::WHITE);
    m_grid[6][0] = new Knight(this, Piece::Position(1, 7), Piece::WHITE);
    m_grid[1][7] = new Knight(this, Piece::Position(8, 2), Piece::BLACK);
    m_grid[6][7] = new Knight(this, Piece::Position(8, 7), Piece::BLACK);

    m_grid[0][0] = new Rook(this, Piece::Position(1, 1), Piece::WHITE);
    m_grid[7][0] = new Rook(this, Piece::Position(1, 8), Piece::WHITE);
    m_grid[0][7] = new Rook(this, Piece::Position(8, 1), Piece::BLACK);
    m_grid[7][7] = new Rook(this, Piece::Position(8, 8), Piece::BLACK);

    for (int i = 1; i <= 8; i++)
    {
        m_grid[i - 1][1] = new Pawn(this, Piece::Position(2, i), Piece::WHITE);
    }

    for (int i = 1; i <= 8; i++)
    {
        m_grid[i - 1][6] = new Pawn(this, Piece::Position(7, i), Piece::BLACK);
    }
}

void Board::display_board()
{
    initscr();
    cbreak();

    if (has_colors() == false)
    {
        fprintf(stderr, "your terminal does not support colors\n");
        endwin();
        return;
    }

    int max_x = getmaxx(stdscr);
    int max_y = getmaxy(stdscr);

    int height = 10, width = 19, start_y = (max_y - height) / 2,
        start_x = (max_x - width) / 2;
    WINDOW *win = newwin(height, width, start_y, start_x);
    box(win, 0, 0);
    refresh();

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);

    for (int i = 1; i <= 8; i++)
    {
        mvprintw(start_y + i, start_x - 1, "%d", 9 - i);
    }

    for (int i = 1; i <= 8; i++)
    {
        mvprintw(start_y + height, start_x + i * 2, "%c", 'a' - 1 + i);
    }

#if 0
    for (auto &piece : m_pieces)
    {
        if (piece->m_side == Piece::WHITE)
        {
            wattron(win, COLOR_PAIR(1));
        }
        else
        {
            wattron(win, COLOR_PAIR(2));
        }

        mvwprintw(win, 9 - piece->m_pos.rank, piece->m_pos.file * 2, "%c",
                  piece->m_symb);
    }
#endif

    wrefresh(win);
    wclear(win);

    endwin();
}

void Board::make_move(std::string &move, Piece::Side side)
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
}
