#include "codemaker.hpp"
#include "color.hpp"

Codemaker::Codemaker(){

}

void Codemaker::createCode(){
    for (int i = 0; i <numOfPegs; i++){
        code[i] = randomColor();
    }
}


