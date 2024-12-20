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

struct Fila {
    No* inicio;
    No* fim;

    Fila() {
        inicio = NULL;
        fim = NULL;
    }

    bool vazia() {
        return inicio == NULL;
    }

    void enfileirar(int v) {
        No* novo = new No(v);
        if (vazia()) {
            inicio = fim = novo;
        } else {
            fim->proximo = novo;
            fim = novo;
        }
    }

    int desenfileirar() {
        if (vazia()) {
            return 0;  // Caso a fila esteja vazia, retorna 0
        }
        No* temp = inicio;
        int valor = temp->valor;
        inicio = inicio->proximo;
        delete temp;
        return valor;
    }
};

int somarNumeros(Fila& fila1, Fila& fila2) {
    Fila resultado;
    int carry = 0;

    // Enquanto qualquer fila não estiver vazia ou houver transporte (carry)
    while (!fila1.vazia() || !fila2.vazia() || carry > 0) {
        // Soma o início das filas, mais o carry de uma soma anterior
        int soma = fila1.desenfileirar() + fila2.desenfileirar() + carry;
        
        // Enfileira o dígito da soma (resto da divisão por 10)
        resultado.enfileirar(soma % 10);
        
        // Atualiza o carry (parte inteira da soma dividida por 10)
        carry = soma / 10;
    }

    // Para armazenar o número final em ordem correta
    string numeroFinal = "";

    // Desenfileira os dígitos do resultado e forma o número final
    while (!resultado.vazia()) {
        numeroFinal += to_string(resultado.desenfileirar());
    }

    // Retorna o número final (convertido de string para inteiro)
    return stoi(numeroFinal);
}

int main() {
    Fila fila1;
    Fila fila2;

    string num1, num2;
    cout << "Digite o primeiro numero: ";
    cin >> num1;
    cout << "Digite o segundo numero: ";
    cin >> num2;

    // Enfileirar os dígitos do primeiro número
    for (char digito : num1) {
        fila1.enfileirar(digito - '0');  // Converte o caractere para inteiro e enfileira
    }

    // Enfileirar os dígitos do segundo número
    for (char digito : num2) {
        fila2.enfileirar(digito - '0');  // Converte o caractere para inteiro e enfileira
    }

    int resultado = somarNumeros(fila1, fila2);
    cout << "Resultado da soma: " << resultado << endl;

    return 0;
}
