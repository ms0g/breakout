#include "UI.H"
#include <stdlib.h>
#include <string.h>
#include "FONTS.H"
#include "RENDERER.H"

#define SCORE_X 12
#define SCORE_Y 10
#define SCORE_ADJ 35
#define LIFE_X 200
#define LIFE_Y 10
#define LIFE_ADJ 30
#define ADJ 6

typedef struct {
    struct {
        int x;
        int y;
    } position;
    
    union {
        int num;
        const char* str;
    } val;
    
    char color;
} UIElement;

static UIElement scoreText;
static UIElement scoreNum;
static UIElement lifeText;
static UIElement lifeNum;
static UIElement gameOverText;
int isGameOver;

static void drawText(const char* s, int x, int y, char color);
static void drawNumber(int num, int x, int y, char color);

void uiInit(void) {
    scoreText.position.x = SCORE_X;
    scoreText.position.y = SCORE_Y;
    scoreText.val.str = "SCORE:";
    scoreText.color = 0xF;

    scoreNum.position.x = SCORE_X + SCORE_ADJ;
    scoreNum.position.y = SCORE_Y;
    scoreNum.val.num = 0;
    scoreNum.color = 0xF;

    lifeText.position.x = LIFE_X;
    lifeText.position.y = LIFE_Y;
    lifeText.val.str = "LIFE:";
    lifeText.color = 0xF;

    lifeNum.position.x = LIFE_X + LIFE_ADJ;
    lifeNum.position.y = LIFE_Y;
    lifeNum.val.num = 0;
    lifeNum.color = 0xF;

    gameOverText.position.x = 130;
    gameOverText.position.y = 130;
    gameOverText.val.str = "GAME OVER";
    gameOverText.color = 0xF;

    isGameOver = 0;
}

void uiUpdate(int score, int life) {
    scoreNum.val.num = score;
    lifeNum.val.num = life;
}

void uiDraw(void) {
    drawText(scoreText.val.str, scoreText.position.x, scoreText.position.y, scoreText.color);
    drawNumber(scoreNum.val.num, scoreNum.position.x, scoreNum.position.y, scoreNum.color);
    
    drawText(lifeText.val.str, lifeText.position.x, lifeText.position.y, lifeText.color);
    drawNumber(lifeNum.val.num, lifeNum.position.x, lifeNum.position.y, lifeNum.color);

    if (isGameOver) {
        drawText(gameOverText.val.str, gameOverText.position.x, gameOverText.position.y, gameOverText.color);
    }
}

static void drawText(const char* s, int x, int y, char color) {
    int i;
    for (i = 0; i < strlen(s); ++i) {
        rndPutchar(x, y, color, asciiFontTable[(int)s[i]]);
        x += ADJ;
    }
}

static void drawNumber(int num, int x, int y, char color) {
    char strNum[4];

    itoa(num, strNum, 10);
        
    drawText(strNum, x, y, color);
}
