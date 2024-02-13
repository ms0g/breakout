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

    scoreValue.pos.x = SCORE_X + SCORE_ADJ;
    scoreValue.pos.y = SCORE_Y;
    scoreValue.val = 0;
    scoreValue.color = WHITE;

    
    lifeText.pos.x = LIFE_X;
    lifeText.pos.y = LIFE_Y;
    lifeText.val = 0;
    lifeText.color = WHITE;

    lifeValue.pos.x = LIFE_X + LIFE_ADJ;
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
    drawTexts(renderer);

    for (int i = 0; i < 2; ++i) {
        string str_num = to_string(dynamicElements[i]->val);
        
        do {
            int index = (str_num.size - 1);
            
            if (index < 0) break;
            
            // turn into integer
            int num = str_num.ptr[index] - '0';

            renderer->putchar(dynamicElements[i]->pos.x, dynamicElements[i]->pos.y, dynamicElements[i]->color, digitFontTable[num]);
            
            dynamicElements[i]->pos.x += ADJ;
        } while (str_num.size--); 
    }

    scoreValue.pos.x = SCORE_X + SCORE_ADJ;
    lifeValue.pos.x = LIFE_X + LIFE_ADJ;
    
}

void UI::drawTexts(Renderer* renderer) {
    renderer->putchar(scoreText.pos.x, scoreText.pos.y, scoreText.color, &S);
    scoreText.pos.x += ADJ;
    renderer->putchar(scoreText.pos.x, scoreText.pos.y, scoreText.color, &C);
    scoreText.pos.x += ADJ;
    renderer->putchar(scoreText.pos.x, scoreText.pos.y, scoreText.color, &O);
    scoreText.pos.x += ADJ;
    renderer->putchar(scoreText.pos.x, scoreText.pos.y, scoreText.color, &R);
    scoreText.pos.x += ADJ;
    renderer->putchar(scoreText.pos.x, scoreText.pos.y, scoreText.color, &E);
    scoreText.pos.x += ADJ;
    renderer->putchar(scoreText.pos.x, scoreText.pos.y, scoreText.color, &COLON);

    renderer->putchar(lifeText.pos.x, lifeText.pos.y, lifeText.color, &L);
    lifeText.pos.x += ADJ;
    renderer->putchar(lifeText.pos.x, lifeText.pos.y, lifeText.color, &I);
    lifeText.pos.x += ADJ;
    renderer->putchar(lifeText.pos.x, lifeText.pos.y, lifeText.color, &F);
    lifeText.pos.x += ADJ;
    renderer->putchar(lifeText.pos.x, lifeText.pos.y, lifeText.color, &E);
    lifeText.pos.x += ADJ;
    renderer->putchar(lifeText.pos.x, lifeText.pos.y, lifeText.color, &COLON);

    scoreText.pos.x = SCORE_X;
    lifeText.pos.x = LIFE_X;
}