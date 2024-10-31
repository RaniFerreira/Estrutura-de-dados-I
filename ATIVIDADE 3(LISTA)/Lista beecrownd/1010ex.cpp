#include <iostream>
#include <iomanip>
using namespace std;

struct Node{
    
    double valor;
    Node* proximo;
    
    Node(){
        
        valor = 0;
        proximo = NULL;
    }
    
    Node(double _valor){
        
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
    
    
    void inserirFrente(double valor){
        
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
    
    void inserirTras(double valor){
        
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
    
    void saldoConta() {
        Node* aux = primeiro;
        double saldo = primeiro->valor;
        
        if(saldo < 0) {
            cout << "invalido" << endl;
            return;
        }
        
        while(aux->proximo != NULL) {
            
            if(aux->proximo->valor + saldo < 0) {
                cout << "invalido" << endl;
                return;
            }
            
           
            saldo = saldo +  aux->proximo->valor;
            aux = aux->proximo; 
        }
        
        
        cout << fixed << setprecision(2) << saldo << endl;
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
    List l;
    
    double x;
    int n;
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        
        cin >> x;
        l.inserirTras(x);
    }
    
    l.saldoConta();
    
    
    
    
    
    
  
 

    return 0;
}