#include "colorHelpers.hpp"
#include "code.hpp"
#include <vector>
#include<iostream>

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