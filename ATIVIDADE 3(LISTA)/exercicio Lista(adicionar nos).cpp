
#include <iostream>
using namespace std;


struct Node{
    
    int valor; //armazena o valor do nó
    Node* proximo; // ponteiro que armazena o endereço para o proximo no
    
    //construtor padrão para inicializar as minhas variaveis valor e proximo
    Node(){
        valor = 0;
        proximo = NULL;
        
    }
    //construtor sobrecarregado que recebe o _valor(_ = utilizado para diferenciar as 
    // variavei e não dar confllito)
    Node(int _valor){
        valor = _valor;
        proximo = NULL;
    
    }
    
};

struct List{
    
    Node* primeiro; //ponteiro para o primeiro nó da lista(guarda o endereço do novo nó)
    Node* ultimo;  //ponteiro para o ultimo nó da lista(guarda o endereço do nó anterior)
    
    List(){
        primeiro = NULL;
        ultimo = NULL;
    }
    
    //verifica se a lista está vazia
    bool empty(){
        return primeiro == NULL;
    }
    
    //inserir um nó no inicio da lista
    void pushFront(int valor){
        Node *n = new Node(valor);
        if(empty()){
            //se a lista estiver vazia o primeiro e ultimo no contem o mesmo endereço
            primeiro = n;
            ultimo = n;
            return;
        }
        n->proximo = primeiro; //o proximo no vai ser o antigo do primeiro
        primeiro = n; // o novo no se torna o primeiro
    }
    
    void pushBack(int valor){
        Node *n = new Node(valor);
            if(empty()){
            //se a lista estiver vazia o primeiro e ultimo no contem o mesmo endereço
            primeiro = n;
            ultimo = n;
            return;
        }
        ultimo->proximo = n; // o nó anterior aponta para o novo nó
        ultimo = n; // o novo no se torna o ultimo
        
    }
    
    //imprimir os valores da lista
    void imprimir(){
        Node *aux = primeiro; // aux= variavel auxiliar para percorrer a lista
        while(aux != NULL){
            cout << "->" << aux->valor; // imprime o valor do nó atual
            aux = aux->proximo;
        }
    }
    
    
};

int main(){
    
    List lista;
    
    lista.pushFront(5);
    lista.pushBack(8);
    lista.pushFront(1);
    lista.pushFront(5);
    lista.pushBack(8);
    lista.imprimir();
    

    return 0;
}
