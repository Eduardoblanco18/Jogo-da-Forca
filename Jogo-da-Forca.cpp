#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
const string PALAVRA_SECRETA = "GOIABADA";
map<char, bool> chutou;
vector<char> chutes_errados;

bool letra_existe (char chute) {
    for(char letra : PALAVRA_SECRETA){
        if (chute == letra){
            return true;
        }
    }

    return false;
}

bool nao_acertou() {
    for(char letra : PALAVRA_SECRETA){
        if(!chutou[letra]){
            return true;
        } 
    } 
    return false;
}

bool nao_enforcou() {
    return chutes_errados.size() < 5;
}

int main () {
    cout << "*********************************" << endl;
    cout << "***      Jogo da Forca        ***" << endl;
    cout << "*********************************" << endl;

    while(nao_acertou() && nao_enforcou()){

        cout << "Chutes errados: ";
        for(char letra : chutes_errados){
            cout << letra << " "; 
        }
        cout << endl;

        for(char letra : PALAVRA_SECRETA){
            if(chutou[letra]){
                cout << letra<< " ";
            } else {
                cout << "_ ";
            }
        }
        cout << endl;
        
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

    cout << "Fim de jogo!" << endl;

    if(nao_acertou()){
        cout << "Você perdeu! Tente novamente!";
    } else {
        cout << "Você acertou a palavra secreta!";
    }
}