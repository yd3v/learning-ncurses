#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]) {

	int window_height = 20;
	int window_width = 60;
	char *text = "MOVE-ME TO SEE THE COLORS :D";
	time_t t;

	srand((unsigned)time(&t));

	initscr();
	noecho();

	WINDOW *win = newwin(window_height, window_width, 0, 0);
	WINDOW *stats = newwin(7, window_width, window_height, 0);

	box(win, 0, 0);
	refresh();
	box(stats, 0, 0);


	if(has_colors() == FALSE) { // Check if the therminal suport colors
		mvwprintw(win, 2, 2, "your terminal don't suport colors :(");
		return 1;
	} else {
		mvwprintw(win, 3, 2, "great, your terminal support colors !");
		mvwprintw(win, 4, 2, "press any arrow key to start");

	}

	start_color(); // This is necessary to work with colors

	init_pair(1, COLOR_BLACK, COLOR_WHITE); // Init a color pair to use as attr
	init_pair(2, COLOR_BLACK, COLOR_RED);
	init_pair(3, COLOR_BLACK, COLOR_GREEN);
	init_pair(4, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(5, COLOR_BLACK, COLOR_YELLOW);
	init_pair(6, COLOR_BLACK, COLOR_BLUE);
	init_pair(7, COLOR_BLACK, COLOR_CYAN);

	init_pair(8, COLOR_RED, COLOR_WHITE);
	init_pair(9, COLOR_RED, COLOR_YELLOW);
	init_pair(10, COLOR_RED, COLOR_GREEN);
	init_pair(11, COLOR_RED, COLOR_CYAN);
	init_pair(12, COLOR_RED, COLOR_BLUE);
	init_pair(13, COLOR_RED, COLOR_MAGENTA);
	init_pair(14, COLOR_RED, COLOR_BLACK);


	init_pair(15, COLOR_GREEN, COLOR_WHITE);
	init_pair(16, COLOR_GREEN, COLOR_YELLOW);
	init_pair(17, COLOR_GREEN, COLOR_RED);
	init_pair(18, COLOR_GREEN, COLOR_CYAN);
	init_pair(19, COLOR_GREEN, COLOR_BLUE);
	init_pair(20, COLOR_GREEN, COLOR_MAGENTA);
	init_pair(21, COLOR_GREEN, COLOR_BLACK);

	wattron(win, COLOR_PAIR(1)); // Apply the attr
	mvwprintw(win, 1, 3, "now let's learn how to use colors");
	wattroff(win, COLOR_PAIR(1)); // Remove the attr

	move(5, 3);
	wrefresh(win);
	int y_index = (int)(window_height/2);

	int x_index = (int)(window_width/2)-(int)(strlen(text)/2)-2;

	int ch;

	while(1) {

		ch = getch();

		int randint;
		randint = (rand() % 21)+1;

		if(y_index == 1 && ch == 65) {
			y_index = window_height-1;
		} else if (y_index == window_height - 2 && ch == 66) {
			y_index = 0;
		}


		if(x_index <= 1 && ch == 68) {
			x_index = window_width-1;
		} else if (x_index >= window_width - 1 && ch == 67) {
			x_index = 0;
		}



		switch(ch) {
			case 65:
				y_index-=1;
				break;
			case 66:
				y_index+=1;
				break;
			case 67:
				x_index+=2;
				break;
			case 68:
				x_index-=2;
				break;
			default:
				continue;
				break;
		}

		wclear(win);
		wclear(stats);

		mvwprintw(stats, 1, 2, "color pair        :");
		mvwprintw(stats, 3, 2, "key pressed       :");
		mvwprintw(stats, 5, 2, "x / y coordinates :");

		wattron(stats, COLOR_PAIR(randint));
		mvwprintw(stats, 1, 25, "%d", randint);
		mvwprintw(stats, 3, 25, "%d", ch);
		mvwprintw(stats, 5, 25, "%d, %d", x_index, y_index);
		wattroff(stats, COLOR_PAIR(randint));

//		wmove(win, y_index, x_index);
		wattron(win, COLOR_PAIR(randint));
		mvwprintw(win, y_index, x_index, text);
		wattroff(win, COLOR_PAIR(randint));

		box(win, 0, 0);
		box(stats, 0, 0);

		wrefresh(stats);
		wrefresh(win);

	}
	endwin();
	return 0;
}
