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
    this->property.position.x = x;
    this->property.position.y = y;
    this->property.width = PADDLE_WIDTH;
    this->property.height = PADDLE_HEIGHT;
    this->velocity.x = PADDLE_SPEED;
    this->velocity.y = 0.0;
    this->property.color = color;
}

static void paddleMove(Paddle* this, int direction) {
    if (direction == LEFT) {
        if (this->property.position.x > 0) {
            this->property.position.x -= this->velocity.x;
        }
    } else if (direction == RIGHT) {
        if (this->property.position.x < SCREEN_WIDTH - this->property.width) {
            this->property.position.x += this->velocity.x;
        }
    }
}

static void paddleDraw(const Paddle* this) {
    rndDrawRect(
        this->property.position.x, 
        this->property.position.y, 
        this->property.width, 
        this->property.height, 
        this->property.color);
}