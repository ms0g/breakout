#ifndef RENDERER_H
#define RENDERER_H

class Renderer {
public:
    void renderRect(int x, int y, int width, int height, char color);

    void renderCircle(int xc, int yc, int r, char color);
};

#endif