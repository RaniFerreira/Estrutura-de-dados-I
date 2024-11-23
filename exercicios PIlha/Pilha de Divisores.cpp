
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
    int n, cont = 0;
    Pilha p;
    
    cin >> n;
    
    int valor;
    
    for (int i = 0; i < n; i++) {
        cin >> valor; // Lê o valor antes de qualquer processamento
        
        if (p.vazia()) {
            // Se a pilha estiver vazia, insere diretamente o primeiro valor
            p.inserir(valor);
        } else {
            // Caso contrário, verifica a condição antes de inserir
            if (valor % p.topoPilha() == 0) {
                p.inserir(valor);
                cont++;
            }
        }
    }
    
    cout << cont << endl;

    return 0;
}