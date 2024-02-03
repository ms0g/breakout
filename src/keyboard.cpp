#include "keyboard.h"

int kbhit(void) {
    asm {
        mov ah, 00h       
        int 16h   
    }
}