#ifndef __CODEMAKER_H__
#define __CODEMAKER_H__

#include "colors.hpp"
#include <vector>

class Codemaker{
    private:
       const int numOfPegs = 4;
       vector<Color> code;
       vector<Color> hint;
       vector<Color>& computeHint(const vector<Color>& ans);

    public:
       Codemaker();
       void createCode();
       void showHint();
};
#endif