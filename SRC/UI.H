#ifndef UI_H
#define UI_H

extern int isGameOver;

void uiInit(void);

void uiUpdate(int score, int life);

void uiDraw(void);

#endif