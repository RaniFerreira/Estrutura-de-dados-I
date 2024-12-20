#include <iostream>
#include <cctype>

using namespace std;

struct No {
    char valor;
    No* prox;

    No(char _valor) {
        valor = _valor;
        prox = NULL;
    }
};

struct Pilha {
    No* topo;

    Pilha() {
        topo = NULL;
    }

    void inserir(char valor) {
        No* novo = new No(valor);
        novo->prox = topo;
        topo = novo;
    }

    void remover() {
        if (topo != NULL) {
            No* aux = topo;
            topo = topo->prox;
            delete aux;
        }
    }

    char topoPilha() {
        if (topo == NULL) return '\0';
        return topo->valor;
    }
};

int main() {
    string palavra;

    cin >> palavra;

    Pilha p;

    for (int i = 0; i < palavra.size(); i++) {
        // Convertendo para maiúsculo
        if (islower(palavra[i])) {
            palavra[i] = toupper(palavra[i]);
        }

        // Inserindo vogais na pilha
        if (palavra[i] == 'A' || palavra[i] == 'E' || palavra[i] == 'I' || palavra[i] == 'O' || palavra[i] == 'U') {
            p.inserir(palavra[i]);
        }
    }

    // Substituindo as vogais pela ordem inversa na palavra original
    for (int i = 0; i < palavra.size(); i++) {
        if (palavra[i] == 'A' || palavra[i] == 'E' || palavra[i] == 'I' || palavra[i] == 'O' || palavra[i] == 'U') {
            char topo = p.topoPilha();
            cout << topo;
            p.remover();
        } else {
            cout << palavra[i];
        }
    }

    cout << endl;

    return 0;
}
