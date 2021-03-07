
#include <ncurses.h>
#include <pthread.h>
#include <unistd.h>

int wwidth = 60, wheight = 27;
int direction_code = 67;

void *move_thread(void *win) {
	int x_pos = 2, y_pos = 2;
	while(1) {
		box(win, 0, 0);
		wrefresh(win);
		usleep(50000);
		wclear(win);

		x_pos = x_pos <= wwidth ? x_pos : 2;
		x_pos = x_pos < 2 ? wwidth : x_pos;

		y_pos = y_pos <= (wheight-2) ? y_pos : 2;
		y_pos = y_pos < 2 ? wheight-2 : y_pos;

		switch(direction_code) {
			case 65:
				y_pos--;
				break;
			case 66:
				y_pos++;
				break;
			case 67:
				x_pos++;
				break;
			case 68:
				x_pos--;
				break;
			default:
				break;
		}

		wmove(win, y_pos, x_pos);
		wprintw(win, "[ %d, %d ]", x_pos, y_pos);
		refresh();
	}
}

int main(int argc, char *argv[]) {
	initscr();
	noecho();
	WINDOW *win = newwin(wheight, wwidth, 0, 0);
	box(win, 0, 0);
	refresh();
	wrefresh(win);

	pthread_t thread_id;
	void *thread_res;
	int rstatus;
	rstatus  = pthread_create(&thread_id, NULL, (void *)move_thread, (void *)win); // thread id, null,
									// rotina, argumentos
	if(rstatus) {
		printw("erro ao criar thread\n");
		refresh();
		return 1;
 	}


	while(1) {
		char direction;
		direction = getch();
		direction_code = (int) ( direction >= 65 && direction<=68 ) ? direction : direction_code;
	}
	pthread_join(thread_id, (void *)thread_res);

	endwin();
	return 0;
}
