#include "colors.hpp"
#include <iostream>
#include <map>

ColorHelpers::colorToChar = {
            {R, 'R'},
            {O, 'O'},
            {G, 'G'},
            {Y, 'Y'},
            {B, 'B'},
            {W, 'W'},
            {blank, '_'}
        };
ColorHelpers::charToColor = {
            {'R', R},
            {'O', O},
            {'G', G},
            {'Y', Y},
            {'B', B},
            {'W', W},
            {'_', blank}
        };        

char ColorHelpers::mapColorToChar(const Color& color){
    std::map<Color,char>:const_iterator pos =  colorToChar.find(color);
    if (pos == colorToChar.end()){
        std::cout<<"invalid key\n";
        return '*';
    }
    else {
        return pos->second;
    }
}

Color ColorHelpers::mapCharToColor(const char& c){
    std::map<char, Color>:const_iterator pos =  charToColor.find(c);
    if (pos == charToColor.end()){
        std::cout<<"invalid key\n";
        return Color::blank;
    }
    else {
        return pos->second;
    }
}

std::ostream& operator<<(ostream& os, const Color& c){
    os<<mapColorToChar(c);
    return os;
}

std::istream& operator>>(istream& is, const Color& c){
    char input = mapCharToColor(c);
    is>>input;
    return is;
}