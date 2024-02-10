#include "GAMELVL.H"
#include "RENDERER.H"

#define BRICK_WIDTH     20
#define BRICK_HEIGHT    5
#define GAP             3
#define START_GAP       12

static const int brickHitCountTable[16] = {0,0,1,0,3,0,4,0,0,0,0,0,2,0,1,0};

void GameLevel::init(const int level[ROW][COL]) {
    int startX = 0;
    int startY = 30;

    activeBrickCount = BRICK_COUNT;

    int index = 0;
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
            obj._color = color;
            obj.isActive = 1;
            obj.hitCount = brickHitCountTable[color];
           
            bricks[index++] = obj;
        }

        startX = 0;
        startY += (BRICK_HEIGHT + GAP);
    }
}

void GameLevel::update(void) {
    activeBrickCount--;
}

int GameLevel::isFinished(void) {
    return activeBrickCount == 0;
}

void GameLevel::draw(Renderer* renderer) {
    for (int i = 0; i < BRICK_COUNT; ++i) {
        if (bricks[i].isActive) {
            renderer->rectangle(bricks[i].pos.x, bricks[i].pos.y, bricks[i].width, bricks[i].height, bricks[i]._color);
        }  
    }
}