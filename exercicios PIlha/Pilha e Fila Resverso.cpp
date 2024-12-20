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

// estrutura da pilha


struct No{
  
    int valor;
    No *proximo;
    
    No(){
        valor = 0;
        proximo = NULL;
    }
    
    No(int _valor){
        valor = _valor;
        proximo = NULL;
    }
    
    
};

struct Pilha{
    
    No* topo;
    
    Pilha(){
        topo = NULL;
    }
    
    bool vazia(){
        return topo == NULL;
    }
    
    void inserir(int num){
        No* novo = new No(num);
        
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
        
        No* delet = topo;
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


int main() {

    Pilha pilha;
    Fila fila;
    
    int n;
    cin >> n;
    
    for(int i =0; i<n;i++){
        
        int valor;
        cin >> valor;
        fila.enfileirar(valor);
        pilha.inserir(valor);
    }
    
    while(!fila.vazia()){
        
        cout << fila.frente() << " ";
        fila.desenfileirar();
    }
    
    cout << endl;
    while(!pilha.vazia()){
        
        cout << pilha.topoPilha() << " ";
        pilha.deletar();
    }
    
   

    return 0;
}