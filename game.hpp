#ifndef GAME_CLASS
#define GAME_CLASS
#include <string>
#include <vector>

using namespace std;

class Game{
    public:
        Game();
        void introMessage();
        void generateRandomString();
        int getMisses();
        void display(int numMisses);
        void insertGuess(char guess);
        bool isOver();
        string getAnswer();

    private:
        int misses;
        string answer;
        string current;
        vector<char> guesses;
};


#endif