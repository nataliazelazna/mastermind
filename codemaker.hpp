#ifndef __CODEMAKER_H__
#define __CODEMAKER_H__

#include "colors.hpp"
#include <vector>

class Codemaker{
    private:
       Code code;
       Code hint;
       Code& computeHint(const Code& ans);

    public:
       Codemaker();
       Code createCode();
       void showHint();
};
#endif