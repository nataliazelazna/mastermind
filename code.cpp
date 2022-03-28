#include "colorHelpers.hpp"
#include "code.hpp"
#include <vector>
#include<iostream>
#include <algorithm>
#include <map>

using namespace std;

const int Code::numOfPegs = 4;

Code::Code(){
    code = vector<Color>(numOfPegs, Color::blank);
}

Code Code::generateRandomCode(){
    for (int i = 0; i <numOfPegs; ++i){
        this->code[i] = ColorHelpers::randomColor();
    }
    return *this;
}

Code& Code::operator=(Code& orig){
    if(this == &orig){
        return *this;
    }
    copy(orig.code.begin(), orig.code.end(), this->code.begin());
    return *this;
}

Code& Code::setCode( vector<Color> data){
    copy(data.begin(), data.end(), this->code.begin());
    return *this;
}

map<Color,int> Code::getStats(){
    map<Color,int> stat;
    vector<Color> colors = this->getCode();
    for(auto elem: colors){
        int occurences = count(colors.cbegin(), colors.cend(), elem);
        stat[elem] = occurences;
    }
    return stat;
}

ostream& operator<<(ostream& os, const Code& cd){
    vector<Color> tmp = cd.getCode();
    for(int i = 0; i < Code::numOfPegs; ++i){
        os<<(cd.getCode())[i]<<" ";
     }
     os<<endl;
     return os;
 }