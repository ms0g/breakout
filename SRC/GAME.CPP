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
#include "TABLES.H"

Game::Game() {
    paddle = new Paddle(SCREEN_WIDTH - 50, SCREEN_HEIGHT - 10, MAGENTA);
   
    ball = new Ball(paddle->pos.x + (paddle->width / 2),  paddle->pos.y - 5, WHITE);

    renderer = new Renderer();

    GameLevel one;
    one.init(levelOne);
    levels[0] = one;

    GameLevel two;
    two.init(levelTwo);
    levels[1] = two;

    GameLevel three;
    three.init(levelThree);
    levels[2] = three;

    GameLevel four;
    four.init(levelFour);
    levels[3] = four;
    
    currentLevel = 0;

    score = 0;

    life = 5;

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
        
        life--;
        if (life == 0) {
            isRunning = false;
        }
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
        
        return;
    }

    for (int i = 0; i < levels[currentLevel].bricks.size(); ++i) {
        GameLevel level = levels[currentLevel];
        GameObject* brick =  &level.bricks[i];
        
        if (!brick->isActive) continue;

        if (checkAABBCollision(ball, brick)) {
            brick->hitCount--;
                
            if (brick->hitCount == 0) {
                brick->isActive = false;
                score += brickScoreTable[brick->m_color];
                
                level.activeBrickCount--;
                if (level.activeBrickCount == 0) {
                    currentLevel++;
                }
            }
                
            ball->velocity.y = -ball->velocity.y;
        }
    }
}