#include "VGA.H"
#include <malloc.h>
#include <string.h>
#include "CONF.H"

VGA::VGA() {
    videoMem = (unsigned char far*)0xA0000000L;
    backBuffer = (unsigned char far*)farmalloc(64000u);

    if (backBuffer) {
        asm {
            xor ah, ah      // change video mode
            mov al, 0x13    // 320x200x256
            int 0x10        //interrupt
        }

        _fmemset(backBuffer, 0, 64000u);
    } 
}

VGA::~VGA() {
    farfree(backBuffer);
}

void VGA::clrscr(char color) {
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

void VGA::clrBackBuffer(char color) {
    _fmemset(backBuffer, color, 64000u);
}

void VGA::putpixel_s(int x, int y, char color) {
    asm {
        mov ah, 0x0C
        mov al, color
        xor bh, bh             
        mov cx, x           
        mov dx, y    
        int 0x10          
    }
}

void VGA::putpixel_f(int x, int y, char color) {
    backBuffer[SCREEN_WIDTH * y + x] = color;
}

void VGA::waitVRetrace(void) {
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

void VGA::updateVideoMem(void) {
    waitVRetrace();

    _fmemcpy(videoMem, backBuffer, 64000u);
}
   
