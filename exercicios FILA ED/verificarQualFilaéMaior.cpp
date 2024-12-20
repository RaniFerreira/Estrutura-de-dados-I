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
    int contador = 0;

    Fila() {
        primeiro = NULL;
        ultimo = NULL;
    }

    bool vazia() {
        return primeiro == NULL;
    }

    void enfileirar(int valor) {
        contador++;
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
        contador--;
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
        return primeiro->valor;
    }
    

};

void verificarFilaMaior(Fila& filaA, Fila& filaB){
        
        // o ponto é ultilizado para acessar o contador de cada fila
        if(filaA.contador > filaB.contador){ 
            
            cout << "FilaA tem mais elementos" << endl;
        }
        else if(filaA.contador < filaB.contador){
            
            cout << "FilaB tem mais elementos" << endl;
        }
        else{
            cout << "As duas filas contem a mesma quantidade de elementos" << endl;
        }
        
        
    }

int main() {
    
    Fila filaA, filaB;
    
    
   
    filaA.enfileirar(5);
    filaA.enfileirar(5);
    filaA.enfileirar(5);
    filaA.enfileirar(5);
    filaA.desenfileirar();
    filaA.desenfileirar();
    
    
    filaB.enfileirar(5);
    filaB.enfileirar(5);
    filaB.enfileirar(5);
    filaB.enfileirar(5);
    filaB.enfileirar(5);
    filaB.desenfileirar();
    filaB.desenfileirar();
    filaB.desenfileirar();
    
    
    
    
    verificarFilaMaior(filaA,filaB);
    
    
    

    

    return 0;
}