#include "GAME.H"
#include "VECTOR.H"
#include "KEYBRD.H"
#include "PADDLE.H"
#include "RENDERER.H"
#include "BALL.H"
#include "BOOL.H"
#include "CONF.H"
#include "AABB.H"
#include "LEVELS.H"

Game::Game() {
    m_paddle = new Paddle(SCREEN_WIDTH - 50, SCREEN_HEIGHT - 10, MAGENTA);
   
    m_ball = new Ball(m_paddle->pos.x + (m_paddle->width / 2),  m_paddle->pos.y - 5, WHITE);

    m_renderer = new Renderer();

    GameLevel one;
    one.init(levelOne);

    levels.push_back(one);
    
    currentLevel = 0;

    isRunning = true;
}

Game::~Game() {
    delete m_paddle;
    
    delete m_ball;
    
    delete m_renderer;
}

void Game::run(void) {
    while (isRunning) {
        processInput();
        
        update();
        
        render();
    }
}

void Game::processInput(void) {
    int key = kbhit();

    if (key == Q) {
        isRunning = false;
    } else if (key == L_ARROW) {
        m_paddle->move(LEFT);
    } else if (key == R_ARROW) {
        m_paddle->move(RIGHT);
    }
}

void Game::update(void) {
    m_ball->move();

    if (m_ball->pos.y + m_ball->height >= SCREEN_HEIGHT) {
        m_ball->reset(m_paddle->pos.x + (m_paddle->width / 2), m_paddle->pos.y - 5);
    } else {
        doCollision();
    }
}

void Game::render(void) {
    m_renderer->clrscr(BLACK);
    
    m_ball->draw(m_renderer);
    
    m_paddle->draw(m_renderer);

    levels[currentLevel].draw(m_renderer);
}

void Game::doCollision(void) {
    if (checkCollision(m_ball, m_paddle)) {
        m_ball->velocity.y = -m_ball->velocity.y;
        m_ball->pos.y = m_paddle->pos.y - 5;
    }

    for (int i = 0; i < levels[currentLevel].bricks.size(); ++i) {
        GameObject* brick =  &levels[currentLevel].bricks[i];
        
        if (checkAABBCollision(m_ball, brick)) {
            brick->m_color = CYAN;
        }
    }
}