#include <iostream>
using namespace std;

struct Node{
  
    int valor;
    Node *proximo;
    
    
    Node(int _valor){
        valor = _valor;
        proximo = NULL;
    }
    
    
};

struct Pilha{
    
    Node* topo;
    Node* segundoTopo; // criando um topo para ligar os menores encontrados
    
    Pilha(){
        topo = NULL;
        segundoTopo = NULL;
    }
    

    
    void inserir(int num){
       
        Node* novo = new Node(num);
        
        novo->proximo = topo;
        topo = novo;
        
        if(segundoTopo == NULL || num < segundoTopo->valor){
            Node* novoMenor = new Node(num);
            novoMenor->proximo = segundoTopo;
            segundoTopo = novoMenor;
        }
    }
    
    void deletar() {
        if (topo == NULL) {
            return;
        }

        Node* del = topo;    
        topo = topo->proximo; 

        
        if (del->valor == segundoTopo->valor) {
            Node* auxMin = segundoTopo;   
            segundoTopo = segundoTopo->proximo; 
            delete auxMin;           
        }

        delete del; 
    }
    
    void menorDaPilha() const{
        
        if(segundoTopo == NULL){
            cout << "EMPTY" << endl;
            return;
        }
        
        cout << segundoTopo->valor << endl;
    }
    
    
};


int main()
{
    // Desabilita a sincronização com stdio para tornar a entrada/saída mais rápida
    ios_base::sync_with_stdio(false);
    // Desativa o emparelhamento automático de cin com cout para evitar flushes desnecessários
    cin.tie(NULL);
    
    Pilha p;
    int n;
    
    
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        string op;
        cin >> op;
        
        if(op == "PUSH"){
            int valor;
            cin >> valor;
            p.inserir(valor);
            
        }
        if(op == "POP"){
            
            p.deletar();
        }
        if(op == "MIN"){
            
            p.menorDaPilha();
        }
        
        
    }

    return 0;
}