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
        //cout << topoPilha->valor << endl;
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

    cin >> n;

    for(int i = 0; i < n; i++){

        int x;
        cin >> x;

        Pilha p;

        while(x > 0){
            p.inserir(x%2);
            x = x / 2;
        }

        p.imprimir();
        p.limpar();
    }


    return 0;
}
