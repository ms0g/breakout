#include "VGA.H"

void initVGA(void) {
    asm {
        xor ah, ah      // change video mode
        mov al, 0x13    // 320x200x256
        int 0x10        //interrupt
    }
}

void v_clrscr(char color) {
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
        mov ah, 0x0C
        mov al, [color]
        xor bh, bh             
        mov cx, [x]           
        mov dx, [y]    
        int 0x10          
    }
}
   
