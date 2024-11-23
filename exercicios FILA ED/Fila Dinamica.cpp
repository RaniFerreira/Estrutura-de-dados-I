#include<iostream>
using namespace std;


struct Node {

    int valor;
    Node* proximo;

    Node() {
        proximo = NULL;
    }

    Node(int _valor) {
        valor = _valor;
        proximo = NULL;
    }

};

struct Fila {

    Node* primeiro;
    Node* ultimo;

    Fila() {
        primeiro = NULL;
        ultimo = NULL;
    }

    bool vazia() {
        return primeiro == NULL;
    }

    void enfileirar(int valor) {
        Node* novo = new Node(valor);
        if (vazia()) {
            primeiro = novo;
            ultimo = novo;
            return;
        }
        ultimo->proximo = novo;
        ultimo = novo;
    }

    void desenfileirar() {
        if (vazia()) return;
        if (primeiro == ultimo) {
            delete(primeiro);
            primeiro = NULL;
            ultimo = NULL;
            return;
        }
        Node* del = primeiro;
        primeiro = primeiro->proximo;
        delete(del);
    }

    int frente() {
        if (vazia()) {
            cout << "Vazia";
            return -1;
        }
        return primeiro->valor;
    }
    

};

int main() {

    

    return 0;
}