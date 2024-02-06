#include "GAMELVL.H"
#include "RENDERER.H"
#include "TABLES.H"

#define BRICK_WIDTH     20
#define BRICK_HEIGHT    5
#define GAP             3
#define START_GAP       12

void GameLevel::init(const int level[ROW][COL]) {
    int startX = 0;
    int startY = 45;

    activeBrickCount = ROW * COL;

    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            char color = level[i][j];
            
            int posX = startX + START_GAP;
            startX += (BRICK_WIDTH + GAP);

            if (color == BLACK) {
                continue;
            }
            
            GameObject obj;
            obj.pos.x = posX;
            obj.pos.y = startY;
            obj.width = BRICK_WIDTH;
            obj.height = BRICK_HEIGHT;
            obj.m_color = color;
            obj.isActive = true;
            obj.hitCount =  brickHitCountTable[color];
           
            bricks.push_back(obj);
        }

        startX = 0;
        startY += (BRICK_HEIGHT + GAP);
    }
}

void GameLevel::draw(Renderer* renderer) {
    for (int i = 0; i < bricks.size(); ++i) {
        if (bricks[i].isActive) {
            renderer->rectangle(bricks[i].pos.x, bricks[i].pos.y, bricks[i].width, bricks[i].height, bricks[i].m_color);
        }  
    }
}