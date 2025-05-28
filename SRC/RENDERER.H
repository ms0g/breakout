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
    void putchar(int x, int y, char color, const int (*font)[5][5]);

    void rectangle(int x, int y, int width, int height, char color);
    
    void clear(char color);

    void updateBuffer(void);

private:
    VGA vga;
};

#endif