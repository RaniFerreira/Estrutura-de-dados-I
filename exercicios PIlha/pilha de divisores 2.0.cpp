
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
    
    int contarDivisivel(int n){
        
        int a;
        int cont = 0;
        for(int i=0; i<n; i++){
           if(vazia()){
               cin >> a;
               inserir(a);
           }
           else{
               cin >> a;
               if(a % topoPilha() == 0){
                   inserir(a);
                   cont++;
               }
           }
            
        }
        
        return cont;
    }
    
};


int main()
{
    Pilha pilha;
    int n;
    
    cin >> n;
    
    cout << pilha.contarDivisivel(n);
    
    
    

    return 0;
}