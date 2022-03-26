#include "codemaker.hpp"
#include "color.hpp"

Codemaker::Codemaker(){
    for (int i = 0; i <numOfPegs; i++){
        code[i] = Color::blank;
        answer[i] = Answer::blank;
    }
}

void Codemaker::createCode(){
    for (int i = 0; i <numOfPegs; i++){
        code[i] = randomColor();
    }
}


