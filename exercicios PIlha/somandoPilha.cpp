#include <iostream>
#include <string>
using namespace std;

struct No {
    int valor;
    No* proximo;

    No(int v) {
        valor = v;
        proximo = NULL;
    }
};

struct Pilha {
    No* topo;

    Pilha() {
        topo = NULL;
    }

    bool vazia() {
        return topo == NULL;
    }

    void empilhar(int v) {
        No* novo = new No(v);
        novo->proximo = topo;
        topo = novo;
    }

    int desempilhar() {
        if (vazia()) {
            return 0;  // Caso a pilha esteja vazia, retorna 0
        }
        No* temp = topo;
        int valor = temp->valor;
        topo = topo->proximo;
        delete temp;
        return valor;
    }
};

int somarNumeros(Pilha& pilha1, Pilha& pilha2) {
    Pilha resultado;
    int carry = 0;

    // Enquanto qualquer pilha não estiver vazia ou houver transporte (carry)
    while (!pilha1.vazia() || !pilha2.vazia() || carry > 0) {
        // Soma o topo das pilhas, mais o carry de uma soma anterior
        int soma = pilha1.desempilhar() + pilha2.desempilhar() + carry;
        
        // Empilha o dígito da soma (resto da divisão por 10)
        resultado.empilhar(soma % 10);
        
        // Atualiza o carry (parte inteira da soma dividida por 10)
        carry = soma / 10;
    }

    // Para armazenar o número final em ordem correta
    string numeroFinal = "";

    // Desempilha os dígitos do resultado e forma o número final
    while (!resultado.vazia()) {
        numeroFinal += to_string(resultado.desempilhar());
    }

    // Retorna o número final (convertido de string para inteiro)
    return stoi(numeroFinal);
}

int main() {
    Pilha pilha1;
    Pilha pilha2;

    string num1, num2;
    cout << "Digite o primeiro numero: ";
    cin >> num1;
    cout << "Digite o segundo numero: ";
    cin >> num2;

    // Empilhar os dígitos do primeiro número (do último para o primeiro)
    for (char digito : num1) {
        pilha1.empilhar(digito - '0');  // Converte o caractere para inteiro e empilha
    }

    // Empilhar os dígitos do segundo número (do último para o primeiro)
    for (char digito : num2) {
        pilha2.empilhar(digito - '0');  // Converte o caractere para inteiro e empilha
    }

    int resultado = somarNumeros(pilha1, pilha2);
    cout << "Resultado da soma: " << resultado << endl;

    return 0;
}
