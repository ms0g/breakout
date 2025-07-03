#include "BALL.H"
#include "CONF.H"
#include "RENDERER.H"

static void ballCreate(Ball* self, float x, float y, char color);
static void ballMove(Ball* self);
static void ballDraw(const Ball* self);
static void ballReset(Ball* self, float x, float y);

void ballInit(Ball* self) {
    self->new = ballCreate;
    self->move = ballMove;
    self->draw = ballDraw;
    self->reset = ballReset;   
}

static void ballCreate(Ball* self, float x, float y, char color) {
    self->property.position.x = x;
    self->property.position.y = y;
    self->property.width = BALL_WIDTH;
    self->property.height = BALL_HEIGHT;
    self->velocity.x = -BALL_SPEED/2;
    self->velocity.y = -BALL_SPEED/2;
    self->property.color = color;
}

static void ballMove(Ball* self) {
    self->property.position.x += self->velocity.x;
    self->property.position.y += self->velocity.y;

    if (self->property.position.x < 0) {
        self->velocity.x = -self->velocity.x;
        self->property.position.x = 0;
    } else if (self->property.position.x + self->property.width >= SCREEN_WIDTH) {
        self->velocity.x = -self->velocity.x;
        self->property.position.x = SCREEN_WIDTH - self->property.width;
    }

    if (self->property.position.y <= 0) {
        self->velocity.y = -self->velocity.y;
        self->property.position.y = 0;
    }
}

static void ballDraw(const Ball* self) {
    rndDrawRect(
        self->property.position.x, 
        self->property.position.y, 
        self->property.width, 
        self->property.height, 
        self->property.color);
}

static void ballReset(Ball* self, float x, float y) {
    self->property.position.x = x;
    self->property.position.y = y;
    self->velocity.x = -BALL_SPEED/2;
    self->velocity.y = -BALL_SPEED/2;
}
