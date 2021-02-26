#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	initscr();
	int window_width = 40;
	int window_height = 20;

	WINDOW *win = newwin(window_height, window_width, 0, 0);
//	box(win, 0, 0);

	start_color();
	init_pair(1, 0, COLOR_GREEN);
	init_pair(2, 0, COLOR_RED);
	int color_counter = 2;

	while(1) {
		usleep(100000);
		color_counter = (color_counter==1?2:1);
		wattron(win, COLOR_PAIR(color_counter));


		int _ = 0;

		wclear(win);
		for(_; _ < 680; _++) {
			wprintw(win, " ");
		}

		refresh();
		wrefresh(win);
	}

	getch();
	endwin();

	return 0;
}
