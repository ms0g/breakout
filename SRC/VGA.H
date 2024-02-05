#ifndef VGA_H
#define VGA_H

/**
 * Initialize the graphics system.
 */
void initVGA(void);

/**
 * Clear all screen
 */
void v_clrscr(char color);

/**
 * Put pixel slowly 
 */
void s_putpixel(int x, int y, char color);

/**
 * Put pixel fastly 
 */
void f_putpixel(int x, int y, char color);

#endif