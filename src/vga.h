#ifndef VGA_H
#define VGA_H

enum COLORS {
    BLACK,		    /* dark colors */
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,		/* light colors */
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};

/**
 * Initialize the graphics system.
 */
void initVGA(void);

/**
 * Clear all screen
 */
void clrscr(void);

void putpixel(int x, int y, char color);

void rectangle(int x, int y, int width, int height, char color);

/**
 * Bresenham’s circle drawing algorithm.
 * https://www.geeksforgeeks.org/bresenhams-circle-drawing-algorithm/
 */
void circle(int xc, int yc, int r, char color);

#endif