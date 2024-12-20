#include <iostream>
using namespace std;

struct Node {
    int valor;
    Node* proximo;

    Node() {
        valor = 0;
        proximo = NULL;
    }

    Node(int _valor) {
        valor = _valor;
        proximo = NULL;
    }
};

struct Pilha {
    Node* topo;

    Pilha() {
        topo = NULL;
    }

    bool vazia() {
        return topo == NULL;
    }

    void inserir(int num) {
        Node* novo = new Node(num);
        if (vazia()) {
            topo = novo;
            return;
        }
        novo->proximo = topo;
        topo = novo;
    }

    void deletar() {
        if (vazia()) {
            return;
        }
        Node* delet = topo;
        topo = topo->proximo;
        delete delet;
    }
};

// Função para validar a sequência de operações
void validarSequencia(int n) {
    Pilha pilha;
    int contInserir = 0;  // Contador de inserções
    int contDeletar = 0;  // Contador de deleções

    for (int i = 0; i < n; i++) {
        string operacao;
        cin >> operacao;

        if (operacao == "inserir") {
            pilha.inserir(1);
            contInserir++;
        } else if (operacao == "remover") {
            if (pilha.vazia()) {
                cout << "Inválida" << endl;  // Tentativa de remover de pilha vazia
                return;
            }
            pilha.deletar();
            contDeletar++;
        }
    }

    // Verifica se a sequência é válida
    if (contInserir >= contDeletar) {
        cout << "Válida" << endl;
    } else {
        cout << "Inválida" << endl;
    }
}

int main() {
    int n;  // Número de operações
    cin >> n;

    validarSequencia(n);

    return 0;
}
