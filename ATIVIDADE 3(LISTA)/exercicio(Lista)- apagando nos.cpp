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
    int c;
    
    List(){
        primeiro = NULL;
        ultimo = NULL;
        c = 0;
    }
    
    //verifica se a lista está vazia
    bool empty(){
        return primeiro == NULL;
    }
    
    //inserir um nó no inicio da lista
    void pushFront(int valor){
        Node *n = new Node(valor);
        c++;
        
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
        c++;
        
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
    
    int size(){
        return c;
    }
    
    //Deletar um nó do inicio da lista
    void popFront(){
        if(empty()) return;
        if(c == 1){
            delete(primeiro);
            primeiro = NULL;
            ultimo = primeiro;
            c =0;
        }
        Node* toDel = primeiro;
        primeiro = primeiro->proximo;
        delete(toDel);
        c--;
    }
    
    //deletar um nó no final da lista
    void popBack() {
    if (empty()) return;
        if (c == 1) {
            delete(primeiro);
            primeiro = NULL;
            ultimo = NULL;
            c = 0;
            return;
        }
        Node* toDel = ultimo;
        Node* aux = primeiro;
        while (aux->proximo != ultimo) {
            aux = aux->proximo;
        }
        ultimo = aux;
        ultimo->proximo = NULL;
        delete(toDel);
        c--;
    }
    
    //Inserir no meio da lista
    
     void insert(int valor, int pos) { //O(n)
        if (pos <= 0) {
            pushFront(valor);
            return;
        }
        if (pos >= c) {
            pushBack(valor);
            return;
        }
        Node* aux = primeiro;
        for (int i = 0; i < pos; i++, aux = aux->proximo);
        Node* n = new Node(valor);
        n->proximo = aux->proximo;
        aux->proximo = n;
        c++;
    }
    
    
    // remover do meio da lista
    
    void remove(int valor) { // O(n)
        if (empty()) return;

        Node *aux = primeiro;
        Node *prev = NULL;
        for (int i = 0; i < c; i++) {
            if (aux->valor == valor) {
                if (prev == NULL) {
                    popFront();
                } else {
                    prev->proximo = aux->proximo;
                    delete(aux);
                    c--;
                    aux = prev;
                }
            }
            prev = aux;
            aux = aux->proximo;
        }
    }
    
    //remover elemento por posição
    
    void removeByPos(int pos) { // O(n)
        if (pos <= 0) {
            popFront();
            return;
        }
        if (pos >= c) {
            popBack();
            return;
        }
        Node* aux = primeiro;
        for (int i = 0; i < pos - 1; i++, aux = aux->proximo);
        Node* toDel = aux->proximo;
        aux->proximo = toDel->proximo;
        delete(toDel);
        c--;
    }
    
    
};

int main(){
    
    List l;

    l.pushFront(10);
    l.pushFront(3);
    l.pushBack(5);

   
    l.insert(8,1);
    l.remove(5);
    l.removeByPos(2);

    l.imprimir();
    

    return 0;
}