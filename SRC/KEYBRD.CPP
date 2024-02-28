#include "KEYBRD.H"
#include <DOS.H>

#define IRQ_PORT    0x20
#define KBC_IRQ     0x09
#define KBC_PORT    0x60
#define KBC_SCP     0x61
#define KBC_BREAK   0x80
#define SCP_KBC_DIS 0x80

static volatile unsigned char _keys[256];

static void interrupt (*old_irq)(...);

static void interrupt kbc_irq_handler(...) {
    unsigned char code, val = 1;
    
    asm {
        cli
        in al, KBC_PORT
        mov code, al
        and al, KBC_BREAK
        jz PRESSED
        mov val, 0
        mov al, code
        sub al, KBC_BREAK
        mov code, al
    }
PRESSED:   
    _keys[code] = val;
    
    asm {
        in al, KBC_SCP
        mov bl, al
        or al, SCP_KBC_DIS
        out KBC_SCP, al
        mov al, bl
        out KBC_SCP, al
        mov al, 0x20
        out IRQ_PORT, al
        sti
    }
}

void initkb(void) {
    old_irq = getvect(KBC_IRQ);
    setvect(KBC_IRQ, kbc_irq_handler);
}

void exitkb(void) {
    setvect(KBC_IRQ, old_irq);
}

char kbhit(void) {
    char key;

    if (_keys[R_ARROW]) {
        key = R_ARROW;
    } else if (_keys[L_ARROW]) {
        key = L_ARROW;
    } else if (_keys[ESC]) {
        key = ESC;
    }
    return key;
}