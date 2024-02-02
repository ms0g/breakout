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
    DARKGRAY,		    /* light colors */
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
void initGFM(void);

void putpixel(int x, int y, char color);

void drawRectangle(int x, int y, int width, int height, char color);

#endif