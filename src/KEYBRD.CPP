#include "KEYBRD.H"

int kbhit(void) {
    asm {
        mov ah, 01h       
        int 16h
        jz NoKey
    }
    asm {
        mov ah, 00h
        int 16h
    }
    NoKey:
}