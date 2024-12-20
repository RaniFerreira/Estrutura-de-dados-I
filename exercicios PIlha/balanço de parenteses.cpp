
#include <iostream>
#include <string>
using namespace std;

struct Node{
  
    char valor;
    Node *proximo;
    
    Node(){
        valor = 0;
        proximo = NULL;
    }
    
    Node(int _valor){
        valor = _valor;
        proximo = NULL;
    }
    
    
};

struct Pilha{
    
    Node* topo;
    
    Pilha(){
        topo = NULL;
    }
    
    bool vazia(){
        return topo == NULL;
    }
    
    void empilhar(int num){
        Node* novo = new Node(num);
        
        if(vazia()){
            
            topo = novo;
            return;
        }
        
        novo->proximo = topo;
        topo = novo;
    }
    
    void desempilhar(){
        if(vazia()){
            
            return;
        }
        if(topo->proximo == NULL){
            delete(topo);
            topo = NULL;
            return;
        }
        
        Node* delet = topo;
        topo = topo->proximo;
        delete(delet);
        
    }
    
    void limparPilha() {
        while (!vazia()) {
            desempilhar();
        }
    }
    
    
    void verificarParenteses(string _equacao){
       
       int tamanho = _equacao.length();
       int cont1 = 0;
       int cont2 = 0;
       
       if(_equacao[0] == ')'){
           cout << "incorrect" << endl;
           return;
       }
       
       for(int i=0; i<tamanho;i++){
           
           if(_equacao[i] == '('){
               
               empilhar(_equacao[i]);
               cont1++;
               
           }
           if(_equacao[i] == ')'){
               
               if(vazia()){
                   cout << "incorrect" << endl;
                   return;
               }
               desempilhar();
               cont2++;
           }
           
       }
       
       if(cont1 > 0 and cont1 == cont2){
               
               cout << "correct" << endl;
           }
           else{
               cout << "incorrect" << endl;
           }
           
        
        
       
       
    }
    
};


int main()
{
    Pilha p;
    
    string equacao;
    
    getline(cin, equacao); // Lê a entrada inteira, incluindo espaços

    while (!equacao.empty()) { // Continua enquanto a string não estiver vazia
        p.verificarParenteses(equacao);
        p.limparPilha();
        getline(cin, equacao); // Lê a próxima entrada
    }
    
    
    
    

    return 0;
}