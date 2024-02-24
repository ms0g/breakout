#include "UI.H"
#include <STDLIB.H>
#include <STRING.H>
#include "RENDERER.H"
#include "UTILS.H"

#define SCORE_X 12
#define SCORE_Y 10
#define SCORE_ADJ 35
#define LIFE_X 200
#define LIFE_Y SCORE_Y
#define LIFE_ADJ 30
#define ADJ 6

UI::UI() {
    scoreText.pos.x = SCORE_X;
    scoreText.pos.y = SCORE_Y;
    scoreText.val = 0;
    scoreText.color = WHITE;

    scoreNum.pos.x = SCORE_X + SCORE_ADJ;
    scoreNum.pos.y = SCORE_Y;
    scoreNum.val = 0;
    scoreNum.color = WHITE;

    lifeText.pos.x = LIFE_X;
    lifeText.pos.y = LIFE_Y;
    lifeText.val = 0;
    lifeText.color = WHITE;

    lifeNum.pos.x = LIFE_X + LIFE_ADJ;
    lifeNum.pos.y = LIFE_Y;
    lifeNum.val = 0;
    lifeNum.color = WHITE;

    gameOverText.pos.x = 130;
    gameOverText.pos.y = 130;
    gameOverText.val = 0;
    gameOverText.color = WHITE;

    dynamicUIElements[0] = &scoreNum;
    dynamicUIElements[1] = &lifeNum;

    isGameOver = 0;

}

void UI::update(int score, int life) {
    scoreNum.val = score;
    lifeNum.val = life;
}

void UI::draw(Renderer* renderer) {
    drawText("SCORE:", scoreText.pos.x, scoreText.pos.y, scoreText.color, renderer);
    drawText("LIFE:", lifeText.pos.x, lifeText.pos.y, lifeText.color, renderer);

    for (int i = 0; i < 2; ++i) {
        char strNum[4];
        
        itoa(dynamicUIElements[i]->val, strNum, 10);
        
        drawText(
            strNum, 
            dynamicUIElements[i]->pos.x, 
            dynamicUIElements[i]->pos.y, 
            dynamicUIElements[i]->color, 
            renderer);
    }

    if (isGameOver) {
        drawText("GAME OVER", gameOverText.pos.x, gameOverText.pos.y, gameOverText.color, renderer);
    }
}

void UI::drawText(const char* s, int x, int y, char color, Renderer* renderer) {
    for (int i = 0; i < strlen(s); ++i) {
        renderer->putchar(x, y, color, asciiFontTable[(int)s[i]]);
        x += ADJ;
    }
}