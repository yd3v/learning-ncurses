

#include <ncurses.h>

int main(int argc, char *argv[]) {
	initscr();
	WINDOW *win = newwin(20, 40, 0, 3);

	refresh();
	box(win, 0, 0);

	mvwprintw(win, 0, 5, "Box title");
	mvwprintw(win, 1, 1, "Box content");
	mvwprintw(win, 2, 1, "Box content line 2");

	wrefresh(win);
	getch();
	endwin();
}
