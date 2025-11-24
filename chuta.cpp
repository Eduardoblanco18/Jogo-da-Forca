#include <iostream>
#include "letra_existe.hpp"
#include "chuta.hpp"

void chuta (std::string palavra_secreta, std::map<char, bool>& chutou, std::array<char, 5>& chutes_errados, int quant_de_erros) {
    char chute;
    std::cout << "Faça seu chute: ";
    std::cin >> chute;

    chutou[chute] = true;

    if(letra_existe(palavra_secreta, chute)){
        std::cout << "Você acertou! Seu chute está na palavra!" << std::endl;
    } else {
        std::cout << "Você errou! Seu chute não está na palavra!" << std::endl;
        chutes_errados[quant_de_erros] = chute;
        quant_de_erros++;
    }
    std::cout << std::endl;
}