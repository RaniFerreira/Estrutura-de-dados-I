#include <iostream>
#include <string>
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

    void empilhar(char valor) {
        No* novo = new No(valor);
        novo->prox = topo;
        topo = novo;
    }

    char desempilhar() {
        if (topo != NULL) {
            No* aux = topo;
            topo = topo->prox;
            char valor = aux->valor;
            delete aux;
            return valor;
        }
        return '\0';
    }

    bool vazia() {
        return topo == NULL;
    }
};

string inverterString(string s) {
    Pilha p;
    // Empilhar todos os caracteres da string
    for (char c : s) {
        p.empilhar(c);
    }

    string invertida = "";
    // Desempilhar os caracteres para inverter a string
    while (!p.vazia()) {
        invertida += p.desempilhar();
    }
    return invertida;
}

int main() {
    string s;
    cin >> s;

    cout << "String invertida: " << inverterString(s) << endl;
    return 0;
}
