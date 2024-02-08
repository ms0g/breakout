#include "UI.H"
#include "RENDERER.H"
#include "UTILS.H"

#define SCORE_X 12
#define SCORE_Y 10
#define SCORE_GAP 35

#define ADJ 6

#define LIFE_X 200
#define LIFE_Y SCORE_Y
#define LIFE_GAP 30

UI::UI() {
    scoreText.pos.x = SCORE_X;
    scoreText.pos.y = SCORE_Y;
    scoreText.val = 0;
    scoreText.color = WHITE;

    scoreValue.pos.x = SCORE_X + SCORE_GAP;
    scoreValue.pos.y = SCORE_Y;
    scoreValue.val = 0;
    scoreValue.color = WHITE;

    
    lifeText.pos.x = LIFE_X;
    lifeText.pos.y = LIFE_Y;
    lifeText.val = 0;
    lifeText.color = WHITE;

    lifeValue.pos.x = LIFE_X + LIFE_GAP;
    lifeValue.pos.y = LIFE_Y;
    lifeValue.val = 0;
    lifeValue.color = WHITE;

    dynamicElements[0] = &scoreValue;
    dynamicElements[1] = &lifeValue;

}

void UI::update(int score, int life) {
    scoreValue.val = score;
    lifeValue.val = life;
}

void UI::draw(Renderer* renderer) {
    drawChar(renderer, &scoreText, &S);
    scoreText.pos.x += ADJ;
    drawChar(renderer, &scoreText, &C);
    scoreText.pos.x += ADJ;
    drawChar(renderer, &scoreText, &O);
    scoreText.pos.x += ADJ;
    drawChar(renderer, &scoreText, &R);
    scoreText.pos.x += ADJ;
    drawChar(renderer, &scoreText, &E);
    scoreText.pos.x += ADJ;
    drawChar(renderer, &scoreText, &COLON);

    drawChar(renderer, &lifeText, &L);
    lifeText.pos.x += ADJ;
    drawChar(renderer, &lifeText, &I);
    lifeText.pos.x += ADJ;
    drawChar(renderer, &lifeText, &F);
    lifeText.pos.x += ADJ;
    drawChar(renderer, &lifeText, &E);
    lifeText.pos.x += ADJ;
    drawChar(renderer, &lifeText, &COLON);

    for (int i = 0; i < 2; ++i) {
        string str_num = to_string(dynamicElements[i]->val);
        
        do {
            int index = (str_num.size - 1);
            
            if (index < 0) break;
            
            // turn into integer
            int num = str_num.ptr[index] - '0';

            drawChar(renderer, dynamicElements[i], digitFontTable[num]);
            
            dynamicElements[i]->pos.x += ADJ;
        } while (str_num.size--); 
    }

    scoreValue.pos.x = SCORE_X + SCORE_GAP;
    scoreText.pos.x = SCORE_X;

    lifeValue.pos.x = LIFE_X + LIFE_GAP;
    lifeText.pos.x = LIFE_X;
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