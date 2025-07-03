#ifndef RENDERER_H
#define RENDERER_H

void rndPutchar(int x, int y, char color, const int (*font)[5][5]);

void rndDrawRect(int x, int y, int width, int height, char color);

#endif