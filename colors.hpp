#ifndef __COLORS_H__
#define __COLORS_H__

#include<vector>
#include<random>
 enum Color {
    R,         /* red */
    O,         /* orange */
    G,         /* green */
    Y,         /* yellow */
    B,         /* black */
    W,         /* white */
    blank = -1
};


Color randomColor(){
    std::vector<Color> allColors ={Color::R, Color::B, Color::G, Color::Y, Color::B, Color::W };
    std::random_device rd;              //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd());             //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<std::size_t> dist(0, allColors.size() - 1);    //Length of the interval for uniform distribution
    Color randColor = allColors[dist(gen)];
    return randColor;
}
#endif