#include "RENDERER.H"
#include "VGA.H"

void Renderer::renderRect(int x, int y, int width, int height, char color) {
    rectangle(x, y, width, height, color);
}

void Renderer::renderCircle(int xc, int yc, int r, char color) {
    circle(xc, yc, r, color);
}