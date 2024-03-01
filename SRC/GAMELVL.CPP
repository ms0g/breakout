#include "GAMELVL.H"
#include "RENDERER.H"

#define BRICK_WIDTH     20
#define BRICK_HEIGHT    5
#define ADJ             3
#define START_ADJ       12

static const int brickHitCountTable[16] = {0,0,1,0,3,0,4,0,0,0,0,0,2,0,1,0};

void GameLevel::init(const int level[ROW][COL]) {
    int startX = 0;
    int startY = 30;

    activeBrickCount = 0;

    int index = 0;
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            char color = level[i][j];
            
            int positionX = startX + START_ADJ;
            startX += (BRICK_WIDTH + ADJ);

            if (color == BLACK) {
                continue;
            }
            
            GameObject obj;
            obj.position.x = positionX;
            obj.position.y = startY;
            obj.width = BRICK_WIDTH;
            obj.height = BRICK_HEIGHT;
            obj._color = color;
            obj.isActive = 1;
            obj.hitCount = brickHitCountTable[color];
           
            bricks[index++] = obj;
            activeBrickCount++;
        }

        startX = 0;
        startY += (BRICK_HEIGHT + ADJ);
    }
}

int GameLevel::isFinished(void) {
    return activeBrickCount == 0;
}

void GameLevel::update(void) {
    activeBrickCount--;
}

void GameLevel::draw(Renderer* renderer) {
    for (int i = 0; i < BRICK_COUNT; ++i) {
        if (bricks[i].isActive) {
            renderer->rectangle(
                bricks[i].position.x, 
                bricks[i].position.y, 
                bricks[i].width, 
                bricks[i].height, 
                bricks[i]._color);
        }  
    }
}

GameObject* GameLevel::getBrick(int index) {
    return &bricks[index];
}