#include "GAME.H"
#include <MATH.H>
#include "KEYBRD.H"
#include "PADDLE.H"
#include "RENDERER.H"
#include "BALL.H"
#include "CONF.H"
#include "AABB.H"
#include "LVLMNGR.H"
#include "UI.H"

#define PI 3.14159f

static const int brickScoreTable[16] = {0,0,10,0,30,0,40,0,0,0,0,0,20,0,10,0};

Game::Game() {
    paddle = new Paddle(SCREEN_WIDTH - 50, SCREEN_HEIGHT - 10, MAGENTA);

    ball = new Ball(paddle->position.x + (paddle->width >> 1),  paddle->position.y - 3, WHITE);

    renderer = new Renderer();

    levelManager = new LevelManager();

    ui = new UI();

    initkb();

    score = 0;

    life = PLAYER_LIFE;

    isRunning = 1;

    done = 0;
}

Game::~Game() {
    delete paddle;

    delete ball;

    delete ui;

    delete renderer;

    delete levelManager;

    exitkb();
}

void Game::loop(void) {
    while (isRunning) {
        processInput();
        
        if (!done) {
            update();
            render();
        }
    }
}

void Game::processInput(void) {
    char key = kbhit();

    if (key == ESC) {
        isRunning = 0;
    } else if (key == L_ARROW) {
        paddle->move(LEFT);
    } else if (key == R_ARROW) {
        paddle->move(RIGHT);
    }
}

void Game::update(void) {
    ui->update(score, life);

    ball->move();

    doCollision();
}

void Game::render(void) {
    renderer->clear(BLACK);
    
    ball->draw(renderer);
    
    paddle->draw(renderer);

    levelManager->drawCurrentLevel(renderer);

    ui->draw(renderer);

    renderer->updateBuffer();
}

void Game::doCollision(void) {
     if (ball->position.y + ball->height >= SCREEN_HEIGHT) {
        ball->reset(paddle->position.x + (paddle->width >> 1), paddle->position.y - 3);
        
        life--;
        
        if (life == 0) {
            done = 1;
            ui->isGameOver = 1;
            ui->update(score, life);
        }
    } else if (checkAABBCollision(ball, paddle)) {

        //determine where on the paddle we made a collision
        float ballposition =
            (paddle->position.x + (paddle->width >> 1))-
            (ball->position.x + (ball->width >> 1));

        //bounce the ball off at an angle from 0 to 60 degrees
        //based on how close we are to the edges of the paddle
        float degrees = 60.0f * (ballposition / (float)(paddle->width >> 1));
        float radians = degrees * (PI/180.0f);

        //calculate the new ball speeds based on that angle
        float ballXMove = BALL_SPEED * sin(radians)*-1;
        float ballYMove = BALL_SPEED * cos(radians)*-1;
        ball->velocity.x = ballXMove;
        ball->velocity.y = ballYMove;
        
    } else {
	    GameLevel* level = levelManager->getCurrentLevel();
    
        for (int i = 0; i < BRICK_COUNT; ++i) {
            GameObject* brick = level->getBrick(i);
            
            if (!brick->isActive) continue;

            if (checkAABBCollision(ball, brick)) {
                brick->hitCount--;
                    
                if (brick->hitCount == 0) {
                    brick->isActive = 0;
                    
                    score += brickScoreTable[brick->_color];
                    
                    level->update();
                    
                    if (level->isFinished()) {
                        levelManager->loadNextLevel();
                        ball->reset(paddle->position.x + (paddle->width >> 1), paddle->position.y - 3);
                        break;
                    }
                }
                    
                ball->velocity.y = -ball->velocity.y;
            }
        }
    }
}