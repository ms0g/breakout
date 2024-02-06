#include "VGA.H"

unsigned char far* videoMem = (unsigned char far*)0xA0000000L;

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
        mov bh, color
        mov cx, 0x0
        mov dx, 0x182a 
        int 0x10 
    }
}

void s_putpixel(int x, int y, char color) {
    asm {
        mov ah, 0x0C
        mov al, color
        xor bh, bh             
        mov cx, x           
        mov dx, y    
        int 0x10          
    }
}

void f_putpixel(int x, int y, char color) {
    unsigned short offset = 320 * y + x;
    videoMem[offset] = color;
}

void waitVRetrace(void) {
    asm {
        cli
    }
v1: 
    asm {
        mov dx, 0x03da
        in al, dx
        test al, 0x08
        jnz v1
    }
v2: 
    asm {
        mov dx, 0x03da
        in al, dx
        test al, 0x08
        jz v2

        sti
    }
}
   
