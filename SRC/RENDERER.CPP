#include "RENDERER.H"

void Renderer::putpixel(int x, int y, char color) {
    vga.putpixel_f(x, y, color);
}

void Renderer::rectangle(int x, int y, int width, int height, char color) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            vga.putpixel_f(x + j, y + i, color);
        }
    }
}

void Renderer::circle(int xc, int yc, int r, char color) {
    int x = 0, y = r; 
    int d = 3 - 2 * r;

    _circle(xc, yc, x, y, color); 
    
    while (y >= x) { 
        // for each pixel we will 
        // draw all eight pixels 
          
        x++; 
  
        // check for decision parameter 
        // and correspondingly  
        // update d, x, y 
        if (d > 0) { 
            y--;  
            d = d + 4 * (x - y) + 10; 
        } else {
            d = d + 4 * x + 6;
        }
             
        _circle(xc, yc, x, y, color);
    }
}

void Renderer::_circle(int xc, int yc, int x, int y, char color) { 
    vga.putpixel_f(xc+x, yc+y, color); 
    vga.putpixel_f(xc-x, yc+y, color); 
    vga.putpixel_f(xc+x, yc-y, color); 
    vga.putpixel_f(xc-x, yc-y, color); 
    vga.putpixel_f(xc+y, yc+x, color); 
    vga.putpixel_f(xc-y, yc+x, color); 
    vga.putpixel_f(xc+y, yc-x, color); 
    vga.putpixel_f(xc-y, yc-x, color); 
}

void Renderer::clear(char color) {
    vga.clrBackBuffer(color);
}

void Renderer::updateBuffer(void) {
    vga.updateVideoMem();
}