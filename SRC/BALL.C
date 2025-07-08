#include "BALL.H"
#include "CONF.H"
#include "RENDERER.H"

static void ballNew(Ball* this, float x, float y, char color);
static void ballMove(Ball* this);
static void ballDraw(const Ball* this);
static void ballReset(Ball* this, float x, float y);

void ballInit(Ball* this) {
    this->new = ballNew;
    this->move = ballMove;
    this->draw = ballDraw;
    this->reset = ballReset;   
}

static void ballNew(Ball* this, float x, float y, char color) {
    this->base.position.x = x;
    this->base.position.y = y;
    this->base.width = BALL_WIDTH;
    this->base.height = BALL_HEIGHT;
    this->velocity.x = -BALL_SPEED/2;
    this->velocity.y = -BALL_SPEED/2;
    this->base.color = color;
}

static void ballMove(Ball* this) {
    this->base.position.x += this->velocity.x;
    this->base.position.y += this->velocity.y;

    if (this->base.position.x < 0) {
        this->velocity.x = -this->velocity.x;
        this->base.position.x = 0;
    } else if (this->base.position.x + this->base.width >= SCREEN_WIDTH) {
        this->velocity.x = -this->velocity.x;
        this->base.position.x = SCREEN_WIDTH - this->base.width;
    }

    if (this->base.position.y <= 0) {
        this->velocity.y = -this->velocity.y;
        this->base.position.y = 0;
    }
}

static void ballDraw(const Ball* this) {
    rndDrawRect(
        this->base.position.x, 
        this->base.position.y, 
        this->base.width, 
        this->base.height, 
        this->base.color);
}

static void ballReset(Ball* this, float x, float y) {
    this->base.position.x = x;
    this->base.position.y = y;
    this->velocity.x = -BALL_SPEED/2;
    this->velocity.y = -BALL_SPEED/2;
}
