
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
        if(topo == NULL) return 0;
        return topo->valor;
    }
    
    void removerTopo() {
        while (topo != NULL) {
            deletar();
        }
    }

    void imprimir() {
        
        Node* topoPilha = topo;

        while(topoPilha != NULL) {
            
            cout << topoPilha->valor;
            topoPilha = topoPilha->proximo;
        }
        
        cout << endl;
    }

    
    
};


int main()
{
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        
        int valor;
        cin >> valor;
        
        Pilha pilha;
        
        while(valor > 0){
            
            pilha.inserir(valor % 2);
            valor = valor / 2;
        }
        
        pilha.imprimir();
        pilha.removerTopo();
    }

    return 0;
}