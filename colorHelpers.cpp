#include <iostream>
#include <map>
#include "colorHelpers.hpp"
#include <vector>
#include <random>

using namespace std;

vector<Color> ColorHelpers::allColors = {Color::R, Color::O, Color::G, Color::Y, Color::V, Color::P };
map<Color, char> ColorHelpers::colorToChar = {
            {Color::R, 'R'},
            {Color::O, 'O'},
            {Color::G, 'G'},
            {Color::Y, 'Y'},
            {Color::V, 'V'},
            {Color::P, 'P'},
            {Color::B, 'B'},
            {Color::W, 'W'},
            {Color::blank, '_'}
        };
map<char, Color> ColorHelpers::charToColor = {
            {'R', Color::R},
            {'O', Color::O},
            {'G', Color::G},
            {'Y', Color::Y},
            {'V', Color::V},
            {'P', Color::P},
        }; 

/* this solution comes from google, I wasn't familiar with such approach for generating random values from enum */
Color ColorHelpers::randomColor(){    
    random_device rd;              //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd());             //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<size_t> dist(0, allColors.size() - 1);    //Length of the interval for uniform distribution
    Color randColor = allColors[dist(gen)];
    return randColor;
}

char ColorHelpers::mapColorToChar(const Color& color){
    map<Color,char>::const_iterator pos = colorToChar.find(color);
    if (pos == colorToChar.end()){
        cout<<"invalid key\n";
        return '*';
    }
    else {
        return pos->second;
    }
}

 Color ColorHelpers::mapCharToColor(char& c){
    map<char, Color>::const_iterator pos = charToColor.find(c);
    if (pos == charToColor.end()){
        cout<<"invalid key\n";
        return Color::blank;
    }
    else {
        return pos->second;
    }
}

ostream& operator<<(ostream& os, const Color& c){
    char output = ColorHelpers::mapColorToChar(c);
    os<<output;
    return os;
}

