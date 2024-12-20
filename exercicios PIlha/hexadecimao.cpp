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
            if(topoPilha->valor >= 10) {
                // Para valores 10 a 15, usamos as letras A a F
                cout << char(topoPilha->valor - 10 + 'A');
            } else {
                cout << topoPilha->valor;
            }
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
        cin >> x;  // Leitura de cada número a ser convertido para hexadecimal

        Pilha p;

        while(x > 0){
            p.inserir(x % 16);  // Divisão por 16 para obter os restos
            x = x / 16;         // Atualiza o número dividindo por 16
        }

        p.imprimir();  // Imprime o número hexadecimal
        p.limpar();    // Limpa a pilha para o próximo número
    }

    return 0;
}
