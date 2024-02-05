#include "GAME.H"

void main(void) {   
    Game* breakout = new Game();

    breakout->run();

    delete breakout;
}