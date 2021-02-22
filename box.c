#include <ncurses.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	initscr(); // Init the screen

	WINDOW *win = newwin(20, 40, 0, 3); // Create a WINDOW instance

	box(win, 0, 0); // Create the box with default border setup (0, 0)
	refresh();	// Refresh the Screen

	mvwprintw(win, 0, 5, "Box title");   // Print "Box title", with the y and x offsets (0, 5)
	mvwprintw(win, 1, 1, "Box content"); // ||

	wrefresh(win);  // Refresh the window
	getch();	// Only to do a pause

	endwin();	// Kill the screen
}
