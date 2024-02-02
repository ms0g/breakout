#include "game.h"
#include <dos.h>
#include "vga.h"
#include "vector.h"
#include "bool.h"

#define R 3
#define SPEED 5
#define PADDLE_SPEED 10
#define PADDLE_WIDTH 20
#define PADDLE_HEIGHT 5


int input() {
    asm {
        mov ah, 00h       
        int 16h   
    }
}

void Game::init(void) {
    initVGA();

    m_paddle.x = WIDTH - 50;
    m_paddle.y = HEIGHT - 10;
    m_paddle.height = PADDLE_HEIGHT;
    m_paddle.width = PADDLE_WIDTH;

    rectangle(m_paddle.x, m_paddle.y, m_paddle.width, m_paddle.height, LIGHTBLUE);
    
    m_ball.x = m_paddle.x + PADDLE_WIDTH / 2;
    m_ball.y = m_paddle.y - 5;
    m_ball.r = R;
    
    circle(m_ball.x, m_ball.y, R, WHITE);

    isRunning = true;
}

void Game::run(void) {
    while(isRunning) {
        
        processInput();
        update();
        render();
        
        delay(50);
    }
}

void Game::processInput(void) {
    int a = input();

    if (a != 0) rectangle(m_paddle.x, m_paddle.y, m_paddle.width, m_paddle.height, BLACK);
    if (a == 0x4B00) {
        m_paddle.x -= PADDLE_SPEED;
    } else if (a == 0x4D00) {
        m_paddle.x += PADDLE_SPEED;
    }
}

void Game::update(void) {
    // m_ball.x -= SPEED;
    // m_ball.y -= SPEED;
}

void Game::render(void) {
    //circle(m_ball.x, m_ball.y, R, WHITE);
    rectangle(m_paddle.x, m_paddle.y, m_paddle.width, m_paddle.height, LIGHTBLUE);
}