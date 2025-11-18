#include <iostream>
#include <fstream>
#include "le_arquivo.hpp"

std::vector<std::string> le_arquivo() {
    std::vector<std::string> palavras_arquivo;
    std::ifstream arquivo;
    arquivo.open("palavras.txt");

    if(arquivo.is_open()){
        int quantidade_palavras;
        arquivo >> quantidade_palavras;

        for(int i = 0; i < quantidade_palavras; i++){
            std::string palavra_lida;
            arquivo >> palavra_lida;
            palavras_arquivo.push_back(palavra_lida);
        }
        arquivo.close();
        return palavras_arquivo;
    } else {
        std::cout << "Não foi possível acessar o banco de palavras." << std::endl;
        exit(0);
    }
}