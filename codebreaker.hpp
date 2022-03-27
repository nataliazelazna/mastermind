#ifndef __CODEBREAKER_H__
#define __CODEBREAKER_H__

#include "colorHelpers.hpp"

class Codebreaker{
    private:
        Code currentAnswer;
        //perhaps should be moved to game?
        vector<Code> allGivenAnswers;
        vector<Code> allReceivedHints;
    public:
        Code giveAnswer();
        void showAllGivenAnswers();
};

#endif