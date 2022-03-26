#include "colors.hpp"
#include <map>
#include <vector>
#include <iostream>
class ColorHelpers{
    private: 
        static std::vector<Color> allColors;
        static std::map<Color,char> colorToChar;
        static std::map<char,Color> charToColor;

    public:
         Color randomColor();
         char mapColorToChar(Color c);    
    friend std::ostream& operator<<(std::ostream& os, Color c);
    friend std::istream& operator>>(std::istream& is, Color c);     
};