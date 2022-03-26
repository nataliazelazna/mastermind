#ifndef __COLOR_HELPERS_H__
#define __COLOR_HELPERS_H__

//#include "colors.hpp"
#include <map>
#include <vector>
#include <iostream>

 enum class Color {
    R,         /* red */
    O,         /* orange */
    G,         /* green */
    Y,         /* yellow */
    B,         /* black */
    W,         /* white */
    blank = -1
};


class ColorHelpers{
    private: 
        static std::vector<Color> allColors;
        static std::map<Color,char> colorToChar;
        static std::map<char,Color> charToColor;

    public:
         static Color randomColor();
         static char mapColorToChar(const Color& c);    
         static Color mapCharToColor(const char& c);
    friend std::ostream& operator<<(std::ostream& os, const Color& c);
 //  friend std::istream& operator>>(std::istream& is, Color c);     
};

#endif