#ifndef GAME_H
#define GAME_H

class Ball;
class Paddle;
class Renderer;
class SceneManager;
class UI;
class Game {
public:
    Game();
    
    ~Game();

    void loop(void);
    
private:
    void processInput(void);

    void update(void);

    void render(void);

    void doCollision(void);

    Ball* ball;

    Paddle* paddle;

    Renderer* renderer;

    SceneManager* sceneManager;

    UI* ui;

    int isRunning;

    int done;

    int score;

    int life;
};

#endif