#include "UI.H"
#include "RENDERER.H"
#include "UTILS.H"
#include <iostream.h>

#define SCORE_X 10
#define SCORE_Y 10
#define SCORE_GAP 6

UI::UI() {
    score.pos.x = SCORE_X;
    score.pos.y = SCORE_Y;
    score.val = 0;
    score.color = WHITE;
}

void UI::update(int value) {
    score.val = value;
}

void UI::draw(Renderer* renderer) {

    string str_num = to_string(score.val);
    
    do {
        int i = (str_num.size - 1);
        
        if (i < 0) break;
        
        // turn into integer
        int index = str_num.ptr[i] - '0';

        drawChar(renderer, digitTable[index]);
        
        score.pos.x += SCORE_GAP;
    } while (str_num.size--);
    
    score.pos.x = SCORE_X;
}

void UI::drawChar(Renderer* renderer, const int (*font)[FONT_SIZE][FONT_SIZE]) {
    for (int i = 0; i < FONT_SIZE; ++i) {
        for (int j = 0; j < FONT_SIZE; ++j) {
            if ((*font)[i][j]) {
                renderer->putpixel(score.pos.x + j, score.pos.y + i, score.color);
            }
        }
    }
}