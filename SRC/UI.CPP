#include "UI.H"
#include "RENDERER.H"
#include "UTILS.H"
#include <iostream.h>

#define SCORE_X 10
#define SCORE_Y 10
#define SCORE_GAP 6
#define SCORE_TXT_GAP 35

UI::UI() {
    scoreText.pos.x = SCORE_X;
    scoreText.pos.y = SCORE_Y;
    scoreText.val = 0;
    scoreText.color = WHITE;

    scoreValue.pos.x = SCORE_X + SCORE_TXT_GAP;
    scoreValue.pos.y = SCORE_Y;
    scoreValue.val = 0;
    scoreValue.color = WHITE;

}

void UI::update(int value) {
    scoreValue.val = value;
}

void UI::draw(Renderer* renderer) {
    drawChar(renderer, &scoreText, &S);
    scoreText.pos.x += SCORE_GAP;
    drawChar(renderer, &scoreText, &C);
    scoreText.pos.x += SCORE_GAP;
    drawChar(renderer, &scoreText, &O);
    scoreText.pos.x += SCORE_GAP;
    drawChar(renderer, &scoreText, &R);
    scoreText.pos.x += SCORE_GAP;
    drawChar(renderer, &scoreText, &E);
    scoreText.pos.x += SCORE_GAP;
    drawChar(renderer, &scoreText, &COLON);

    string str_num = to_string(scoreValue.val);
    
    do {
        int i = (str_num.size - 1);
        
        if (i < 0) break;
        
        // turn into integer
        int index = str_num.ptr[i] - '0';

        drawChar(renderer, &scoreValue, digitTable[index]);
        
        scoreValue.pos.x += SCORE_GAP;
    } while (str_num.size--);
    
    scoreValue.pos.x = SCORE_X + SCORE_TXT_GAP;
    scoreText.pos.x = SCORE_X;
}

void UI::drawChar(Renderer* renderer, UIElement* uiElement, const int (*font)[FONT_SIZE][FONT_SIZE]) {
    for (int i = 0; i < FONT_SIZE; ++i) {
        for (int j = 0; j < FONT_SIZE; ++j) {
            if ((*font)[i][j]) {
                renderer->putpixel(uiElement->pos.x + j, uiElement->pos.y + i, uiElement->color);
            }
        }
    }
}