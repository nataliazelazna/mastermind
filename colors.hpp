#ifndef __COLORS_H__
#define __COLORS_H__

#include <random>
#include <vector>

enum Color = {
    red,
    blue,
    green,
    yellow, 
    black,
    white,
    blank = -1;
}

/*this I googled, wasn't familiar with such a construction */

Color randomColor(){
    std::vector<Color> allColors({Color::red, Color::blue, Color::green, Color::yellow, Color::black, Color::white });
    std::random_device rd;              //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd());             //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<size_t> dist(0, allColors.size() - 1);    //Length of the interval for uniform distribution
    Color randColor = allColors[dist(gen)];
    return randColor;
}
#endif