#include "GAMELVL.H"
#include <string.h>
#include "RENDERER.H"

#define BRICK_WIDTH     20
#define BRICK_HEIGHT    5
#define ADJ             3
#define START_ADJ       12

static const int brickHitCountTable[16] = {0,0,1,0,3,0,4,0,0,0,0,0,2,0,1,0};

static void glCreate(GameLevel* self, const int level[ROW][COL]);
static int glIsFinished(const GameLevel* self);
static void glUpdate(GameLevel* self);
static void glDraw(const GameLevel* self);
static Brick* glGetBrick(GameLevel* self, int index);

void glInit(GameLevel* self) {
    self->new = glCreate;
    self->isFinished = glIsFinished;
    self->update = glUpdate;
    self->draw = glDraw;
    self->getBrick = glGetBrick;

    self->activeBrickCount = 0;
    
    memset(self->bricks, 0, sizeof(self->bricks));
}

static void glCreate(GameLevel* self, const int level[ROW][COL]) {
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
           
            self->bricks[index++] = obj;
            self->activeBrickCount++;
        }
      
        startX = 0;
        startY += (BRICK_HEIGHT + ADJ);
    }
}

static int glIsFinished(const GameLevel* self) {
    return self->activeBrickCount == 0;
}

static void glUpdate(GameLevel* self) {
    if (self->activeBrickCount == 0) {
        return;
    }
    self->activeBrickCount--;
}

static void glDraw(const GameLevel* self) {
    int i;
    for (i = 0; i < BRICK_COUNT; ++i) {
        if (self->bricks[i].isActive) {
            rndDrawRect(
                self->bricks[i].property.position.x, 
                self->bricks[i].property.position.y, 
                self->bricks[i].property.width, 
                self->bricks[i].property.height, 
                self->bricks[i].property.color);
        }  
    }
}

static Brick* glGetBrick(GameLevel* self, int index) {
    if (index < 0 || index >= BRICK_COUNT) {
        return NULL;
    }
    return &self->bricks[index];
}