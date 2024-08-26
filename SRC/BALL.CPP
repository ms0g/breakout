#include "BALL.H"
#include "CONF.H"
#include "RENDERER.H"

Ball::Ball(float x, float y, char color) {
    property.position.x = x;
    property.position.y = y;
    property.width = BALL_WIDTH;
    property.height = BALL_HEIGHT;
    velocity.x = -BALL_SPEED/2;
    velocity.y = -BALL_SPEED/2;
    property.color = color;
}

void Ball::move(void) {
    property.position.x += velocity.x;
    property.position.y += velocity.y;

    if (property.position.x < 0) {
        velocity.x = -velocity.x;
        property.position.x = 0;
    } else if (property.position.x + property.width >= SCREEN_WIDTH) {
        velocity.x = -velocity.x;
        property.position.x = SCREEN_WIDTH - property.width;
    }

    if (property.position.y <= 0) {
        velocity.y = -velocity.y;
        property.position.y = 0;
    }
}

void Ball::draw(Renderer* renderer) {
    renderer->rectangle(property.position.x, property.position.y, property.width, property.height, property.color);
}

void Ball::reset(float x, float y) {
    property.position.x = x;
    property.position.y = y;
    velocity.x = -BALL_SPEED/2;
    velocity.y = -BALL_SPEED/2;
}
