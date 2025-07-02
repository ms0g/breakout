#include "PADDLE.H"
#include "CONF.H"
#include "RENDERER.H"

#define PADDLE_SPEED 2.0
#define PADDLE_WIDTH 30
#define PADDLE_HEIGHT 5

Paddle::Paddle(float x, float y, char color) {
    property.position.x = x;
    property.position.y = y;
    property.width = PADDLE_WIDTH;
    property.height = PADDLE_HEIGHT;
    velocity.x = PADDLE_SPEED;
    property.color = color;
}

void Paddle::move(int direction) {
    if (direction == LEFT) {
        if (property.position.x > 0) {
            property.position.x -= velocity.x;
        }
    } else if (direction == RIGHT) {
        if (property.position.x < SCREEN_WIDTH - property.width) {
            property.position.x += velocity.x;
        }
    }
}

void Paddle::draw(void) {
    rndDrawRect(property.position.x, property.position.y,property. width, property.height, property.color);
}