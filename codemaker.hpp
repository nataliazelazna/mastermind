#ifndef __CODEMAKER_H__
#define __CODEMAKER_H__

#include "colors.hpp"
#include <vector>
using namespace std;

class Codemaker{
    private:
       const int numOfPegs = 4;
       vector<Color> code;
       vector<Color> hint;
       void createCode();
    public:
       Codemaker();
       vector<Color>& void showHint(const vector<Color>& ans);
};
#endif