
#include "colorHelpers.hpp"
#include "code.hpp"
#include<iostream>

int main(){
    Code cd;
    Color col = Color::B;
    Color& c = col;
    std::cout<<ColorHelpers::mapColorToChar(c)<<std::endl;
    std::cout<<c<<std::endl;
  //  cd.generateRandomCode();
  //  std::cout<<cd[10];
  //  std::cout<<cd[0];
}