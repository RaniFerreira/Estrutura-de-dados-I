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
    
    //colocar o tamanho atual da lista como ultimo no
    
    void tamanhoAtualNoFinalLista(){
    
        int atual = contador;
        
        inserirTras(atual);

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
    List lista;
    
    lista.inserirFrente(5);
    lista.inserirFrente(4);
    lista.inserirFrente(3);
    lista.inserirFrente(2);
    lista.inserirFrente(1);
    lista.inserirFrente(5);
    lista.inserirFrente(4);
    lista.inserirFrente(3);
    lista.inserirFrente(2);
    lista.inserirFrente(1);
    
    lista.imprimir();
    lista.tamanhoAtualNoFinalLista();
    cout << endl;
    
    lista.imprimir();
    
    
    
    
    
  
 

    return 0;
}