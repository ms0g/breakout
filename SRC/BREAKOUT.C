#include <math.h>
#include <stdio.h>
#include "VGA.H"
#include "KEYBRD.H"
#include "PADDLE.H"
#include "BALL.H"
#include "RENDERER.H"
#include "CONF.H"
#include "AABB.H"
#include "LVLMNGR.H"
#include "UI.H"

#define PI 3.14159f

static Ball ball;
static Paddle paddle;
static LevelManager levelManager;
static int isRunning;
static int done;
static int score;
static int life;
static int isGameOver;

static const int brickScoreTable[16] = {0,0,10,0,30,0,40,0,0,0,0,0,20,0,10,0};

static void doCollision(void);
static void resetBall(void);

static void processInput(void) {
    unsigned char key = kbHit();

    if (key == ESC) {
        isRunning = 0;
    } else if (key == L_ARROW) {
        paddle.move(&paddle, LEFT);
    } else if (key == R_ARROW) {
        paddle.move(&paddle, RIGHT);
    }
}

static void update(void) {
    uiUpdate(score, life);

    ball.move(&ball);

    doCollision();
}

static void render(void) {
    vgaClearOffscreen(0x0);
    
    ball.draw(&ball);
    
    paddle.draw(&paddle);

    levelManager.drawCurrentLevel(&levelManager);

    uiDraw(isGameOver);

    vgaUpdateVram();
}

static void doCollision(void) {
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
        float radians = degrees * (PI / 180.0f);

        //calculate the new ball speeds based on that angle
        float ballXMove = BALL_SPEED * sin(radians)*-1;
        float ballYMove = BALL_SPEED * cos(radians)*-1;
        ball.velocity.x = ballXMove;
        ball.velocity.y = ballYMove;
        
    } else {
        int i;
        GameLevel* level = levelManager.getCurrentLevel(&levelManager);
    
        for (i = 0; i < BRICK_COUNT; ++i) {
            Brick* brick = level->getBrick(level, i);
            
            if (!brick->isActive) continue;

            if (checkAABBCollision(&ball.property, &brick->property)) {
                brick->hitCount--;
                    
                if (brick->hitCount == 0) {
                    brick->isActive = 0;
                    
                    score += brickScoreTable[brick->property.color];
                    
                    level->update(level);
                    
                    if (level->isFinished(level)) {
                        levelManager.loadNextLevel(&levelManager);
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

static void resetBall(void) {
    ball.reset(
        &ball, 
        paddle.property.position.x + (paddle.property.width >> 1), 
        paddle.property.position.y - BALL_RESET_OFFSET_Y);
}

static void init(void) {
    paddleInit(&paddle);
    paddle.new(&paddle, SCREEN_WIDTH - 50, SCREEN_HEIGHT - 10, 0x5);

    ballInit(&ball);
    ball.new(
        &ball, 
        paddle.property.position.x + (paddle.property.width >> 1),
        paddle.property.position.y - BALL_RESET_OFFSET_Y, 
        0xF);

    lmInit(&levelManager);
    levelManager.new(&levelManager);

    vgaInit();
    uiInit();
    kbInit();

    score = done = isGameOver = 0;

    life = PLAYER_LIFE;

    isRunning = 1;
}

void main(void) {
    init();
    
    while (isRunning) {
        processInput();
        
        if (!done) {
            update();
            render();
        }
    }

    vgaExit();
    kbExit();
    
    printf("%s", "\tDeveloped by M. Sami GURPINAR\n     In a lot of blood, sweat, and tears.\n");
}