#include "BALL.H"
#include "CONF.H"
#include "RENDERER.H"

#define BALL_SPEED 1.0
#define BALL_WIDTH 3
#define BALL_HEIGHT 3

Ball::Ball(float x, float y, char color) {
    pos.x = x;
    pos.y = y;
    width = BALL_WIDTH;
    height = BALL_HEIGHT;
    velocity.x = -BALL_SPEED;
    velocity.y = -BALL_SPEED;
    _color = color;
}

void Ball::move(void) {
    pos.x += velocity.x;
    pos.y += velocity.y;

    if (pos.x < 0) {
        velocity.x = -velocity.x;
        pos.x = 0;
    } else if (pos.x + width >= SCREEN_WIDTH) {
        velocity.x = -velocity.x;
        pos.x = SCREEN_WIDTH - width;
    }

    if (pos.y <= 0) {
        velocity.y = -velocity.y;
        pos.y = 0;
    }
}

void Ball::draw(Renderer* renderer) {
    renderer->rectangle(pos.x, pos.y, width, height, _color);
}

void Ball::reset(float x, float y) {
    pos.x = x;
    pos.y = y;
    velocity.x = -BALL_SPEED;
    velocity.y = -BALL_SPEED;
}
