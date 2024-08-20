.model small
.data
.code
public __waitvretrace
public __initMode
public __putpixel
; -------------------------------------------------------------
; void _Cdecl _waitvretrace(void)                             ;
; -------------------------------------------------------------
__waitvretrace proc
    cli
    ;If vert. retrace bit is set, wait for it to clear
v1: 
    mov dx, 03dah  ;dx <- VGA status register
    in al, dx      ;al <- status byte
    test al, 08h   ;is bit 3 (vertical retrace bit) set
    jnz v1         ;If so, wait for it to clear
    
    ;When it's cleared, wait for it to be set
v2: 
    mov dx, 03dah
    in al, dx
    test al, 08h
    jz v2           ;loop back till vert. retrace bit is newly set
    sti
    ret
__waitvretrace endp
; -------------------------------------------------------------
; void _Cdecl _initMode(int mode)                        ;
; -------------------------------------------------------------
__initMode proc
    push bp       
    mov bp, sp
    mov al, byte ptr [bp+4]
    xor ah, ah         
    int 10h
    mov sp, bp
    pop bp
    ret      
__initMode endp
; -------------------------------------------------------------
; void _Cdecl _putpixel(int x, int y, char color)             ;
; -------------------------------------------------------------
__putpixel proc
    push bp       
    mov bp, sp
    mov al, byte ptr [bp+8]
    mov dx, word ptr [bp+6]
    mov cx, word ptr [bp+4]
    mov ah, 0Ch
    xor bh, bh                
    int 10h
    mov sp, bp
    pop bp
    ret        
__putpixel endp