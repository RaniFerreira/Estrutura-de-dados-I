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
    int c;

    Fila() {
        primeiro = NULL;
        ultimo = NULL;
    }

    bool vazia() {
        return primeiro == NULL;
    }

    void enfileirar(int valor) {
        c++;
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
        c--;
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
    
    
    bool repetido(int valor){
        
        Node* aux = primeiro;
        
        while(aux != NULL){
            
            if(valor == aux->valor){
                
                return true;
            }
            
            aux = aux->proximo;
            
        }
        
        
        return false;
    }
    
    void passarFrente(Fila& f2){
        
        Node* aux = primeiro;
        
        while(aux != NULL){

            
            if(f2.repetido(aux->valor) == false){
                
                f2.enfileirar(aux->valor);
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

    Fila f,f2;
    int n;
    int vetor[n];
    
    cin >> n;
    
    for(int i=0; i<n;i++){
        cin >> vetor[i];
    }
    
    int m;
    cin >> m;
    int vetor2[m];
    
    for(int i=0; i<m;i++){
        cin >> vetor2[i];
    }
    
    for(int i=0; i<n;i++){
        
        bool fora = false;
        
       for(int j=0; j<m;j++){
            
            if(vetor[i] == vetor2[j]){
                
                fora = true;
                break;
            }
        
        } 
        
        if(!fora){
            
            f.enfileirar(vetor[i]);
        }
        
    }
    
    f.passarFrente(f2);
    f2.imprimir();
   

    return 0;
}