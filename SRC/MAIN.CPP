#include "GAME.H"

void main(void) {   
    Game* breakout = new Game();

    breakout->init();
    breakout->run();

    delete breakout;
}