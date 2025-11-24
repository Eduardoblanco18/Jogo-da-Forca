#include <string>
#include "letra_existe.hpp"

bool letra_existe (std::string palavra_secreta, char chute) {
    for(char letra : palavra_secreta){
        if (chute == letra){
            return true;
        }
    }

    return false;
}