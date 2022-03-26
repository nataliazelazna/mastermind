#ifndef __CODEBREAKER_H__
#define __CODEBREAKER_H__

#include "colors.hpp"
#include <vector>

class Codebreaker{
    private:
      vector<Color> answer;
      vector<vector<Color> > allGivenAnswers;
    public:
       vector<Color> giveAnswer();
       void showAllGivenAnswers();

};

#endif