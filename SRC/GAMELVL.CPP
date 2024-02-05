#include "GAMELVL.H"
#include "RENDERER.H"

#define BRICK_WIDTH     20
#define BRICK_HEIGHT    5
#define GAP             3
#define START_GAP       12

void GameLevel::init(int level[9][13]) {
    int startX = 0;
    int startY = 0;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 13; ++j) {
            char color = level[i][j];
            int posX = startX + START_GAP;
            
            GameObject obj;
            obj.pos.x = posX;
            obj.pos.y = startY;
            obj.width = BRICK_WIDTH;
            obj.height = BRICK_HEIGHT;
            obj.m_color = color;

            bricks.push_back(obj);

            startX += (BRICK_WIDTH + GAP);

        }
        startX = 0;
        startY += (BRICK_HEIGHT + GAP);
    }
}

void GameLevel::draw(Renderer* renderer) {
     for (int i = 0; i < bricks.size(); ++i) {
        renderer->rectangle(bricks[i].pos.x, bricks[i].pos.y, bricks[i].width, bricks[i].height, bricks[i].m_color);
    }
}