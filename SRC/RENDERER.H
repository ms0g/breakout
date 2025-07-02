#ifndef RENDERER_H
#define RENDERER_H

#include "VGA.H"

#ifdef __cplusplus
extern "C" {
#endif

void rndInit(void);

void rndExit(void);

void rndPutchar(int x, int y, char color, const int (*font)[5][5]);

void rndDrawRect(int x, int y, int width, int height, char color);

void rndClear(char color);

void rndUpdateBuffer(void);
#ifdef __cplusplus
}
#endif

#endif