#include <iostream>
#include <cmath>

using namespace std;

struct No {
    int valor;
    No* prox;

    No() {
        valor = 0;
        prox = NULL;
    }

    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }
};

struct Pilha {
    No* topo;
    int n;

    Pilha() {
        topo = NULL;
        n = 0;
    }

    void inserir(int valor) {
        No* novo = new No(valor);
        if(topo == NULL){
            topo = novo;
        }else {
            novo->prox = topo;
            topo = novo;
        }
        n++;
    }

    void remover(){
        if(n == 0) return;
        if(n == 1){
            delete(topo);
            topo = NULL;
            n = 0;
            return;
        }
        No* aux = topo;
        topo = topo->prox;
        delete(aux);
        n--;
    }

    int topoPilha(){
        if(topo == NULL) return 0;
        return topo->valor;
    }

    void imprimir() {
        No* topoPilha = topo;

        while(topoPilha != NULL) {
            cout << topoPilha->valor;
            topoPilha = topoPilha->prox;
        }
        cout << endl;
    }

    void limpar() {
        while (topo != NULL) {
            remover();
        }
    }

};

int main(){
    int n;

    cin >> n;  // Leitura da quantidade de números que serão convertidos

    for(int i = 0; i < n; i++){

        int x;
        cin >> x;  // Leitura de cada número a ser convertido para octal

        Pilha p;

        while(x > 0){
            p.inserir(x % 8);  // Divisão por 8 para obter os restos
            x = x / 8;         // Atualiza o número dividindo por 8
        }

        p.imprimir();  // Imprime o número octal
        p.limpar();    // Limpa a pilha para o próximo número
    }

    return 0;
}
