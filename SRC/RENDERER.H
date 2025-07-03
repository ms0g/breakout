#ifndef RENDERER_H
#define RENDERER_H

void rndInit(void);

void rndExit(void);

void rndPutchar(int x, int y, char color, const int (*font)[5][5]);

void rndDrawRect(int x, int y, int width, int height, char color);

void rndClear(char color);

void rndUpdateBuffer(void);

#endif