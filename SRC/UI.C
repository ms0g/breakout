#include "UI.H"
#include <stdlib.h>
#include <string.h>
#include "FONTS.H"
#include "RENDERER.H"
#include "OBJPRTY.H"

#define SCORE_X 12
#define SCORE_Y 10
#define SCORE_ADJ 35
#define LIFE_X 200
#define LIFE_Y 10
#define LIFE_ADJ 30
#define ADJ 6

typedef struct {
    ObjectProperty property;
    
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
int isGameOver;

static void drawText(const char* s, int x, int y, char color);
static void drawNumber(int num, int x, int y, char color);

void uiInit(void) {
    scoreText.property.position.x = SCORE_X;
    scoreText.property.position.y = SCORE_Y;
    scoreText.property.color = 0xF;
    scoreText.val.str = "SCORE:";
    
    scoreNum.property.position.x = SCORE_X + SCORE_ADJ;
    scoreNum.property.position.y = SCORE_Y;
    scoreNum.property.color = 0xF;
    scoreNum.val.num = 0;

    lifeText.property.position.x = LIFE_X;
    lifeText.property.position.y = LIFE_Y;
    lifeText.property.color = 0xF;
    lifeText.val.str = "LIFE:";
   
    lifeNum.property.position.x = LIFE_X + LIFE_ADJ;
    lifeNum.property.position.y = LIFE_Y;
    lifeNum.property.color = 0xF;
    lifeNum.val.num = 0;
   
    gameOverText.property.position.x = 130;
    gameOverText.property.position.y = 130;
    gameOverText.property.color = 0xF;
    gameOverText.val.str = "GAME OVER";
   
    isGameOver = 0;
}

void uiUpdate(int score, int life) {
    scoreNum.val.num = score;
    lifeNum.val.num = life;
}

void uiDraw(void) {
    drawText(scoreText.val.str, scoreText.property.position.x, scoreText.property.position.y, scoreText.property.color);
    drawNumber(scoreNum.val.num, scoreNum.property.position.x, scoreNum.property.position.y, scoreNum.property.color);
    
    drawText(lifeText.val.str, lifeText.property.position.x, lifeText.property.position.y, lifeText.property.color);
    drawNumber(lifeNum.val.num, lifeNum.property.position.x, lifeNum.property.position.y, lifeNum.property.color);

    if (isGameOver) {
        drawText(gameOverText.val.str, gameOverText.property.position.x, gameOverText.property.position.y, gameOverText.property.color);
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
