#include <iostream>
#include "game.hpp"

using namespace std;

int main(){

    Game* newGame = new Game();
    newGame->introMessage();

    return 0;
}