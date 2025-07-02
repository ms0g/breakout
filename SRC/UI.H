#ifndef UI_H
#define UI_H

#ifdef __cplusplus
extern "C" {
#endif

extern int isGameOver;

void uiInit(void);

void uiUpdate(int score, int life);

void uiDraw(void);

#ifdef __cplusplus
}   
#endif
#endif