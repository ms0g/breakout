#ifndef UI_H
#define UI_H

class Renderer;
class UI {
public:
    UI();

    void update(int score, int life);
    
    void draw(const Renderer* renderer);

    int isGameOver;

private:
    struct UIElement {
        struct {
            int x;
            int y;
        } position;
      
        union {
            int num;
            const char* str;
        } val;
        
        char color;
    };

    void drawText(const char* s, int x, int y, char color, const Renderer* renderer);
    
    void drawNumber(int value, int x, int y, char color, const Renderer* renderer);

    UIElement scoreText;
    UIElement scoreNum;

    UIElement lifeText;
    UIElement lifeNum;

    UIElement gameOverText;
};

#endif