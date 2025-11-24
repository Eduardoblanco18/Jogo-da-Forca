#include <iostream>
#include "imprime_erros.hpp"


void imprime_erros(const std::array<char, 5>& chutes_errados, int quant_de_erros) {
    std::cout << "Chutes errados: ";
    for(char letra : chutes_errados){
        std::cout << letra << " "; 
    }
    std::cout << std::endl;
}