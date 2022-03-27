
#include "colorHelpers.hpp"
#include "code.hpp"
#include <iostream>
#include "codemaker.hpp"
#include <vector>
#include <map>
#include <string>
#include "game.hpp"

int main(){
    Codemaker cm;
    cm.createSecret();
    std::cout<<"secret "<<cm.revealSecretInCaseOfFailure();
    Code ans;
    std::vector<Color> v = {Color::R, Color::B, Color::Y, Color::Y};
    ans.setCode(v);
    std::cout<<"answer "<<ans<<std::endl;
    std::map<Color, int> stat = ans.getStats();

    std::cout<<cm.computeHint(ans);
    Game g;
    std::cout<<g.getAnswer();
   

}