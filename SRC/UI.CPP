#include "UI.H"
#include <stdlib.h>
#include <string.h>
#include "RENDERER.H"
#include "FONTS.H"

#define SCORE_X 12
#define SCORE_Y 10
#define SCORE_ADJ 35
#define LIFE_X 200
#define LIFE_Y SCORE_Y
#define LIFE_ADJ 30
#define ADJ 6

UI::UI() {
    scoreText.position.x = SCORE_X;
    scoreText.position.y = SCORE_Y;
    scoreText.val = 0;
    scoreText.color = WHITE;

    scoreNum.position.x = SCORE_X + SCORE_ADJ;
    scoreNum.position.y = SCORE_Y;
    scoreNum.val = 0;
    scoreNum.color = WHITE;

    lifeText.position.x = LIFE_X;
    lifeText.position.y = LIFE_Y;
    lifeText.val = 0;
    lifeText.color = WHITE;

    lifeNum.position.x = LIFE_X + LIFE_ADJ;
    lifeNum.position.y = LIFE_Y;
    lifeNum.val = 0;
    lifeNum.color = WHITE;

    gameOverText.position.x = 130;
    gameOverText.position.y = 130;
    gameOverText.val = 0;
    gameOverText.color = WHITE;

    isGameOver = 0;

}

void UI::update(int score, int life) {
    scoreNum.val = score;
    lifeNum.val = life;
}

void UI::draw(Renderer* renderer) {
    drawText("SCORE:", scoreText.position.x, scoreText.position.y, scoreText.color, renderer);
    drawNumber(scoreNum.val, scoreNum.position.x, scoreNum.position.y, scoreNum.color, renderer);
    
    drawText("LIFE:", lifeText.position.x, lifeText.position.y, lifeText.color, renderer);
    drawNumber(lifeNum.val, lifeNum.position.x, lifeNum.position.y, lifeNum.color, renderer);

    if (isGameOver) {
        drawText("GAME OVER", gameOverText.position.x, gameOverText.position.y, gameOverText.color, renderer);
    }
}

void UI::drawText(const char* s, int x, int y, char color, Renderer* renderer) {
    for (int i = 0; i < strlen(s); ++i) {
        renderer->putchar(x, y, color, asciiFontTable[(int)s[i]]);
        x += ADJ;
    }
}

void UI::drawNumber(int value, int x, int y, char color, Renderer* renderer) {
    char strNum[4];

    itoa(value, strNum, 10);
        
    drawText(strNum, x, y, color, renderer);
}