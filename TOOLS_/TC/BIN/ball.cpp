#include "BALL.H"
#include "CONF.H"
#include "RENDERER.H"

#define BALL_SPEED 1
#define BALL_WIDTH 3
#define BALL_HEIGHT 3

Ball::Ball(int x, int y, char color) {
    m_pos.x = x;
    m_pos.y = y;
    m_width = BALL_WIDTH;
    m_height = BALL_HEIGHT;
    m_velocity.x = -BALL_SPEED;
    m_velocity.y = -BALL_SPEED;
    m_color = color;
}

void Ball::move(void) {
    m_pos.x += m_velocity.x;
    m_pos.y += m_velocity.y;

    if (m_pos.x < 0) {
        m_velocity.x = -m_velocity.x;
        m_pos.x = 0;
    } else if (m_pos.x + m_width >= SCREEN_WIDTH) {
        m_velocity.x = -m_velocity.x;
        m_pos.x = SCREEN_WIDTH - m_width;
    }

    if (m_pos.y <= 0) {
        m_velocity.y = -m_velocity.y;
        m_pos.y = 0;
    }
}

void Ball::draw(Renderer* renderer) {
    renderer->renderRect(m_pos.x, m_pos.y, m_width, m_height, m_color);
}

void Ball::reset(int x, int y) {
    m_pos.x = x;
    m_pos.y = y;
    m_velocity.x = -BALL_SPEED;
    m_velocity.y = -BALL_SPEED;
}
