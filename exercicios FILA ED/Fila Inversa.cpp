#include<iostream>
using namespace std;


struct Node {

    int valor;
    Node* proximo;
    Node* anterior;

    Node() {
        proximo = NULL;
        anterior = NULL;
    }

    Node(int _valor) {
        valor = _valor;
        proximo = NULL;
        anterior = NULL;
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
        novo->anterior = ultimo;
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
        primeiro->anterior = NULL;
        delete(del);
    }
    
    void desenfileirarTras() {
        if (vazia()) return;
        if (primeiro == ultimo) {
            delete(primeiro);
            primeiro = NULL;
            ultimo = NULL;
            return;
        }
        Node* del = ultimo;
        ultimo = ultimo->anterior;
        ultimo->proximo = NULL;
        delete(del);
    }
    
    void removerEmOrdem(){
        
        if(vazia()){
            cout << "A fila esta vazia";
            return;
        }
        
        
        
        while(!vazia()){
            
            cout << primeiro->valor << " ";
            
            desenfileirar();
        }
        
        
    }
    
    void removerOrdemInversa(){
        
        if(vazia()){
            cout << "A fila esta vazia";
            return;
        }
        
        
        
        while(!vazia()){
            
            cout << ultimo->valor << " ";
            
            desenfileirarTras();
        }
        
        
    }
    
    void menu(){
        
        int op;
        
        cout << "Escolha de que forma os números serão retirados da fila: " << endl;
        cout << "1 - Ordem de chegada." << endl;
        cout << "2 - De tras pra frente" << endl;
        
        cin >> op;
        
        switch(op){
            case 1 :
                cout << "Quem chegou primeiro, sai primeiro" << endl;
                removerEmOrdem();
                break;
            case 2 :
                cout << "os ultimos serão os primeiro" << endl;
                removerOrdemInversa();
                break;
        }
    }
    

};

int main() {

    Fila f;
    int n;
    
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        int valor;
        cin >> valor;
        f.enfileirar(valor);
    }
    
    f.menu();

    return 0;
}