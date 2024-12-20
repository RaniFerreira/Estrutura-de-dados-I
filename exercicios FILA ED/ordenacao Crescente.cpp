#include<iostream>
using namespace std;


struct Node {

    int valor;
    Node* proximo;

    Node() {
        proximo = NULL;
    }

    Node(int _valor) {
        valor = _valor;
        proximo = NULL;
    }

};

struct Fila {

    Node* primeiro;
    Node* ultimo;

    Fila() {
        primeiro = NULL;
        ultimo = NULL;
    }

    bool vazia() {
        return primeiro == NULL;
    }

    void enfileirar(int valor) {
        Node* novo = new Node(valor);
        if (vazia()) {
            primeiro = novo;
            ultimo = novo;
            return;
        }
        ultimo->proximo = novo;
        ultimo = novo;
    }

    void desenfileirar() {
        if (vazia()) return;
        if (primeiro == ultimo) {
            delete(primeiro);
            primeiro = NULL;
            ultimo = NULL;
            return;
        }
        Node* del = primeiro;
        primeiro = primeiro->proximo;
        delete(del);
    }

    void ordenarCrescente() {
    if (vazia() || primeiro->proximo == NULL) return; // Se a lista está vazia ou tem só um elemento, já está ordenada.

    Node* ordenar = NULL; // Ponteiro para a nova lista ordenada.

    while (primeiro != NULL) {
        // Remove o primeiro nó da lista original.
        Node* atual = primeiro;
        primeiro = primeiro->proximo;

        // Insere o nó na posição correta na lista ordenada.
        if (ordenar == NULL || atual->valor < ordenar->valor) {
            // Insere no início da lista ordenada.
            atual->proximo = ordenar;
            ordenar = atual;
        } else {
            // Encontra a posição correta para inserir.
            Node* aux = ordenar;
            while (aux->proximo != NULL && aux->proximo->valor < atual->valor) {
                aux = aux->proximo;
            }
            // Insere o nó na posição correta.
            atual->proximo = aux->proximo;
            aux->proximo = atual;
        }
    }

    // Atualiza os ponteiros de início e fim para a lista ordenada.
    primeiro = ordenar;
    ultimo = primeiro;
    while (ultimo->proximo != NULL) {
        ultimo = ultimo->proximo;
    }
}

    
    void imprimir(){
        
        Node* aux = primeiro;
        
        while (aux != NULL){
            
            cout << aux->valor << " ";
            aux = aux->proximo;
        }
    }

};

int main() {
    
    Fila f;
    
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        
        int valor;
        cin >> valor;
        f.enfileirar(valor);
    }
    
    
    f.ordenarCrescente();
    f.imprimir();

    

    return 0;
}