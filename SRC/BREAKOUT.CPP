#include "GAME.H"
#include <iostream.h>

void main(void) {   
    Game* breakout = new Game();

    breakout->loop();

    delete breakout;
    
    cout << "\tDeveloped by M. Sami GURPINAR\n     In a lot of blood, sweat, and tears.\n";

}