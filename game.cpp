#include <iostream>
#include "game.hpp"
#include "code.hpp"
#include "colorHelpers.hpp"
#include <algorithm>

using namespace std;

Code Game::getUserAnswer(){
    char c;
    Color col;
    Code answer;
    vector<char> userInput;
    vector<Color> ans;
    
    do {
        userInput.clear();
        cout<<"Provide your answer: ";
        for (int i = 0; i < Code::numOfPegs; ++i){
            cin>>c;
            userInput.push_back(c);
        }  
        for(auto elem :  userInput) {
            col = ColorHelpers::mapCharToColor(elem);
            if (col == Color::blank) {
                cout<<"Invalid color, please retry from the beginning\n";
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

Code Game::getHint(Code& answer){
    return cm.computeHint(answer);
}

void Game::playMastermind(){
    /* create secret once for game */
    cm.createSecret();
    cout<<"Secret of length 4 is ready, start guessing. Colors may repeat\n";
    cout<<"Avalaible colors are: R (red), O(orange), G(green), Y(yellow), V(violet), P(purple)\n";

    bool isUserAnswerCorrect = false;
    int roundNo = 1;
    /* loop until all black or 10 rounds completed */
    do {
        Code answer = getUserAnswer();
        wholeGame.push_back(answer);
        Code hint = getHint(answer);
        cout<<hint;
        wholeGame.push_back(hint);
        vector<Color> correct = hint.getCode();
        isUserAnswerCorrect = all_of(correct.cbegin(), correct.cend(), [](Color col){return col ==Color::B; });
        if (isUserAnswerCorrect) {
            cout<<"Congratulations! You guessed the code in "<<roundNo<<" rounds\n";
        }
        roundNo++;
    } while ((roundNo <= numOfRounds) && (isUserAnswerCorrect == false));

    if (isUserAnswerCorrect == false) {
        cout<<"Correct answer is: "<<cm.revealSecretInCaseOfFailure();
    } 
}

