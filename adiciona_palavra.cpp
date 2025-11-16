#include <iostream>
#include <string>
#include <vector>
#include "le_arquivo.cpp"
#include "salva_arquivo.cpp"

void adiciona_palavra(){
    std::cout << "Digite a nova palavra, usando letras maiúculas." << std::endl;
    std::string nova_palavra;
    std::cin >> nova_palavra;

    std::vector<std::string> lista_palavras = le_arquivo();
    lista_palavras.push_back(nova_palavra);

    salva_arquivo(lista_palavras);
}