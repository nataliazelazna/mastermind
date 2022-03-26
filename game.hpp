#ifndef __GAME_H__
#define __GAME_H__

#include "codemaker.hpp"
#include "codebreaker.hpp"

using namespace std;

class Game{
    private:
       const int numOfRounds = 10; //dowiedz sie wiecej o constach w klasie
       Codemaker cm;      //this is a computer player with some logic
       Codebreaker cb;    //this is a human player
    public:
       Game();
       void playMastermind();
};
#endif