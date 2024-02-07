#ifndef RENDERER_H
#define RENDERER_H

#include "VGA.H"

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

class Renderer {
public:
    void rectangle(int x, int y, int width, int height, char color);

    /**
     * Bresenham’s circle drawing algorithm.
     * https://www.geeksforgeeks.org/bresenhams-circle-drawing-algorithm/
     */
    void circle(int xc, int yc, int r, char color);
    
    void clear(char color);

    void updateBuffer();

private:
    void _circle(int xc, int yc, int x, int y, char color);

    VGA vga;

};

#endif