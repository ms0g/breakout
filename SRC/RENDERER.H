#ifndef RENDERER_H
#define RENDERER_H

#include "VGA.H"

class Renderer {
public:
    Renderer();
    ~Renderer();
    void putchar(int x, int y, char color, const int (*font)[5][5]) const;

    void rectangle(int x, int y, int width, int height, char color) const;
    
    void clear(char color) const;

    void updateBuffer(void) const;
};

#endif