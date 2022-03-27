#ifndef __CODEMAKER_H__
#define __CODEMAKER_H__

#include "code.hpp"
#include <vector>
#include <map>
class Codemaker{
    private:
       Code secret;
       std::map<Color,int> secretStats;
       void createSecretStats();
    public:
        void createSecret();
        Code computeHint(Code& ans);
        Code& revealSecretInCaseOfFailure();
};
#endif