#include "UI.H"
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
    drawText("SCORE:", 6, scoreText.pos.x, scoreText.pos.y, scoreText.color, renderer);
    drawText("LIFE:", 5 , lifeText.pos.x, lifeText.pos.y, lifeText.color, renderer);

    for (int i = 0; i < 2; ++i) {
        string str_num = to_string(dynamicElements[i]->val);
        
        do {
            int index = (str_num.size - 1);
            
            if (index < 0) break;

            renderer->putchar(
                dynamicElements[i]->pos.x, 
                dynamicElements[i]->pos.y, 
                dynamicElements[i]->color, 
                asciiFontTable[(int)str_num.ptr[index]]);
            
            dynamicElements[i]->pos.x += ADJ;
        } while (str_num.size--); 
    }

    scoreNum.pos.x = SCORE_X + SCORE_ADJ;
    lifeNum.pos.x = LIFE_X + LIFE_ADJ;
}

void UI::drawText(char* s, int len, int x, int y, char color, Renderer* renderer) {
    for (int i = 0; i < len; ++i) {
        renderer->putchar(x, y, color, asciiFontTable[(int)s[i]]);
        x += ADJ;
    }
}