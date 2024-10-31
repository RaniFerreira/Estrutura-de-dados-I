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
    
    void deletarFrente(){
        
        if(vazia()){
            return;
        }
        if(contador == 1){
            
            delete(primeiro);
            primeiro = NULL;
            ultimo = primeiro;
            contador = 0;
        }
        
        Node* deletar = primeiro;
        primeiro = primeiro-> proximo;
        delete(deletar);
        contador --;
        
    }
    
    void deletarTras(){
        if(vazia()){
            return;
        }
        if(contador == 1){
            delete(primeiro);
            primeiro = NULL;
            ultimo = NULL;
            contador = 0;
            return;
        }
        
        Node* deletar = ultimo;
        Node* aux = primeiro;
        
        while(aux->proximo != ultimo){
            
            aux = aux->proximo;
        }
        
        ultimo = aux;
        ultimo->proximo = NULL;
        delete(deletar);
        contador--;
        
    }
    
    void soma(List &lista2, List &lista3) {
        Node* auxl1 = primeiro;
        Node* auxl2 = lista2.primeiro;

        while (auxl1 != NULL && auxl2 != NULL) {
            int soma = 0;
            if (auxl1->valor + auxl2->valor >= 10) {
                auxl1->proximo->valor += 1;
                soma = (auxl1->valor + auxl2->valor) - 10;
                
            }else{
                soma = auxl1->valor + auxl2->valor;
              
            }
            
            lista3.inserirTras(soma);
            
            auxl1 = auxl1->proximo;
            auxl2 = auxl2->proximo;

        }
        
        

    }
    
    
    
    
    
    void imprimir(){
        
        
        Node* aux = primeiro;
        
        while(aux != NULL){
            
            cout << "->" << aux->valor;
            aux = aux->proximo;
        }
        
    }
    
    
};




int main()
{
    List lista1;
    List lista2;
    List lista3;
    
    int x, n;
    
    cin >> n;
    
    for(int i=0; i < n ; i++){
        
        cin >> x;
        lista1.inserirFrente(x);
    }
    
    for(int i=0; i < n ; i++){
        
        cin >> x;
        lista2.inserirFrente(x);
    }
    
    
    
    lista1.soma(lista2,lista3);
    lista3.imprimir();
  
 

    return 0;
}