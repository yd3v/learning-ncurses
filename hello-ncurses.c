#include <ncurses.h>

int main(int argc, char *argv[]) {
	initscr(); // Init the screen
	printw("Hello, ncurses"); // The "printf" version of ncurses
	refresh(); // Refresh the screen to apply the changes
	getch(); // Just to do a pause
	endwin(); // Finish the screen

	return 0;

}
