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

void putpixel(int x, int y, char color);

#endif