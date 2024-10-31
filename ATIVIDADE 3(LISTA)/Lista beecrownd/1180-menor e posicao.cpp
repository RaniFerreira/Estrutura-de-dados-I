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
    
    void imprimirMenorValorEPosicao(){
        
        Node* aux = primeiro;
        Node* menor = primeiro;
        int posicao = 0;
        int posicaoM = 0;
        
        while(aux != NULL){
            
            if(aux->valor < menor->valor){
                
                menor = aux;
                posicaoM = posicao;
            }
            aux = aux->proximo;
            posicao++;
        }
        
        cout << "Menor valor: " << menor->valor << endl;
        cout << "Posicao: " << posicaoM << endl;
    }
    
    
};

int main()
{
    Lista l;
    
    int n, valor;
    cin >> n;
    
    for(int i=0; i<n;i++){
        
        cin >> valor;
        
        l.inserirTras(valor);
    }
    
    l.imprimirMenorValorEPosicao();
    
    return 0;
}