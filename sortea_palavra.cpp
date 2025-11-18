#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include "le_arquivo.hpp"
#include "sortea_palavra.hpp"

std::string palavra_secreta;

void sortea_palavra() {
    std::vector<std::string> palavras =le_arquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();

    palavra_secreta = palavras[indice_sorteado];
}