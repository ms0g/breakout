#include "game.h"

void main(void) {   
    Game* breakout = new Game();

    breakout->init();
    breakout->run();

    delete breakout;
}