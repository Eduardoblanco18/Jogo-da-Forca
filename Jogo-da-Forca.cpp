#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "nao_acertou.hpp"
#include "letra_existe.hpp"
#include "nao_enforcou.hpp"
#include "imprime_cabecalho.hpp"
#include "imprime_erros.hpp"
#include "imprime_palavra.hpp"
#include "chuta.hpp"
#include "le_arquivo.hpp"
#include "sortea_palavra.hpp"
#include "salva_arquivo.hpp"
#include "adiciona_palavra.hpp"

using namespace std;

string palavra_secreta;
map<char, bool> chutou;
vector<char> chutes_errados;

int main () {
    imprime_cabecalho();

    sortea_palavra();

    while(nao_acertou() && nao_enforcou()){

        imprime_erros();

        imprime_palavra();
        
        chuta ();
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era " << palavra_secreta << endl;

    if(nao_acertou()){
        cout << "Você perdeu! Tente novamente!";
    } else {
        cout << "Parabéns! Você acertou a palavra secreta!";

        cout << "Você deseja adicionar uma nova palavra ao banco? (S/N)";
        char resposta;
        cin >> resposta;
        if(resposta == 'S'){
           adiciona_palavra(); 
        }
    }
}