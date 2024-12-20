#include<iostream>
#include <cctype>
using namespace std;


struct Node {

    char letra;
    Node* proximo;

    Node() {
        proximo = NULL;
    }

    Node(char _letra) {
        letra = _letra;
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

    void enfileirar(char letra) {
        c++;
        Node* novo = new Node(tolower(letra));
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


    int frente() {
        if (vazia()) {
            cout << "Vazia";
            return -1;
        }
        return primeiro->letra;
    }
    

};

// estrutura da pilha


struct No{
  
    char letra;
    No *proximo;
    
    No(){
        proximo = NULL;
    }
    
    No(int _letra){
        letra = _letra;
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
    
    void inserir(char letra){
        No* novo = new No(tolower(letra));
        
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
        if(topo == NULL) return '0';
        return topo->letra;
    }
    
    
};



int main() {

    string p;

    cin >> p;

    Pilha vogal;
    Fila fila;
    
    int tamanho = p.size();

    for(int i = 0; i < tamanho; i++){
            p[i] = toupper(p[i]);
       

        if(p[i] == 'A' || p[i] == 'E' || p[i] == 'I' || p[i] == 'O' || p[i] == 'U'){
            vogal.inserir(p[i]);
        }
    }
    
    while(!vogal.vazia()){
        
        
        fila.enfileirar(vogal.topoPilha());
        vogal.deletar();
        
    }

    for(int i = 0; i < tamanho; i++){
        if(p[i] == 'A' || p[i] == 'E' || p[i] == 'I' || p[i] == 'O' || p[i] == 'U'){
            char topo = toupper(fila.frente());
            cout << topo;
            fila.desenfileirar();
        }else {
            cout << p[i];
        }
    }

    cout << endl;
    
    
    
    
   

    return 0;
}