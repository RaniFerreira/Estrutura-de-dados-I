#include<iostream>
using namespace std;


struct Node {

    int valor;
    Node* proximo;

    Node() {
        proximo = NULL;
    }

    Node(int _valor) {
        valor = _valor;
        proximo = NULL;
    }

};

struct Fila {

    Node* primeiro;
    Node* ultimo;

    Fila() {
        primeiro = NULL;
        ultimo = NULL;
    }

    bool vazia() {
        return primeiro == NULL;
    }

    void enfileirar(int valor) {
        Node* novo = new Node(valor);
        if (vazia()) {
            primeiro = novo;
            ultimo = novo;
            return;
        }
        ultimo->proximo = novo;
        ultimo = novo;
    }

    void desenfileirar() {
        if (vazia()) return;
        if (primeiro == ultimo) {
            delete(primeiro);
            primeiro = NULL;
            ultimo = NULL;
            return;
        }
        Node* del = primeiro;
        primeiro = primeiro->proximo;
        delete(del);
    }
    
    void passarFrente(int v){
        
        Node* aux = primeiro;
        int atual = aux->valor;
        
        while(aux != NULL){
            
            if(v == aux->valor){
                
                if(aux->valor == primeiro->valor){
                    
                    desenfileirar();
                }
                else{
                    
                    
                }
                
            }
            
                
                
            aux = aux->proximo;
            
        }
        
        
    }
    
    void imprimir(){
        
        Node* aux = primeiro;
        
        while(aux != NULL){
            
            
            cout << aux->valor << " ";
            
            aux = aux->proximo;
        }
    }

    int frente() {
        if (vazia()) {
            cout << "Vazia";
            return -1;
        }
        return primeiro->valor;
    }
    

};

int main() {

    Fila f;
    int n;
    
    cin >> n;
    
    for(int i=0; i<n;i++){
        
        int valor;
        
        cin >> valor;
        f.enfileirar(valor);
    }
    
    int m;
    cin >> m;
    
    for(int i=0; i<m;i++){
        
        int valor2;
        cin >> valor2;
        f.passarFrente(valor2);
        
    }
    
    f.imprimir();
    

    return 0;
}