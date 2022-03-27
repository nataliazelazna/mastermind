#include "codemaker.hpp"
#include "colorHelpers.hpp"
#include "code.hpp"
#include <vector>
#include <algorithm>

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
    std::vector<Color> tempHint = std::vector<Color>(Code::numOfPegs, Color::blank);
    std::vector<Color> ans = answer.getCode();
    std::vector<Color> secretVector = secret.getCode();
    std::map<Color,int> ansStats = answer.getStats();
    std::map<Color,int> secretStatsForAnswer = this->secretStats;

    //handle black pegs in answer
    int numOfBlack = 0;
    for(int i = 0; i < ans.size(); i++){
        if (ans[i] == secretVector[i]){
            tempHint[numOfBlack] = Color::B;
            ++numOfBlack;
            --ansStats[ans[i]];
            --secretStatsForAnswer[ans[i]];
        }
    }
  
    //handle white pegs
    int numOfWhite = 0;
    for(const auto& elem :secretStatsForAnswer){
        Color col = elem.first;
        auto it = std::find_if(ansStats.cbegin(), ansStats.cend(), [col](const std::pair<Color,int>& p){return p.first == col;});
        if (it != ansStats.cend()){
            numOfWhite += std::min(elem.second,it->second);
        }
    }
    for(int i = numOfBlack; i < numOfBlack+numOfWhite; ++i){
        tempHint[i] = Color::W;
    }

    hint.setCode(tempHint);
    return hint;
}

Code& Codemaker::revealSecretInCaseOfFailure(){
    return this->secret;
}
