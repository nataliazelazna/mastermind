#ifndef __GAME_H__
#define __GAME_H__

#include "codemaker.hpp"
#include "codebreaker.hpp"
#include <vector>

class Game{
    private:
        const int numOfRounds = 10; 
        Codemaker cm;          //this is a computer player with some logic
        Codebreaker cb;        //this is a human player
        Code currentHint;      //hint received in current round, will be computed by codemaker and received by codebreaker via game module
        std::vector<Code> allGivenAnswers;
        std::vector<Code> allReceivedHints;
        std::vector<Code> wholeGame;
    public:
        Code getAnswer();
        void showHint();
        void playMastermind();
};
#endif