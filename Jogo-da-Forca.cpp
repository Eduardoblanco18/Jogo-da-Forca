#include <iostream>
#include <string>
#include <map>
#include <array>
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
static array<char, 5> chutes_errados;
int quant_de_erros = 0;

int main () {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    imprime_cabecalho();

    palavra_secreta = sortea_palavra();

    while(nao_acertou(palavra_secreta, chutou) && quant_de_erros < 5){

        imprime_erros(chutes_errados, quant_de_erros);

        imprime_palavra(palavra_secreta, chutou);
        
        chuta (palavra_secreta,chutou, chutes_errados, quant_de_erros);
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