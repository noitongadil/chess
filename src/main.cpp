#include "replay.h"
#include <ncurses.h>

#include "game.h"
#include "replay.h"

inline int get_user_input();

int main()
{
    initscr();

    int user_choice = get_user_input();

    switch (user_choice)
    {
    default: {
        fprintf(stderr, "invalid mode\n");
        break;
    }
    case 1: {
        Game game;
        game.play();
        break;
    }
    case 2: {
        Replay replay;
        replay.play();
        break;
    }
    }

    endwin();
    return 0;
}

inline int get_user_input()
{
    echo();

    int max_x = getmaxx(stdscr);
    int max_y = getmaxy(stdscr);

    int big_height = 8;
    int big_width = 44;
    int big_start_y = (max_y - big_height - 5) / 2;
    int big_start_x = (max_x - big_width) / 2;

    WINDOW *big_box = newwin(big_height, big_width, big_start_y, big_start_x);
    box(big_box, 0, 0);
    refresh();
    wrefresh(big_box);

    mvprintw(big_start_y + 1, big_start_x + 1, "1 - Play a game of chess.");
    mvprintw(big_start_y + 2, big_start_x + 1, "2 - Watch the replay of a game of chess.");
    mvprintw(big_start_y + 4, big_start_x + 1, "Enter anything else to exit.");
    mvprintw(big_start_y + 6, big_start_x + 24, "made by noitongadil");

    int small_height = 3;
    int small_width = 23;
    int small_start_y = (max_y / 2) - small_height + 5;
    int small_start_x = (max_x - small_width) / 2;

    WINDOW *small_box =
        newwin(small_height, small_width, small_start_y, small_start_x);
    box(small_box, 0, 0);
    refresh();

    char choice[1];
    mvwgetstr(small_box, 1, 1, choice);

    clear();

    return atoi(choice);
}
