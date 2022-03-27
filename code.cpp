#include "colorHelpers.hpp"
#include "code.hpp"
#include <vector>
#include<iostream>
#include <algorithm>
#include <map>

Code::Code(){
    code = std::vector<Color>(numOfPegs, Color::blank);
}

Code Code::generateRandomCode(){
    for (int i = 0; i <numOfPegs; i++){
        this->code[i] = ColorHelpers::randomColor();
    }
    return *this;
}

Code& Code::operator=(Code& orig){
    if(this == &orig){
        return *this;
    }
    std::copy(orig.code.begin(), orig.code.end(), this->code.begin());
    return *this;
}

Code& Code::setCode( std::vector<Color> data){
    std::copy(data.begin(), data.end(), this->code.begin());
    return *this;
}

std::map<Color,int> Code::getStats(){
    std::map<Color,int> stat;
    std::vector<Color> colors = this->getCode();
    std::vector<Color>::iterator it = colors.begin();
    for(auto elem: colors){
        Color x = elem;
        int occurences = std::count(colors.cbegin(), colors.cend(), elem);
        stat[elem] = occurences;
    }
    return stat;
}

std::ostream& operator<<(std::ostream& os, const Code& cd){
    std::vector<Color> tmp = cd.getCode();
    for(int i = 0; i < cd.getNumOfPegs(); i++){
        os<<(cd.getCode())[i]<<" ";
     }
     os<<std::endl;
     return os;
 }