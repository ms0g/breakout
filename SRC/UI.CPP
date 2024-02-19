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

    dynamicElements[0] = &scoreNum;
    dynamicElements[1] = &lifeNum;

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
        
        itoa(dynamicElements[i]->val, strNum, 10);
        
        drawText(
            strNum, 
            dynamicElements[i]->pos.x, 
            dynamicElements[i]->pos.y, 
            dynamicElements[i]->color, 
            renderer);
    }
}

void UI::drawText(const char* s, int x, int y, char color, Renderer* renderer) {
    for (int i = 0; i < strlen(s); ++i) {
        renderer->putchar(x, y, color, asciiFontTable[(int)s[i]]);
        x += ADJ;
    }
}