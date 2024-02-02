#include "vga.h"

void initVGA(void) {
    asm {
        mov ah, 0h     // change video mode
        mov al, 13h    // 320x200x256
        int 10h        //interrupt
    }
}

void putpixel(int x, int y, char color) {
    asm {
        mov bh, 00h           
        mov al, [color]       
        mov cx, [x]           
        mov dx, [y]                    
        mov ah, 0Ch        
        int 10h          
    }
}

void rectangle(int x, int y, int width, int height, char color) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            putpixel(x + j, y + i, color);
        }
    }
}

static void _circle(int xc, int yc, int x, int y, char color) { 
    putpixel(xc+x, yc+y, color); 
    putpixel(xc-x, yc+y, color); 
    putpixel(xc+x, yc-y, color); 
    putpixel(xc-x, yc-y, color); 
    putpixel(xc+y, yc+x, color); 
    putpixel(xc-y, yc+x, color); 
    putpixel(xc+y, yc-x, color); 
    putpixel(xc-y, yc-x, color); 
}

void circle(int xc, int yc, int r, char color) { 
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
  
   
