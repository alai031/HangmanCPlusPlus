#include <iostream>
#include "game.hpp"

using namespace std;

int main(){

    Game* game = new Game();
    game->introMessage();
    for (int i = 0; i < game->getAnswer().length(); ++i){
        if (game->getAnswer()[i] == ' ')
            cout << "  ";
        else
            cout << "_ ";
    }
    cout << endl;
    char guess;
    
    while ( game->getMisses() < 6 && !game->isOver()){
        game->display(game->getMisses());
        cout << endl;
        cout << "Guess a character: " << endl;
        cin >> guess;
        cout << endl;
        game->insertGuess(guess);
    }

    if (game->getMisses() < 6){
        cout << endl << endl << "You guessed correctly! ! ! Well done :)" << endl << endl << endl;
    }
    else{
        cout << endl << endl << "You've run out of guesses. You lose :(" << endl; 
        cout << "The answer was '" << game->getAnswer() << "'.";
        cout << endl << endl << endl;
    }

    return 0;
}