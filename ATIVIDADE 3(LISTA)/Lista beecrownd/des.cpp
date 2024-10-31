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

    void ordenarDecrescente() {
        if (vazia()) return;

        No* aux;
        bool trocado = true;

        while (trocado) {
            trocado = false;
            aux = primeiro;

            while (aux->proximo != NULL) {
                if (aux->valor < aux->proximo->valor) {
                    // Troca os valores
                    int temp = aux->valor;
                    aux->valor = aux->proximo->valor;
                    aux->proximo->valor = temp;
                    trocado = true;
                }
                aux = aux->proximo;
            }
        }
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

    lista.ordenarDecrescente();
    lista.imprimir();

    return 0;
}
