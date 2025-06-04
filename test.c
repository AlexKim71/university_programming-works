#include <curses.h>
#include <stdlib.h>

#define SIZE 5

int main() {
    int array[SIZE][SIZE];
    int i, j;
    int product = 1;
    int non_even_count = 0;

    // Initialize curses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Check if the terminal supports color
    if(has_colors() == FALSE) {
        endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);    // For highlighted elements
    init_pair(2, COLOR_GREEN, COLOR_BLACK); // For modified elements

    // Create a window for input and display
    WINDOW *win = newwin(SIZE + 6, SIZE * 6 + 2, 0, 0);
    box(win, 0, 0); // Draw a box around the window

    // Input elements
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            mvwprintw(win, i + 1, j * 6 + 1, "Enter [%d][%d]: ", i, j);
            wrefresh(win);
            scanw("%d", &array[i][j]);
        }
    }

    // Clear the window for redisplay
    werase(win);
    box(win, 0, 0);

    // Display the array
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            mvwprintw(win, i + 1, j * 6 + 1, "%d", array[i][j]);
        }
    }
    wrefresh(win);

    // Calculate the product of elements above the main diagonal
    for(i = 0; i < SIZE; i++) {
        for(j = i + 1; j < SIZE; j++) {
            product *= array[i][j];
        }
    }

    // Replace non-even elements with the product
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(array[i][j] % 2 != 0) {
                array[i][j] = product;
                non_even_count++;
            }
        }
    }

    // Pause for 2 seconds
    napms(2000);

    // Change the color of the window to green
    wbkgd(win, COLOR_PAIR(2));
    werase(win);
    box(win, 0, 0);

    // Display the modified array with modified elements highlighted in red
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(array[i][j] == product) {
                attron(COLOR_PAIR(1));
                mvwprintw(win, i + 1, j * 6 + 1, "%d", array[i][j]);
                attroff(COLOR_PAIR(1));
            } else {
                mvwprintw(win, i + 1, j * 6 + 1, "%d", array[i][j]);
            }
        }
    }
    wrefresh(win);

    // Print the product and number of replacements
    mvwprintw(win, SIZE + 2, 1, "Product above diagonal: %d", product);
    mvwprintw(win, SIZE + 3, 1, "Number of replacements: %d", non_even_count);

    // Wait for another 2 seconds
    napms(2000);

    // End curses
    delwin(win);
    endwin();

    return 0;
}