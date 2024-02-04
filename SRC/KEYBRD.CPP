#include "KEYBRD.H"

int kbhit(void) {
    int key;
    asm {
        mov ah, 0x01       
        int 0x16
        mov key, ax
        jz NoKey
    }
    asm {
        xor ah, ah
        int 0x16
        mov key, ax
    }
    NoKey:
    return key;
}