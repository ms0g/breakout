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
            int color = level[i][j];
            
            int positionX = startX + START_ADJ;
            startX += (BRICK_WIDTH + ADJ);

            if (color == BLACK) {
                continue;
            }
            
            Brick obj;
            obj.property.position.x = positionX;
            obj.property.position.y = startY;
            obj.property.width = BRICK_WIDTH;
            obj.property.height = BRICK_HEIGHT;
            obj.property.color = color;
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

void GameLevel::draw(const Renderer* renderer) {
    for (int i = 0; i < BRICK_COUNT; ++i) {
        if (bricks[i].isActive) {
            renderer->rectangle(
                bricks[i].property.position.x, 
                bricks[i].property.position.y, 
                bricks[i].property.width, 
                bricks[i].property.height, 
                bricks[i].property.color);
        }  
    }
}

Brick* GameLevel::getBrick(int index) {
    return &bricks[index];
}