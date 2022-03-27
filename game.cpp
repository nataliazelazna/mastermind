#include <iostream>
#include "game.hpp"
#include "code.hpp"
#include "colorHelpers.hpp"

Code Game::getAnswer(){
    char c;
    Color col;
    Code answer;
    std::vector<char> userInput;
    std::vector<Color> ans;
    
    do {
        userInput.clear();
        std::cout<<"Provide your answer: ";
        for (int i = 0; i < Code::numOfPegs; ++i){
            std::cin>>c;
            userInput.push_back(c);
        }  
        for(auto elem :  userInput) {
            col = ColorHelpers::mapCharToColor(elem);
            if (col == Color::blank) {
                std::cout<<"Invalid color, please retry from the beginning\n";
                ans.clear();
                break;
            }
            else {
                ans.push_back(col);
            }
           
        }
    } while(ans.size() < Code::numOfPegs);
    answer.setCode(ans);
    return answer;

}

