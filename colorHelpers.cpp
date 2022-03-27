#include <iostream>
#include <map>
#include "ColorHelpers.hpp"
#include <vector>
#include <random>

std::vector<Color> ColorHelpers::allColors = {Color::R, Color::O, Color::G, Color::Y, Color::B, Color::W };
std::map<Color, char> ColorHelpers::colorToChar = {
            {Color::R, 'R'},
            {Color::O, 'O'},
            {Color::G, 'G'},
            {Color::Y, 'Y'},
            {Color::B, 'B'},
            {Color::W, 'W'},
            {Color::blank, '_'}
        };
std::map<char, Color> ColorHelpers::charToColor = {
            {'R', Color::R},
            {'O', Color::O},
            {'G', Color::G},
            {'Y', Color::Y},
            {'B', Color::B},
            {'W', Color::W},
            {'_', Color::blank}
        }; 

/* this solution comes from google, I wasn't familiar with such approach for generating random values from enum */
Color ColorHelpers::randomColor(){    
    std::random_device rd;              //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd());             //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<std::size_t> dist(0, allColors.size() - 1);    //Length of the interval for uniform distribution
    Color randColor = allColors[dist(gen)];
    return randColor;
}

char ColorHelpers::mapColorToChar(const Color& color){
    std::map<Color,char>::const_iterator pos = colorToChar.find(color);
    if (pos == colorToChar.end()){
        std::cout<<"invalid key\n";
        return '*';
    }
    else {
        return pos->second;
    }
}

 Color ColorHelpers::mapCharToColor(char& c){
    std::map<char, Color>::const_iterator pos = charToColor.find(c);
    if (pos == charToColor.end()){
        std::cout<<"invalid key\n";
        return Color::blank;
    }
    else {
        return pos->second;
    }
}

std::ostream& operator<<(std::ostream& os, const Color& c){
    char output = ColorHelpers::mapColorToChar(c);
    os<<output;
    return os;
}
/*
std::istream& operator>>(std::istream& is, const Color& c){
    char& input = ColorHelpers::mapCharToColor(c);
    is>>input;
    return is;
}
*/