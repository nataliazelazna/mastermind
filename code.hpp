#ifndef __CODE_H__
#define __CODE_H__

#include <vector>
#include <iostream>
#include "colorHelpers.hpp"
#include <map>
class Code;
std::ostream& operator<<(std::ostream& os, const Code& cd);

class Code {
    private:
       const int numOfPegs = 4; //static
       std::vector<Color> code;
    public:
        Code();
        int getNumOfPegs() const {return this->numOfPegs;}
        Code generateRandomCode();
        Code& operator=(Code& orig);
        Code& setCode( std::vector<Color> data);
        std::map<Color, int> getStats();
        const std::vector<Color>& getCode() const {return this->code;}

        friend std::ostream& operator<<(std::ostream& os, const Code& cd);
//friend istream& operator>>(std::istream& is,Code& code);
};


#endif