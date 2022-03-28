#include "codemaker.hpp"
#include "colorHelpers.hpp"
#include "code.hpp"
#include <vector>
#include <algorithm>

using namespace std;

void Codemaker::createSecret(){
    Code cd;
    cd.generateRandomCode();
    this->secret = cd;
    this->createSecretStats();
}

void Codemaker::createSecretStats(){
    secretStats = secret.getStats();
}

Code Codemaker::computeHint(Code& answer){
    Code hint;
    vector<Color> tempHint = vector<Color>(Code::numOfPegs, Color::blank);
    vector<Color> ans = answer.getCode();
    vector<Color> secretVector = secret.getCode();
    map<Color,int> ansStats = answer.getStats();
    map<Color,int> secretStatsForAnswer = this->secretStats;

    //handle black pegs in answer
    int numOfBlack = 0;
    for(int i = 0; i < ans.size(); ++i){
        if (ans[i] == secretVector[i]){
            tempHint[numOfBlack] = Color::B;
            ++numOfBlack;
            --ansStats[ans[i]];
            --secretStatsForAnswer[ans[i]];
        }
    }
  
    //handle white pegs, lambda comes from google, I was aware that it exists in c++
    int numOfWhite = 0;
    for(const auto& elem :secretStatsForAnswer){
        Color col = elem.first;
        auto it = find_if(ansStats.cbegin(), ansStats.cend(), [col](const pair<Color,int>& p){return p.first == col;});
        if (it != ansStats.cend()){
            numOfWhite += min(elem.second,it->second);
        }
    }
    for(int i = numOfBlack; i < numOfBlack+numOfWhite; ++i){
        tempHint[i] = Color::W;
    }

    hint.setCode(tempHint);
    return hint;
}

const Code& Codemaker::revealSecretInCaseOfFailure(){
    return this->secret;
}