#include "src/headers/PDCurses/curses.h"
#include "stdlib.h"
#include "stdio.h"

int main()

{

initscr();

wclear(stdscr);

printw("hello world\n");

wrefresh(stdscr);

system("pause");

endwin();

}