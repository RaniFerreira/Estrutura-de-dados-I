#include <iostream>
using namespace std;
#define N 5


struct Pilha{
  
    int vetor[N];
    int topo;
    
    Pilha(){
        topo = 0;
        
    }
    
    bool vazia(){
        return topo == 0;
    }
    
    bool cheia(){
        return topo >= N;
    }
    
    void inserir(int valor){
        if(cheia()){
            cout << "Está Cheia";
            return;
        }
        vetor[topo++] = valor;
    }
    
    void deletar(){
        if(vazia()){
            cout << "Está vazia";
            return;
        }
        topo--;
    }
    
    int topoPilha(){
        if(vazia()){
            cout << "Está vazia";
            return -1;
        }
        
        return vetor[topo - 1];
    }
    

  
};

int main(){
    
    Pilha pilha1;
    
    pilha1.inserir(1);
    pilha1.inserir(2);
    pilha1.inserir(3);
    
    
    while(!pilha1.vazia()){
        cout << pilha1.topoPilha() << endl;
        pilha1.deletar();
    }
    
    
    return 0;
    
    
    
    
}