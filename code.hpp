#ifndef __CODE_H__
#define __CODE_H__

#include <vector>
#include <iostream>
#include "colorHelpers.hpp"

class Code;
std::ostream& operator<<(std::ostream& os,  Code& cd);

class Code {
    private:
       const int numOfPegs = 4;
       std::vector<Color> code;
    public:
        Code();
        int getNumOfPegs(){ return this->numOfPegs;}
        Code generateRandomCode();
        Color& operator[](int idx);
friend std::ostream& operator<<(std::ostream& os,  Code& cd);
//friend istream& operator>>(std::istream& is,Code& code);
};


#endif