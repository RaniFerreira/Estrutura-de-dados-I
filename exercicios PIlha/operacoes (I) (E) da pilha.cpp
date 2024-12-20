

/* 3. Suponha que uma pilha possua 4 valores na seguinte ordem: 1, 2, 3 e 4. Qual seria
 a sequˆ encia correta de operac¸˜ oes de inserc ¸˜ ao (I) e eliminac ¸˜ ao (E) para se obter os
 registros na ordem 2 4 3 1?*/
#include <iostream>
using namespace std;

struct Node{
  
    int valor;
    Node *proximo;
    
    Node(){
        valor = 0;
        proximo = NULL;
    }
    
    Node(int _valor){
        valor = _valor;
        proximo = NULL;
    }
    
    
};

struct Pilha{
    
    Node* topo;
    
    Pilha(){
        topo = NULL;
    }
    
    bool vazia(){
        return topo == NULL;
    }
    
    void inserir(int num){
        Node* novo = new Node(num);
        
        if(vazia()){
            
            topo = novo;
            return;
        }
        
        novo->proximo = topo;
        topo = novo;
    }
    
    void deletar(){
        if(vazia()){
            
            return;
        }
        if(topo->proximo == NULL){
            delete(topo);
            topo = NULL;
            return;
        }
        
        Node* delet = topo;
        topo = topo->proximo;
        delete(delet);
        
    }
    
    int topoPilha(){
        if(vazia()){
            cout << "Pilha vazia !";
            return -1;
        }
        
        return topo->valor;
    }
    
};


int main()
{
    Pilha pilha;
    
    
    
    pilha.inserir(1);
    pilha.inserir(2);
    pilha.inserir(3);
    pilha.inserir(4);
    
    pilha.deletar();
    pilha.deletar();
    pilha.deletar();
    
    pilha.inserir(3);
    pilha.inserir(4);
    pilha.inserir(2);
   

    
    while(!pilha.vazia()){
        cout << pilha.topoPilha() << " ";
        pilha.deletar();
    }

    return 0;
}