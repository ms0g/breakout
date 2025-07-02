#include "RENDERER.H"

Renderer::Renderer() {
    vgaInit();
}
Renderer::~Renderer() {
    vgaExit();
}

void Renderer::putchar(int x, int y, char color, const int (*font)[5][5]) const {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if ((*font)[j][i]) {
                vgaPutPixel(x + i, y + j, color);
            }
        }
    }
}

void Renderer::rectangle(int x, int y, int width, int height, char color) const {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            vgaPutPixel(x + i, y + j, color);
        }
    }
}

void Renderer::clear(char color) const {
    vgaClearOffscreen(color);
}

void Renderer::updateBuffer(void) const {
    vgaUpdateVram();
}