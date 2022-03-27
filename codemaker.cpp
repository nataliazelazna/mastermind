#include "codemaker.hpp"
#include "colorHelpers.hpp"
#include "code.hpp"
#include <vector>
#include <algorithm>

void Codemaker::createSecret(){
    Code cd;
    cd.generateRandomCode();
    this->secret = cd;
}

void Codemaker::createSecretStats(){
    secretStats = secret.getStats();
}

Code Codemaker::computeHint(Code& answer){
    int numOfWhite = 0;
    int cntBlack = 0;
    Code hint;
    std::vector<Color> tempHint = std::vector<Color>(answer.getNumOfPegs(), Color::blank);
    std::vector<Color> ans = answer.getCode();
    std::vector<Color> secretVector = secret.getCode();
    std::map<Color,int> ansStats = answer.getStats();
    std::map<Color,int> secretStatsForAnswer = this->secretStats;
    //handle black pegs n answer
    for(int i = 0; i < ans.size(); i++){
        if (ans[i] == secretVector[i]){
            tempHint[cntBlack] = Color::B;
            ++cntBlack;
            --ansStats[ans[i]];
            --secretStatsForAnswer[ans[i]];
        }
    }
    //handle white pegs



    hint.setCode(tempHint);
    return hint;

}

Code& Codemaker::revealSecretInCaseOfFailure(){
    return this->secret;
}
