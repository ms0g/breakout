#include "PADDLE.H"
#include "CONF.H"
#include "RENDERER.H"

#define PADDLE_SPEED 2.0
#define PADDLE_WIDTH 30
#define PADDLE_HEIGHT 5

static void paddleNew(Paddle* this, float x, float y, char color);
static void paddleMove(Paddle* this, int direction);
static void paddleDraw(const Paddle* this);

void paddleInit(Paddle* this) {
    this->new = paddleNew;
    this->move = paddleMove;
    this->draw = paddleDraw;
}

static void paddleNew(Paddle* this, float x, float y, char color) {
    this->base.position.x = x;
    this->base.position.y = y;
    this->base.width = PADDLE_WIDTH;
    this->base.height = PADDLE_HEIGHT;
    this->velocity.x = PADDLE_SPEED;
    this->velocity.y = 0.0;
    this->base.color = color;
}

static void paddleMove(Paddle* this, int direction) {
    if (direction == LEFT) {
        if (this->base.position.x > 0) {
            this->base.position.x -= this->velocity.x;
        }
    } else if (direction == RIGHT) {
        if (this->base.position.x < SCREEN_WIDTH - this->base.width) {
            this->base.position.x += this->velocity.x;
        }
    }
}

static void paddleDraw(const Paddle* this) {
    rndDrawRect(
        this->base.position.x, 
        this->base.position.y, 
        this->base.width, 
        this->base.height, 
        this->base.color);
}