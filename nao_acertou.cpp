#include <string>
#include <map>
#include "nao_acertou.hpp"

extern std::string palavra_secreta = "GOIABADA";
extern std::map<char, bool> chutou;

bool nao_acertou() {
    for(char letra : palavra_secreta){
        if(!chutou[letra]){
            return true;
        } 
    } 
    return false;
}