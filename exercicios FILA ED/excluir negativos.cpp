/*Dada uma fila de inteiros, escreva um programa que exclua todos os n´umeros negativos
 sem alterar a posic ¸˜ ao dos outros elementos da fila.*/
 
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
    
    void filaPositivos(Fila& positivos){
        
        Node* aux = primeiro;
        
        while(aux != NULL){
            
            if(aux->valor >= 0){
                
                positivos.enfileirar(aux->valor);
            }
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

    Fila fila, positivos;
    
    fila.enfileirar(2);
    fila.enfileirar(-2);
    fila.enfileirar(-10);
    fila.enfileirar(20);
    fila.enfileirar(0);
    
    fila.filaPositivos(positivos);
    
    while(!positivos.vazia()){
        
        cout << positivos.frente() << " ";
        positivos.desenfileirar();
    }
    

    return 0;
}