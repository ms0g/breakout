#include "GAMELVL.H"
#include <string.h>
#include "RENDERER.H"

#define BRICK_WIDTH     20
#define BRICK_HEIGHT    5
#define ADJ             3
#define START_ADJ       12

static const int brickHitCountTable[16] = {0,0,1,0,3,0,4,0,0,0,0,0,2,0,1,0};

static void glCreate(GameLevel* this, const int (*level)[COL]);
static int glIsFinished(const GameLevel* this);
static void glUpdate(GameLevel* this);
static void glDraw(const GameLevel* this);
static Brick* glGetBrick(GameLevel* this, int index);

void glInit(GameLevel* this) {
    this->new = glCreate;
    this->isFinished = glIsFinished;
    this->update = glUpdate;
    this->draw = glDraw;
    this->getBrick = glGetBrick;

    this->activeBrickCount = 0;
    
    memset(this->bricks, 0, sizeof(this->bricks));
}

static void glCreate(GameLevel* this, const int (*level)[COL]) {
    int startX = 0;
    int startY = 30;
    int index = 0;
    int i, j;
    Brick obj;
    
    for (i = 0; i < ROW; ++i) {
        for (j = 0; j < COL; ++j) {
            int color = level[i][j];
            
            int positionX = startX + START_ADJ;
            startX += (BRICK_WIDTH + ADJ);

            if (color == 0x0) {
                continue;
            }
            
            obj.property.position.x = positionX;
            obj.property.position.y = startY;
            obj.property.width = BRICK_WIDTH;
            obj.property.height = BRICK_HEIGHT;
            obj.property.color = color;
            obj.isActive = 1;
            obj.hitCount = brickHitCountTable[color];
           
            this->bricks[index++] = obj;
            this->activeBrickCount++;
        }
      
        startX = 0;
        startY += (BRICK_HEIGHT + ADJ);
    }
}

static int glIsFinished(const GameLevel* this) {
    return this->activeBrickCount == 0;
}

static void glUpdate(GameLevel* this) {
    if (this->activeBrickCount == 0) {
        return;
    }
    this->activeBrickCount--;
}

static void glDraw(const GameLevel* this) {
    int i;
    for (i = 0; i < BRICK_COUNT; ++i) {
        if (this->bricks[i].isActive) {
            rndDrawRect(
                this->bricks[i].property.position.x, 
                this->bricks[i].property.position.y, 
                this->bricks[i].property.width, 
                this->bricks[i].property.height, 
                this->bricks[i].property.color);
        }  
    }
}

static Brick* glGetBrick(GameLevel* this, int index) {
    if (index < 0 || index >= BRICK_COUNT) {
        return NULL;
    }
    return &this->bricks[index];
}