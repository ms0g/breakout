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
    void drawChar(Renderer* renderer, const int (*font)[FONT_SIZE][FONT_SIZE]);

    struct UIElement {
        struct {
            int x;
            int y;
        } pos;
      
        int val;

        char color;
    };

    UIElement score;
    UIElement life;
};

#endif