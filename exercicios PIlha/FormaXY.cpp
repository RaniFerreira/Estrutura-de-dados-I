#include <iostream>
using namespace std;

struct Node {
    char letra;
    Node* proximo;
    Node* anterior;

    Node(char _letra) {
        letra = _letra;
        proximo = NULL;
        anterior = NULL;
    }
};

struct Pilha {
    Node* topo;
    Node* razo;
    int cont = 0;

    Pilha() {
        
        topo = NULL;
        razo = NULL;
    }

    bool vazia() {
        return topo == NULL;
    }

    void inserir(char letra) {
        cont++;
        Node* novo = new Node(letra);
        if (vazia()) {
            topo = novo;
            razo = novo;
            return;
        }
        topo->anterior = novo;
        novo->proximo = topo;
        topo = novo;
    }

    void deletar() {
        if (vazia()) {
            return;
        }
        Node* delet = topo;
        topo = topo->proximo;
        delete delet;
    }
    
    void formaXY(Pilha& y){
       
       Node* auxX = topo;
       Node* auxY = y.razo;
       
       int diferente = 0;
       
       if(cont != y.cont){
           
           cout << "Não é da forma XY" << endl;
           return;
       }
       
       while(auxX != NULL && auxY != NULL){
           
           if(auxX->letra != auxY->letra){
               diferente ++;
           }
           
           auxY = auxY->anterior;
           auxX = auxX->proximo;
       }
       
       if(diferente >= 1){
           cout << "Não é da forma XY" << endl;
       }
       else{
           cout << "É da forma XY" << endl;
       }
        
    }
};




int main() {
    
    Pilha x,y;
    
    string palavrax;
    
    cin >> palavrax;
    int tamanho = palavrax.size();
    
    for(int i=0;i<tamanho;i++){
        
        x.inserir(palavrax[i]);
    }
    string palavray;
    cin >> palavray;
    int tamanho2 = palavray.size();
    
    for(int i=0;i<tamanho2;i++){
        
        y.inserir(palavray[i]);
    }
    
    x.formaXY(y);
    
    

    return 0;
}
