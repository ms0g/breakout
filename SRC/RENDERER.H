#ifndef RENDERER_H
#define RENDERER_H

class Renderer {
public:
    void drawRect(int x, int y, int width, int height, char color);

    void drawCircle(int xc, int yc, int r, char color);
};

#endif