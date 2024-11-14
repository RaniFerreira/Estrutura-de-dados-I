#include<stdio.h>

struct Node {
    int valor;
    Node* proximo;
    Node* anterior;

    Node() {
        valor = 0;
        proximo = NULL;
        anterior = NULL;
    }

    Node(int _valor) {
        valor = _valor;
        proximo = NULL;
        anterior = NULL;
    }

};

struct ListaDupla {

    Node *primeiro;
    Node *ultimo;
    int contador;

    ListaDupla() {
        primeiro = NULL;
        ultimo = NULL;
        contador = 0;
    }

    bool empty() { //O(1)
        return primeiro == NULL;
    }

    void pushBack(int v) { //O(1)
        Node *no = new Node(v);
        contador++;
        if (empty()) {
            primeiro = no;
            ultimo = no;
            return;
        }
        no->anterior = ultimo;
        ultimo->proximo= no;
        ultimo = no;
    }

    void pushFront(int v) { //O(1)
        Node *no = new Node(v);
        contador++;
        if (empty()) {
            primeiro = no;
            ultimo = no;
            return;
        }
        primeiro->anterior = no;
        no->proximo = primeiro;
        primeiro = no;
    }

    void imprimir() { //O(n)
        Node* aux = primeiro;
        while (aux != NULL) {
            printf("%d -> ", aux->valor);
            aux = aux->proximo;
        }
        printf("\n");
    }

    void printBackward() { //O(n)
        Node* aux = ultimo;
        while (aux != NULL) {
            printf("%d -> ", aux->valor);
            aux = aux->anterior;
        }
        printf("\n");
    }

    void popFront() { //O(1)
        if (empty()) return;
        if (contador == 1) {
            primeiro = NULL;
            ultimo = NULL;
            contador = 0;
            return;
        }
        Node* deletar = primeiro;
        primeiro = primeiro->proximo;
        primeiro->anterior = NULL;
        delete(deletar);
        contador--;
    }

    void popBack() { // O(1)
        if (empty()) return;
        if (contador == 1) {
            primeiro = NULL;
            ultimo = NULL;
            contador = 0;
            return;
        }
        Node* deletar = ultimo;
        ultimo = ultimo->anterior;
        ultimo->proximo = NULL;
        delete(deletar);
        contador--;
    }

    void insert(int v, int p) { //O(n)
        if (p <= 0) {
            pushFront(v);
            return;
        }
        if (p >= contador) {
            pushBack(v);
            return;
        }
        Node* no = new Node(v);
        contador++;
        Node* aux1 = primeiro;
        for (int i = 0; i < p - 1; i++) {
            aux1 = aux1->proximo;
        }
        Node* aux2 = aux1->proximo;
        no->anterior = aux1;
        no->proximo = aux2;
        aux1->proximo = no;
        aux2->anterior = no;
    }

};

int main() {

    ListaDupla l;

    l.pushBack(4);
    l.pushBack(5);
    l.pushBack(6);
    l.pushBack(7);
    l.pushFront(3);
    l.pushFront(2);
    l.pushFront(1);
    l.insert(99, 3);

    l.imprimir();
    l.printBackward();

    return 0;
}