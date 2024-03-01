#include "PADDLE.H"
#include "CONF.H"
#include "RENDERER.H"

#define PADDLE_SPEED 2.0
#define PADDLE_WIDTH 30
#define PADDLE_HEIGHT 5

Paddle::Paddle(float x, float y, char color) {
    position.x = x;
    position.y = y;
    width = PADDLE_WIDTH;
    height = PADDLE_HEIGHT;
    velocity.x = PADDLE_SPEED;
    _color = color;
}

void Paddle::move(int direction) {
    if (direction == LEFT) {
        if (position.x > 0) {
            position.x -= velocity.x;
        }
    } else if (direction == RIGHT) {
        if (position.x < SCREEN_WIDTH - width) {
                position.x += velocity.x;
        }
    }
}

void Paddle::draw(Renderer* renderer) {
    renderer->rectangle(position.x, position.y, width, height, _color);
}