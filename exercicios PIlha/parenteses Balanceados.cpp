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

bool verificaBalanceamento(string s) {
    Pilha p;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            p.empilhar(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (p.vazia()) return false;
            char topo = p.desempilhar();
            if ((c == ')' && topo != '(') || (c == '}' && topo != '{') || (c == ']' && topo != '[')) {
                return false;
            }
        }
    }
    return p.vazia();  // Se a pilha estiver vazia, os parênteses estão balanceados
}

int main() {
    string s;
    cin >> s;

    if (verificaBalanceamento(s)) {
        cout << "Expressão balanceada!" << endl;
    } else {
        cout << "Expressão não balanceada!" << endl;
    }
    return 0;
}
