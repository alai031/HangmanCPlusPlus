#include "game.hpp"
#include <iostream>
#include <algorithm>
#include <random>
#include <cctype>

using namespace std;

Game::Game(){
    misses = 0;
    answer = "";
    current = "";
    generateRandomString();
}

void Game::introMessage(){
    cout << "Welcome to Hangman!" << endl;
    cout << "A random word has been chosen. Try to guess it!" << endl;
}

void Game::generateRandomString(){
    srand(time(0));
    vector<string> randomStrings = {"Oranges", "Grapes", "strawberries", "pineapple", "lemons", "grapefruit"};
    int randomNum = rand() % randomStrings.size();
    answer = randomStrings[randomNum];
    
    for (int i = 0; i < answer.length(); ++i){
        answer[i] = tolower(answer[i]);
        if (answer[i] == ' ')
            current += ' ';
        else
            current += '_';
    }
}

int Game::getMisses(){
    return misses;
}

void Game::display(int numMisses){
    if (numMisses == 0){
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "      | \n";
        cout << "      | \n";
        cout << "      | \n";
        cout << "      | \n";
    }
    else if (numMisses == 1){
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  O   | \n";
        cout << "      | \n";
        cout << "      | \n";
        cout << "      | \n";
    }
    else if (numMisses == 2){
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  O   | \n";
        cout << "  |   | \n";
        cout << "      | \n";
        cout << "      | \n";
    }
    else if (numMisses == 3){
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  O   | \n";
        cout << "  |   | \n";
        cout << "   \\  | \n";
        cout << "      | \n";
    }
    else if (numMisses == 4){
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  O   | \n";
        cout << "  |   | \n";
        cout << " / \\  | \n";
        cout << "      | \n";
    }
    else if (numMisses == 5){
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  O   | \n";
        cout << "  |\\  | \n";
        cout << " / \\  | \n";
        cout << "      | \n";
    }
    else if (numMisses == 6){
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  O   | \n";
        cout << " /|\\  | \n";
        cout << " / \\  | \n";
        cout << "      | \n";
    }
}

void Game::insertGuess(char guess){
    if (find(guesses.begin(), guesses.end(), tolower(guess)) != guesses.end() || find(guesses.begin(), guesses.end(), toupper(guess)) != guesses.end()){
        cout << "Character " << guess << " already found. Please try a different character." << endl;
    }

    else{
        guesses.push_back(guess);
        if (count(answer.begin(), answer.end(), tolower(guess)) == 0 && count(answer.begin(), answer.end(), toupper(guess)) == 0){
            ++misses;
            cout << "Character " << guess << " not found" << endl;
        }
        else{
            for (int i = 0; i < current.size(); ++i){
                if (tolower(guess) == tolower(answer[i]) || toupper(guess) == toupper(answer[i])){
                    current[i] = answer[i];
                }
            }
            cout << "Character " << guess << " found" << endl;
        }
    }

    cout << "Current: ";
    for (int i = 0; i < current.size(); ++i){
        cout << current[i] << " ";
    }
    cout << endl;

    if (current != answer && misses < 6){
        cout << "Attempted characters: ";
        for (int l = 0; l < guesses.size(); ++l){
            cout << guesses[l] << " ";
        }
        cout << endl;
        cout << "Attempts remaining: " << 6-misses << endl;
    }
}

bool Game::isOver(){
    if (current == answer)
        return true;
    return false;
}

string Game::getAnswer(){
    return answer;
}