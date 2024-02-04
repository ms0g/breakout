#include "KEYBRD.H"

int kbhit(void) {
    asm {
        mov ah, 0x01       
        int 0x16
        jz NoKey
    }
    asm {
        xor ah, ah
        int 0x16
    }
    NoKey:
}