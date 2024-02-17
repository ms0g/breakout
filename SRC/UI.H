#ifndef UI_H
#define UI_H

#include "FONTS.H"

class Renderer;
class UI {
public:
    UI();

    void update(int score, int life);
    
    void draw(Renderer* renderer);

private:
    struct UIElement {
        struct {
            int x;
            int y;
        } pos;
      
        int val;

        char color;
    };

    void drawText(char* s, int len, int x, int y, char color, Renderer* renderer);

    UIElement scoreText;
    UIElement scoreNum;

    UIElement lifeText;
    UIElement lifeNum;

    UIElement* dynamicElements[2];
};

#endif