#include "BALL.H"
#include "CONF.H"

#define BALL_SPEED 1
#define BALL_WIDTH 3
#define BALL_HEIGHT 3

Ball::Ball(int x, int y, char color) {
    pos.x = x;
    pos.y = y;
    width = BALL_WIDTH;
    height = BALL_HEIGHT;
    velocity.x = -BALL_SPEED;
    velocity.y = -BALL_SPEED;
    m_color = color;
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

void Ball::reset(int x, int y) {
    pos.x = x;
    pos.y = y;
    velocity.x = -BALL_SPEED;
    velocity.y = -BALL_SPEED;
}
