#include "BALL.H"
#include "CONF.H"
#include "RENDERER.H"

Ball::Ball(float x, float y, char color) {
    position.x = x;
    position.y = y;
    width = BALL_WIDTH;
    height = BALL_HEIGHT;
    velocity.x = -BALL_SPEED/2;
    velocity.y = -BALL_SPEED/2;
    _color = color;
}

void Ball::move(void) {
    position.x += velocity.x;
    position.y += velocity.y;

    if (position.x < 0) {
        velocity.x = -velocity.x;
        position.x = 0;
    } else if (position.x + width >= SCREEN_WIDTH) {
        velocity.x = -velocity.x;
        position.x = SCREEN_WIDTH - width;
    }

    if (position.y <= 0) {
        velocity.y = -velocity.y;
        position.y = 0;
    }
}

void Ball::draw(Renderer* renderer) {
    renderer->rectangle(position.x, position.y, width, height, _color);
}

void Ball::reset(float x, float y) {
    position.x = x;
    position.y = y;
    velocity.x = -BALL_SPEED/2;
    velocity.y = -BALL_SPEED/2;
}
