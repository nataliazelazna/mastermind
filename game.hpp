#ifndef __GAME_H__
#define __GAME_H__

#include "codemaker.hpp"
#include <vector>

class Game{
    private:
        const int numOfRounds = 10; 
        Codemaker cm;          //this is a computer player with some logic
    //    Code currentHint;      //hint received in current round, will be computed by codemaker and received by codebreaker via game module
        std::vector<Code> wholeGame;
    public:
        Code getUserAnswer();
        Code getHint(Code& answer);
        void playMastermind();
};
#endif