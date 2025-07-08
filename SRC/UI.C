#include "UI.H"
#include <stdlib.h>
#include <string.h>
#include "FONTS.H"
#include "RENDERER.H"
#include "GAMEOBJ.H"

#define SCORE_X 12
#define SCORE_Y 10
#define SCORE_ADJ 35
#define LIFE_X 200
#define LIFE_Y 10
#define LIFE_ADJ 30
#define ADJ 6

typedef struct {
    GameObject base;
    
    union {
        int num;
        const char* str;
    } val;
} UIElement;

static UIElement scoreText;
static UIElement scoreNum;
static UIElement lifeText;
static UIElement lifeNum;
static UIElement gameOverText;

static void drawText(const char* s, int x, int y, char color);
static void drawNumber(int num, int x, int y, char color);

void uiInit(void) {
    scoreText.base.position.x = SCORE_X;
    scoreText.base.position.y = SCORE_Y;
    scoreText.base.color = 0xF;
    scoreText.val.str = "SCORE:";
    
    scoreNum.base.position.x = SCORE_X + SCORE_ADJ;
    scoreNum.base.position.y = SCORE_Y;
    scoreNum.base.color = 0xF;
    scoreNum.val.num = 0;

    lifeText.base.position.x = LIFE_X;
    lifeText.base.position.y = LIFE_Y;
    lifeText.base.color = 0xF;
    lifeText.val.str = "LIFE:";
   
    lifeNum.base.position.x = LIFE_X + LIFE_ADJ;
    lifeNum.base.position.y = LIFE_Y;
    lifeNum.base.color = 0xF;
    lifeNum.val.num = 0;
   
    gameOverText.base.position.x = 130;
    gameOverText.base.position.y = 130;
    gameOverText.base.color = 0xF;
    gameOverText.val.str = "GAME OVER";
}

void uiUpdate(int score, int life) {
    scoreNum.val.num = score;
    lifeNum.val.num = life;
}

void uiDraw(int isGameOver) {
    drawText(scoreText.val.str, scoreText.base.position.x, scoreText.base.position.y, scoreText.base.color);
    drawNumber(scoreNum.val.num, scoreNum.base.position.x, scoreNum.base.position.y, scoreNum.base.color);
    
    drawText(lifeText.val.str, lifeText.base.position.x, lifeText.base.position.y, lifeText.base.color);
    drawNumber(lifeNum.val.num, lifeNum.base.position.x, lifeNum.base.position.y, lifeNum.base.color);

    if (isGameOver) {
        drawText(gameOverText.val.str, gameOverText.base.position.x, gameOverText.base.position.y, gameOverText.base.color);
    }
}

static void drawText(const char* s, int x, int y, char color) {
    int i;
    for (i = 0; i < s[i] != '\0'; ++i) {
        rndPutchar(x, y, color, asciiFontTable[(int)s[i]]);
        x += ADJ;
    }
}

static void drawNumber(int num, int x, int y, char color) {
    char strNum[6];

    itoa(num, strNum, 10);
        
    drawText(strNum, x, y, color);
}
