#include "PADDLE.H"
#include "CONF.H"
#include "RENDERER.H"

#define PADDLE_SPEED 2.0
#define PADDLE_WIDTH 30
#define PADDLE_HEIGHT 5

static void paddleCreate(Paddle* self, float x, float y, char color);
static void paddleMove(Paddle* self, int direction);
static void paddleDraw(const Paddle* self);

void paddleInit(Paddle* self) {
    self->new = paddleCreate;
    self->move = paddleMove;
    self->draw = paddleDraw;
}

static void paddleCreate(Paddle* self, float x, float y, char color) {
    self->property.position.x = x;
    self->property.position.y = y;
    self->property.width = PADDLE_WIDTH;
    self->property.height = PADDLE_HEIGHT;
    self->velocity.x = PADDLE_SPEED;
    self->property.color = color;
}

static void paddleMove(Paddle* self, int direction) {
    if (direction == LEFT) {
        if (self->property.position.x > 0) {
            self->property.position.x -= self->velocity.x;
        }
    } else if (direction == RIGHT) {
        if (self->property.position.x < SCREEN_WIDTH - self->property.width) {
            self->property.position.x += self->velocity.x;
        }
    }
}

static void paddleDraw(const Paddle* self) {
    rndDrawRect(
        self->property.position.x, 
        self->property.position.y, 
        self->property.width, 
        self->property.height, 
        self->property.color);
}