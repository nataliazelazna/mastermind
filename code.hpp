#ifndef __CODE_H__
#define __CODE_H__

#include <vector>
#include <iostream>
#include "colorHelpers.hpp"
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

Code::Code(){
    code = std::vector<Color>(numOfPegs, Color::blank);
}

Color& Code::operator[](int idx) {
    Color blank = Color::blank;
    Color& result = blank;
    if (idx >= numOfPegs) {
        std::cout<<"index out of bonds, returning blank\n";
        return result;
    }
    return code[idx];
}

Code Code::generateRandomCode(){
    for (int i = 0; i <numOfPegs; i++){
        this->code[i] = ColorHelpers::randomColor();
        std::cout<<this->code[i];
    }
    return *this;
}

 std::ostream& operator<<(std::ostream& os,  Code& cd){
     for(int i = 0; i < cd.getNumOfPegs(); i++){
         os<<cd[i]<<" ";
     }
     os<<std::endl;
     return os;
 }
#endif