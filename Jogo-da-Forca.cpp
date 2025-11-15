#include <iostream>
#include <string>
using namespace std;

int main () {
    string palavra_chave = "MELANCIA";
    cout << palavra_chave << endl;

    bool nao_acertou = true, nao_enforcou = true;

    while(nao_acertou && nao_enforcou){
        char chute;
        cin >> chute;

        cout << "O seu chute foi " << chute << endl;
    }
}