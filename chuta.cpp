#include <iostream>
#include "letra_existe.hpp"
#include "chuta.hpp"

extern std::map<char, bool> chutou;
extern std::vector<char> chutes_errados;

void chuta (std::map<char, bool>& chutou, std::vector<char>& chutes_errados) {
    char chute;
    std::cout << "Faça seu chute: ";
    std::cin >> chute;

    chutou[chute] = true;

    if(letra_existe(chute)){
        std::cout << "Você acertou! Seu chute está na palavra!" << std::endl;
    } else {
        std::cout << "Você errou! Seu chute não está na palavra!" << std::endl;
        chutes_errados. push_back(chute);
    }
    std::cout << std::endl;
}