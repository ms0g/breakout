#include "PADDLE.H"
#include "CONF.H"
#include "RENDERER.H"

#define PADDLE_SPEED 5
#define PADDLE_WIDTH 50
#define PADDLE_HEIGHT 5

Paddle::Paddle(int x, int y, char color) {
    m_pos.x = x;
    m_pos.y = y;
    m_width = PADDLE_WIDTH;
    m_height = PADDLE_HEIGHT;
    m_velocity.x = PADDLE_SPEED;
    m_color = color;
}

void Paddle::move(int direction) {
    if (direction == LEFT) {
        if (m_pos.x > 0) {
            m_pos.x -= m_velocity.x;
        }
    } else if (direction == RIGHT) {
        if (m_pos.x < SCREEN_WIDTH - m_width) {
                m_pos.x += m_velocity.x;
        }
    }
}

void Paddle::draw(Renderer* renderer) {
    renderer->renderRect(m_pos.x, m_pos.y, m_width, m_height, m_color);
}