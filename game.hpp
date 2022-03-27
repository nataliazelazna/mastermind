#ifndef __GAME_H__
#define __GAME_H__

#include "codemaker.hpp"
#include "codebreaker.hpp"

using namespace std;

class Game{
    private:
        const int numOfRounds = 10; 
        Codemaker cm;      //this is a computer player with some logic
        Codebreaker cb;    //this is a human player
        Code currentHint;  //hint received in current round, will be computed by codemaker and received by codebreaker via game module
    public:
       Game();
       void playMastermind();
};
#endif