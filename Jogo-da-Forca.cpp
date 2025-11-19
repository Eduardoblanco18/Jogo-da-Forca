#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <Windows.h>
#include "nao_acertou.hpp"
#include "letra_existe.hpp"
#include "imprime_cabecalho.hpp"
#include "imprime_erros.hpp"
#include "imprime_palavra.hpp"
#include "chuta.hpp"
#include "le_arquivo.hpp"
#include "sortea_palavra.hpp"
#include "salva_arquivo.hpp"
#include "adiciona_palavra.hpp"

using namespace std;

static string palavra_secreta;
static map<char, bool> chutou;
static vector<char> chutes_errados;

int main () {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    imprime_cabecalho();

    palavra_secreta = sortea_palavra();

    while(nao_acertou(palavra_secreta, chutou) && chutes_errados.size() < 5){

        imprime_erros(chutes_errados);

        imprime_palavra(palavra_secreta, chutou);
        
        chuta (chutou, chutes_errados);
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era " << palavra_secreta << endl;

    if(nao_acertou(palavra_secreta, chutou)){
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