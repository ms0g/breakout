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

    void drawText(const char* s, int x, int y, char color, Renderer* renderer);

    UIElement scoreText;
    UIElement scoreNum;

    UIElement lifeText;
    UIElement lifeNum;

    UIElement* dynamicUIElements[2];
};

#endif