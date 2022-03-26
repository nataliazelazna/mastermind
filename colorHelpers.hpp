#ifndef __COLOR_HELPERS_H__
#define __COLOR_HELPERS_H__

//#include "colors.hpp"
#include <map>
#include <vector>
#include <iostream>

 enum  Color {
    R,         /* red */
    O,         /* orange */
    G,         /* green */
    Y,         /* yellow */
    B,         /* black */
    W,         /* white */
    blank = -1 /* empty field in answer */
};

class ColorHelpers{
    private: 
        static std::vector<Color> allColors;
        static std::map<Color,char> colorToChar;
        static std::map<char,Color> charToColor;

    public:
         static Color randomColor();
         static char mapColorToChar( Color& c);    
         static Color mapCharToColor(char& c);

    friend std::ostream& operator<<(std::ostream& os, Color& c);
 //  friend std::istream& operator>>(std::istream& is, Color c);     
};

#endif