#include <iostream>
using namespace std;

struct Node {
    int valor;
    Node* proximo;

    Node(int _valor) {
        valor = _valor;
        proximo = nullptr;
    }
};

struct Fila {
    Node* primeiro;
    Node* ultimo;

    Fila() {
        primeiro = nullptr;
        ultimo = nullptr;
    }

    bool vazia() {
        return primeiro == nullptr;
    }

    void enfileirar(int valor) {
        Node* novo = new Node(valor);
        if (vazia()) {
            primeiro = novo;
            ultimo = novo;
        } else {
            ultimo->proximo = novo;
            ultimo = novo;
        }
    }

    void desenfileirar() {
        if (vazia()) {
            return; // Fila já está vazia
        }

        Node* temp = primeiro;
        primeiro = primeiro->proximo;

        // Se o último nó foi removido, atualiza o último
        if (primeiro == nullptr) {
            ultimo = nullptr;
        }

        delete temp; // Libera a memória do nó removido
    }

    int frente() {
        if (vazia()) {
            throw runtime_error("Fila vazia!");
        }
        return primeiro->valor;
    }

    void inserirOrdenado(int valor) {
        Node* novo = new Node(valor);

        // Caso a fila esteja vazia ou o valor seja menor que o primeiro
        if (vazia() || valor < primeiro->valor) {
            novo->proximo = primeiro;
            primeiro = novo;
            if (ultimo == nullptr) {
                ultimo = novo; // Atualiza o último caso seja o único elemento
            }
            return;
        }

        // Caso o valor deva ser inserido no meio ou no final
        Node* atual = primeiro;
        while (atual->proximo != nullptr && atual->proximo->valor < valor) {
            atual = atual->proximo;
        }

        novo->proximo = atual->proximo;
        atual->proximo = novo;

        if (novo->proximo == nullptr) {
            ultimo = novo; // Atualiza o último caso o novo seja o último elemento
        }
    }

    void mostrar() {
        Node* atual = primeiro;
        while (atual != nullptr) {
            cout << atual->valor << " ";
            atual = atual->proximo;
        }
        cout << endl;
    }
};

void juntarFilasOrdenadas(Fila& f1, Fila& f2, Fila& resultado) {
    // Processa os elementos da primeira fila
    while (!f1.vazia()) {
        resultado.inserirOrdenado(f1.frente());
        f1.desenfileirar();
    }

    // Processa os elementos da segunda fila
    while (!f2.vazia()) {
        resultado.inserirOrdenado(f2.frente());
        f2.desenfileirar();
    }
}

int main() {
    Fila f1, f2, resultado;

    // Preenchendo as filas f1 e f2
    f1.enfileirar(10);
    f1.enfileirar(4);
    f1.enfileirar(70);

    f2.enfileirar(25);
    f2.enfileirar(5);
    f2.enfileirar(6);

    // Junta as filas ordenadas
    juntarFilasOrdenadas(f1, f2, resultado);

    // Mostra a fila resultado
    cout << "Fila resultante: ";
    resultado.mostrar();

    return 0;
}
