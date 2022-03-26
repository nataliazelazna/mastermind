#ifndef __CODEMAKER_H__
#define __CODEMAKER_H__

#include "colors.hpp"
#include <vector>
using namespace std;

class Codemaker{
    private:
       vector<Color> code;
       vector<Answer> hint;
       void createCode();
    public:
       Codemaker();
       void showHint(const vector<Color>& ans);
};
#endif