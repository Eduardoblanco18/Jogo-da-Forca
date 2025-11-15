#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

string palavra_secreta = "GOIABADA";
map<char, bool> chutou;
vector<char> chutes_errados;

bool letra_existe (char chute) {
    for(char letra : palavra_secreta){
        if (chute == letra){
            return true;
        }
    }

    return false;
}

bool nao_acertou() {
    for(char letra : palavra_secreta){
        if(!chutou[letra]){
            return true;
        } 
    } 
    return false;
}

bool nao_enforcou() {
    return chutes_errados.size() < 5;
}

void imprime_cabecalho(){
    cout << "*********************************" << endl;
    cout << "***      Jogo da Forca        ***" << endl;
    cout << "*********************************" << endl;
    cout << endl;
}

void imprime_erros (){
    cout << "Chutes errados: ";
    for(char letra : chutes_errados){
        cout << letra << " "; 
    }
    cout << endl;
}

void imprime_palavra (){
    for(char letra : palavra_secreta){
        if(chutou[letra]){
            cout << letra<< " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

void chuta (){
    char chute;
    cout << "Faça seu chute: ";
    cin >> chute;

    chutou[chute] = true;

    if(letra_existe(chute)){
        cout << "Você acertou! Seu chute está na palavra!" << endl;
    } else {
        cout << "Você errou! Seu chute não está na palavra!" << endl;
        chutes_errados.push_back(chute);
    }
    cout << endl;
}

vector<string> le_arquivo(){
    vector<string> palavras_arquivo;
    ifstream arquivo;
    arquivo.open("palavras.txt");

    if(arquivo.is_open()){
        int quantidade_palavras;
        arquivo >> quantidade_palavras;

        for(int i = 0; i < quantidade_palavras; i++){
            string palavra_lida;
            arquivo >> palavra_lida;
            palavras_arquivo.push_back(palavra_lida);
        }
        arquivo.close();
        return palavras_arquivo;
    } else {
        cout << "Não foi possível acessar o banco de palavras." << endl;
        exit(0);
    }
}

void sortea_palavra(){
    vector<string> palavras =le_arquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();

    palavra_secreta = palavras[indice_sorteado];
}

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
        cout << "Você acertou a palavra secreta!";
    }
}