#include "code.hpp"
#include<iostream>

int main(){
   Code cd;
   cd.generateRandomCode();
    std::cout<<cd[10];
    std::cout<<cd[0];
    std::cout<<"dupa";
}