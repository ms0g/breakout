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
    paddle = new Paddle(SCREEN_WIDTH - 50, SCREEN_HEIGHT - 10, MAGENTA);
   
    ball = new Ball(paddle->pos.x + (paddle->width / 2),  paddle->pos.y - 5, WHITE);

    renderer = new Renderer();

    GameLevel one;
    one.init(levelOne);

    levels.push_back(one);
    
    currentLevel = 0;

    isRunning = true;
}

Game::~Game() {
    delete paddle;
    
    delete ball;
    
    delete renderer;
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
        paddle->move(LEFT);
    } else if (key == R_ARROW) {
        paddle->move(RIGHT);
    }
}

void Game::update(void) {
    ball->move();

    if (ball->pos.y + ball->height >= SCREEN_HEIGHT) {
        ball->reset(paddle->pos.x + (paddle->width / 2), paddle->pos.y - 5);
    } else {
        doCollision();
    }
}

void Game::render(void) {
    renderer->clrscr(BLACK);
    
    ball->draw(renderer);
    
    paddle->draw(renderer);

    levels[currentLevel].draw(renderer);
}

void Game::doCollision(void) {
    if (checkCollision(ball, paddle)) {
        ball->velocity.y = -ball->velocity.y;
        ball->pos.y = paddle->pos.y - 5;
    }

    for (int i = 0; i < levels[currentLevel].bricks.size(); ++i) {
        GameObject* brick =  &levels[currentLevel].bricks[i];
        
        if (brick->isActive) {
            if (checkAABBCollision(ball, brick)) {
                brick->hitCount--;
                
                if (brick->hitCount == 0) {
                    brick->isActive = false;
                }
                
                ball->velocity.y = -ball->velocity.y;
            }
        } 
    }
}