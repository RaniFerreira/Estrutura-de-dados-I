#include <iostream>
using namespace std;

struct No {
    int valor;
    No* proximo;

    No(int n) {
        valor = n;
        proximo = NULL;
    }
};

struct Lista {
    No* primeiro;
    No* ultimo;
    int contador;

    Lista() {
        primeiro = NULL;
        ultimo = NULL;
        contador = 0;
    }

    bool vazia() {
        return primeiro == NULL;
    }

    void inserirFinal(int n) {
        No* novo = new No(n);
        if (vazia()) {
            primeiro = novo;
            ultimo = novo;
        } else {
            ultimo->proximo = novo;
            ultimo = novo;
        }
        contador++;
    }

    void imprimir() {
        No* aux = primeiro;

        while (aux != NULL) {
            cout << aux->valor << " ";
            aux = aux->proximo;
        }
        cout << endl;
    }

    void ordenarCrescente() {
        if (vazia()) return;

        bool trocado;
        do {
            trocado = false;
            No* aux = primeiro;

            while (aux->proximo != NULL) {
                if (aux->valor > aux->proximo->valor) {
                    // Troca os valores
                    swap(aux->valor, aux->proximo->valor);
                    trocado = true;
                }
                aux = aux->proximo;
            }
        } while (trocado);
    }
};

int main() {
    Lista lista;
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        lista.inserirFinal(x);
    }

    for (int j = 0; j < m; j++) {
        int v;
        cin >> v;
        lista.inserirFinal(v);
    }

    lista.ordenarCrescente();  // Chama a função para ordenar em ordem crescente
    lista.imprimir();           // Imprime a lista ordenada

    return 0;
}
