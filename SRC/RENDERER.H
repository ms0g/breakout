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
    void putchar(int x, int y, char color, const int (*font)[5][5]) const;

    void rectangle(int x, int y, int width, int height, char color) const;
    
    void clear(char color) const;

    void updateBuffer(void) const;

private:
    VGA vga;
};

#endif