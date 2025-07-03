#include "BALL.H"
#include "CONF.H"
#include "RENDERER.H"

static void ballCreate(Ball* this, float x, float y, char color);
static void ballMove(Ball* this);
static void ballDraw(const Ball* this);
static void ballReset(Ball* this, float x, float y);

void ballInit(Ball* this) {
    this->new = ballCreate;
    this->move = ballMove;
    this->draw = ballDraw;
    this->reset = ballReset;   
}

static void ballCreate(Ball* this, float x, float y, char color) {
    this->property.position.x = x;
    this->property.position.y = y;
    this->property.width = BALL_WIDTH;
    this->property.height = BALL_HEIGHT;
    this->velocity.x = -BALL_SPEED/2;
    this->velocity.y = -BALL_SPEED/2;
    this->property.color = color;
}

static void ballMove(Ball* this) {
    this->property.position.x += this->velocity.x;
    this->property.position.y += this->velocity.y;

    if (this->property.position.x < 0) {
        this->velocity.x = -this->velocity.x;
        this->property.position.x = 0;
    } else if (this->property.position.x + this->property.width >= SCREEN_WIDTH) {
        this->velocity.x = -this->velocity.x;
        this->property.position.x = SCREEN_WIDTH - this->property.width;
    }

    if (this->property.position.y <= 0) {
        this->velocity.y = -this->velocity.y;
        this->property.position.y = 0;
    }
}

static void ballDraw(const Ball* this) {
    rndDrawRect(
        this->property.position.x, 
        this->property.position.y, 
        this->property.width, 
        this->property.height, 
        this->property.color);
}

static void ballReset(Ball* this, float x, float y) {
    this->property.position.x = x;
    this->property.position.y = y;
    this->velocity.x = -BALL_SPEED/2;
    this->velocity.y = -BALL_SPEED/2;
}
