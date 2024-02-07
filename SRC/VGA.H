#ifndef VGA_H
#define VGA_H

class VGA {
public:
    VGA();

    ~VGA();
    
    void clrscr(char color);

    void clrBackBuffer(char color);
  
    void putpixel_s(int x, int y, char color);

    void putpixel_f(int x, int y, char color);

    void waitVRetrace(void);

    void updateVideoMem(void);

private:
    unsigned char far* videoMem;
    unsigned char far* backBuffer;
};

#endif