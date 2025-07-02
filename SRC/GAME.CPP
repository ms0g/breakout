#include "GAME.H"
#include <math.h>
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
    paddleInit(&paddle);
    paddle.create(&paddle, SCREEN_WIDTH - 50, SCREEN_HEIGHT - 10, MAGENTA);

    ballInit(&ball);
    ball.create(
        &ball, 
        paddle.property.position.x + (paddle.property.width >> 1),
        paddle.property.position.y - BALL_RESET_OFFSET_Y, 
        0xF);

    levelManager = new LevelManager();

    rndInit();

    uiInit();

    kbInit();

    score = 0;

    life = PLAYER_LIFE;

    isRunning = 1;

    done = 0;
}

Game::~Game() {
    rndExit();

    delete levelManager;

    kbExit();
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
    unsigned char key = kbHit();

    if (key == ESC) {
        isRunning = 0;
    } else if (key == L_ARROW) {
        paddle.move(&paddle, LEFT);
    } else if (key == R_ARROW) {
        paddle.move(&paddle, RIGHT);
    }
}

void Game::update(void) {
    uiUpdate(score, life);

    ball.move(&ball);

    doCollision();
}

void Game::render(void) {
    rndClear(0x0);
    
    ball.draw(&ball);
    
    paddle.draw(&paddle);

    levelManager->drawCurrentLevel();

    uiDraw();

    rndUpdateBuffer();
}

void Game::doCollision(void) {
     if (ball.property.position.y + ball.property.height >= SCREEN_HEIGHT) {
        resetBall();
        
        life--;
        
        if (life == 0) {
            done = 1;
            isGameOver = 1;
            uiUpdate(score, life);
        }
    } else if (checkAABBCollision(&ball.property, &paddle.property)) {
        //determine where on the paddle we made a collision
        float ballposition =
            (paddle.property.position.x + (paddle.property.width >> 1)) - (ball.property.position.x + (ball.property.width >> 1));

        //bounce the ball off at an angle from 0 to 60 degrees
        //based on how close we are to the edges of the paddle
        float degrees = 60.0f * (ballposition / (float)(paddle.property.width >> 1));
        float radians = degrees * (PI/180.0f);

        //calculate the new ball speeds based on that angle
        float ballXMove = BALL_SPEED * sin(radians)*-1;
        float ballYMove = BALL_SPEED * cos(radians)*-1;
        ball.velocity.x = ballXMove;
        ball.velocity.y = ballYMove;
        
    } else {
        const GameLevel* level = levelManager->getCurrentLevel();
    
        for (int i = 0; i < BRICK_COUNT; ++i) {
            Brick* brick = level->getBrick(i);
            
            if (!brick->isActive) continue;

            if (checkAABBCollision(&ball.property, &brick->property)) {
                brick->hitCount--;
                    
                if (brick->hitCount == 0) {
                    brick->isActive = 0;
                    
                    score += brickScoreTable[brick->property.color];
                    
                    level->update();
                    
                    if (level->isFinished()) {
                        levelManager->loadNextLevel();
                        resetBall();                       
                        break;
                    }
                }
                    
                ball.velocity.y = -ball.velocity.y;
                break;
            }
        }
    }
}

void Game::resetBall(void) {
    ball.reset(
        &ball, 
        paddle.property.position.x + (paddle.property.width >> 1), 
        paddle.property.position.y - BALL_RESET_OFFSET_Y);
}