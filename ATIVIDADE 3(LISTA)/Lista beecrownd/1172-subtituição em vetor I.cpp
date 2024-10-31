
#include <iostream>
using namespace std;

struct Node{
    int valor;
    Node* proximo;
    
    Node(){
        valor = 0;
        proximo = NULL;
        
    }
    
    Node(int _valor){
        
        valor = _valor;
        proximo = NULL;
    }
    
};

struct Lista{
    
    Node* primeiro;
    Node* ultimo;
    int contador;
    
    Lista(){
        
        primeiro = NULL;
        ultimo = NULL;
        contador = 0;
        
    }
    
    bool vazia(){
        return primeiro == NULL;
    }
    
    void inserirTras(int valor){
        
        Node* no = new Node(valor);
        contador++;
        
        if(vazia()){
            
            primeiro = no;
            ultimo = no;
            return;
        }
        
       ultimo->proximo = no;
       ultimo = no;
        
        
    }
    
    void imprimir(){
        
        Node* aux = primeiro;
        int n = 0;
        
        while(aux->proximo != NULL){
            
            cout << "X[" << n << "] = " << aux->valor << endl;
            aux = aux->proximo;
            n++;
        }
        cout << "X[" << n << "] = " << aux->valor << endl;
    }
    
};

int main()
{
    Lista l;
    int x;
    
    for(int i=0; i<10; i++){
        
        cin >> x;
        
        if(x <= 0){
            x = 1;
        }
        
        l.inserirTras(x);
        
    }
    
    l.imprimir();

    return 0;
}