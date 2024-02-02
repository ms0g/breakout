#include "vga.h"

void initGFM(void) {
    asm {
        mov ah, 0h     // change video mode
        mov al, 13h    // 320x200x256
        int 10h        //interrupt
    }
}

void putPixel(int x, int y, char color) {
    asm {
        mov bh, 00h           
        mov al, [color]       
        mov cx, [x]           
        mov dx, [y]                    
        mov ah, 0Ch        
        int 10h          
    }
}

void drawRectangle(int x, int y, int width, int height, char color) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            putPixel(x + j, y + i, color);
        }
    }
}
  
   
