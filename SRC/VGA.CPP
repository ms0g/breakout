#include "VGA.H"

void initVGA(void) {
    asm {
        mov ah, 0x0     // change video mode
        mov al, 0x13    // 320x200x256
        int 0x10        //interrupt
    }
}

void clrscr(char color) {
    asm {
        xor al, al
        mov ah, 0x6
        xor bl, bl
        mov bh, [color]
        mov cx, 0x0
        mov dx, 0x182a 
        int 0x10 
    }
}

void putpixel(int x, int y, char color) {
    asm {
        mov bh, 0x0           
        mov al, [color]       
        mov cx, [x]           
        mov dx, [y]                    
        mov ah, 0x0C        
        int 0x10          
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
  
   
