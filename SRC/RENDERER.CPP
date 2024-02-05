#include "RENDERER.H"
#include "VGA.H"

Renderer::Renderer() {
    initVGA();
}
void Renderer::drawRect(int x, int y, int width, int height, char color) {
    rectangle(x, y, width, height, color);
}

void Renderer::drawCircle(int xc, int yc, int r, char color) {
    circle(xc, yc, r, color);
}