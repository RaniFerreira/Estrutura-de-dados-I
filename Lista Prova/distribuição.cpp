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

struct List{
    
    Node* primeiro;
    Node* ultimo;
    int contador;
    
    
    List(){
        
        primeiro = NULL;
        ultimo = NULL;
        contador = 0;
    }
    
    bool vazia(){
        
        return primeiro == NULL;
    }
    
    
    void inserirFrente(int valor){
        
        Node* no = new Node(valor);
        contador++;
        
        if(vazia()){
            
            primeiro = no;
            ultimo = no;
            return;
        }
        
        no->proximo = primeiro;
        primeiro = no;
    }
    
    int tamanhoLista(){
        
        return contador;
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
    
    
    
    
    
    
    void imprimir(List &l2){
        
        
        Node* aux1 = primeiro;
        Node* aux2 = l2.primeiro;
        
        while(aux1 != NULL and aux2 != NULL){
            
            cout << aux1->valor << " ";
            cout << aux2->valor  <<" ";
            
            aux1 = aux1->proximo;
            aux2 = aux2->proximo;
        }
        
    }
    
    
};




int main()
{
    List l1, l2;
    
   int n,a,b;
    
    cin >> n;
    
    
    for(int i = 0; i < n; i++){
        
        cin >> a;
        l1.inserirTras(a);
    }
    
    for(int i = 0; i < n; i++){
        
        cin >> a;
        l2.inserirTras(a);
    }
    
    l1.imprimir(l2);
    
   
    
  
 

    return 0;
}