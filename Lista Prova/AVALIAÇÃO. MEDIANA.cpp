#include <iostream>
#include <iomanip> // para formatar a saída com precisão
using namespace std;

struct No {
    int valor;
    No* prox;

    // Construtor para inicializar o nó com o valor
    No(int n) {
        valor = n;
        prox = NULL;
    }
};

struct Lista {
    No* inicio;        // Ponteiro para o início da lista
    No* fim;           // Ponteiro para o fim da lista
    No* mediana;       // Ponteiro para o nó mediano
    int tamanho;       // Tamanho da lista

    // Construtor que inicializa uma lista vazia
    Lista() {
        inicio = NULL;
        fim = NULL;
        mediana = NULL;
        tamanho = 0;
    }

    // Inserção de um valor ordenado na lista
    void inserirOrdenado(int valor) {
        No* novo = new No(valor);

        if (inicio == NULL) { // Lista vazia
            inicio = fim = mediana = novo;
        } else if (valor < inicio->valor) { // Inserção no início
            novo->prox = inicio;
            inicio = novo;
        } else { // Inserção no meio ou no fim
            No* atual = inicio;
            while (atual->prox != NULL && atual->prox->valor < valor) {
                atual = atual->prox;
            }
            novo->prox = atual->prox;
            atual->prox = novo;
            if (novo->prox == NULL) fim = novo;
        }

        tamanho++;
        atualizarMediana();   // Atualizar o ponteiro da mediana
        exibirListaMediana(); // Exibir lista e mediana
    }

    // Atualiza o ponteiro da mediana conforme o tamanho da lista
    void atualizarMediana() {
        No* atual = inicio;
        int passos = (tamanho - 1) / 2;
        for (int i = 0; i < passos; i++) {
            atual = atual->prox;
        }
        mediana = atual;
    }

    // Exibe a lista e a mediana com precisão de 2 casas decimais
    void exibirListaMediana() {
        No* atual = inicio;
        while (atual != NULL) {
            cout << atual->valor << " ";
            atual = atual->prox;
        }

        // Calcular a mediana
        double mediana_valor;
        if (tamanho % 2 == 1) {
            mediana_valor = mediana->valor;
        } else {
            mediana_valor = (mediana->valor + mediana->prox->valor) / 2.0;
        }

        // Exibir mediana com duas casas decimais
        cout << fixed << setprecision(2) << mediana_valor << endl;
    }
};

int main() {
    int n, x;
    cin >> n;
    Lista lista;

    for (int i = 0; i < n; i++) {
        cin >> x;
        lista.inserirOrdenado(x);
    }

    return 0;
}
