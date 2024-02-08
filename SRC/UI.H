#ifndef UI_H
#define UI_H

#include "FONTS.H"

class Renderer;
class UI {
public:
    UI();

    void update(int value);
    
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

    void drawChar(Renderer* renderer, UIElement* uiElement, const int (*font)[FONT_SIZE][FONT_SIZE]);

    UIElement scoreText;
    UIElement scoreValue;
    UIElement life;
};

#endif