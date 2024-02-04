#include "GAME.H"
#include <dos.h>
#include "VGA.H"
#include "VECTOR.H"
#include "KEYBRD.H"
#include "PADDLE.H"
#include "BALL.H"
#include "RENDERER.H"
#include "BOOL.H"
#include "CONF.H"
#include "AABB.H"

void Game::init(void) {
    initVGA();

    m_paddle = new Paddle(SCREEN_WIDTH - 50, SCREEN_HEIGHT - 10, MAGENTA);
   
    m_ball = new Ball(m_paddle->pos.x + (m_paddle->width / 2),  m_paddle->pos.y - 5, WHITE);

    m_renderer = new Renderer();
    
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
        m_paddle->move(LEFT);
    } else if (key == R_ARROW) {
        m_paddle->move(RIGHT);
    }
}

void Game::update(void) {
    m_ball->move();

    if (m_ball->pos.y + m_ball->height >= SCREEN_HEIGHT) {
        m_ball->reset(m_paddle->pos.x + (m_paddle->width / 2), m_paddle->pos.y - 5);
    }

    doCollision();
}

void Game::render(void) {
    clrscr();
    
    m_ball->draw(m_renderer);
    
    m_paddle->draw(m_renderer);
}

void Game::doCollision(void) {
    if (checkCollision(m_ball, m_paddle)) {
        m_ball->velocity.y = -m_ball->velocity.y;
        m_ball->pos.y = m_paddle->pos.y - 5;
    }
}