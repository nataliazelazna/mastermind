#ifndef __GAME_H__
#define __GAME_H__

#include "codemaker.hpp"
#include <vector>

class Game{
    private:
        const int numOfRounds = 10; 
        Codemaker cm;          //this is a computer player with some logic
        std::vector<Code> wholeGame;
        Code getUserAnswer();
        Code getHint(Code& answer);
    public:
        void playMastermind();
};

#endif