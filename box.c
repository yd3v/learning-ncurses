#include <ncurses.h>
#include <unistd.h>

void make_box(WINDOW *win) {

	box(win, 0, 0);
	refresh();
	mvwprintw(win, 0, 5, " to_char_code ");   // Print the string with the y and x offsets (0, 5)

}

int main(int argc, char *argv[]) {
	initscr(); // Init the screen
	noecho();  // Disable keyboard input stdout

	WINDOW *win = newwin(10, 60, 0, 3); // Create a WINDOW instance

	make_box(win);
	mvwprintw(win, 2, 4, "press a key to get the decimal value"); // ||
	wrefresh(win);
	while(1) {
		wmove(win, 3, 1);
		wrefresh(win);

		mvwprintw(win, 4, 4, "result: %d",(int) getch());	// Only to do a pause
		wclrtoeol(win);
		make_box(win);
		wrefresh(win);	// Refresh the Screen

	}
	endwin();	// Back terminal to normal mode
}
