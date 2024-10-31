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

    int soma() {
        int total = 0;
        No* aux = primeiro;
        while (aux != NULL) {
            total += aux->valor;
            aux = aux->proximo;
        }
        return total;
    }
};

int main() {
    Lista lista1, lista2;
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        lista1.inserirFinal(x);
    }

    for (int j = 0; j < m; j++) {
        int v;
        cin >> v;
        lista2.inserirFinal(v);
    }

    int somaTotal = lista1.soma() + lista2.soma();
    double media = static_cast<double>(somaTotal) / (n + m);
    cout << "Media: " << media << endl;

    return 0;
}
