#include "game.h"
#include <dos.h>
#include "vga.h"
#include "vector.h"
#include "keyboard.h"
#include "bool.h"

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200

#define PADDLE_SPEED 5
#define PADDLE_WIDTH 20
#define PADDLE_HEIGHT 5

#define BALL_SPEED 1
#define BALL_WIDTH 3
#define BALL_HEIGHT 3

void Game::init(void) {
    initVGA();

    m_paddle.x = SCREEN_WIDTH - 50;
    m_paddle.y = SCREEN_HEIGHT - 10;
    m_paddle.width = PADDLE_WIDTH;
    m_paddle.height = PADDLE_HEIGHT;
    m_paddle.velocity.x = PADDLE_SPEED;
   
    rectangle(m_paddle.x, m_paddle.y, m_paddle.width, m_paddle.height, LIGHTBLUE);
    
    m_ball.x = m_paddle.x + (PADDLE_WIDTH / 2);
    m_ball.y = m_paddle.y - 5;
    m_ball.width = BALL_WIDTH;
    m_ball.height = BALL_HEIGHT;
    m_ball.velocity.x = -BALL_SPEED;
    m_ball.velocity.y = -BALL_SPEED;
    
    rectangle(m_ball.x, m_ball.y, m_ball.width, m_ball.height, WHITE);

    isRunning = true;
}

void Game::run(void) {
    while(isRunning) {
        processInput();
        update();
        render();
        
        delay(15);
    }
}

void Game::processInput(void) {
    int key = kbhit();

    if (key == L_ARROW) {
        if (m_paddle.x > 0) {
            m_paddle.x -= m_paddle.velocity.x;
        }
    } else if (key == R_ARROW) {
        if (m_paddle.x < SCREEN_WIDTH - m_paddle.width) {
             m_paddle.x += m_paddle.velocity.x;
        }
    }
}

void Game::update(void) {
    m_ball.x += m_ball.velocity.x;
    m_ball.y += m_ball.velocity.y;

    if (m_ball.x < 0) {
        m_ball.velocity.x = -m_ball.velocity.x;
        m_ball.x = 0;
    } else if (m_ball.x + m_ball.width >= SCREEN_WIDTH) {
        m_ball.velocity.x = -m_ball.velocity.x;
        m_ball.x = SCREEN_WIDTH - m_ball.width;
    }
    
    if (m_ball.y <= 0) {
        m_ball.velocity.y = -m_ball.velocity.y;
        m_ball.y = 0;
    } else if ((m_ball.y + m_ball.height >= m_paddle.y) && (m_ball.x > m_paddle.x && m_ball.x < (m_paddle.x + m_paddle.width))) {
        m_ball.velocity.y = -m_ball.velocity.y;
        m_ball.y = m_paddle.y - 5;
    } else if (m_ball.y + m_ball.height >= SCREEN_HEIGHT) {
        m_ball.x = m_paddle.x + (PADDLE_WIDTH / 2);
        m_ball.y = m_paddle.y - 5;
        m_ball.velocity.x = -BALL_SPEED;
        m_ball.velocity.y = -BALL_SPEED;
    }
}

void Game::render(void) {
    clrscr();
    
    rectangle(m_ball.x, m_ball.y, m_ball.width, m_ball.height, WHITE);
    rectangle(m_paddle.x, m_paddle.y, m_paddle.width, m_paddle.height, LIGHTBLUE);
}