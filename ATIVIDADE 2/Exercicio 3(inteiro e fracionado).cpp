/******************************************************************************

Escreva uma função que dado um número real passado como parâmetro, retorne a parte inteira e a parte fracionária deste número.
Escreva um programa que chama esta função.

*******************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

struct Divisao{
    double inteiro;
    double fracionado;
    double valor;
    double *pont;
    
    void ler(){
        
        cout << "Digite o valor: " << endl;
        cin  >> valor;
        
        pont = &valor;
        separar();
        
    }
    
    void separar(){
        
        inteiro = floor(valor); // função para tirar o inteiro
        fracionado = valor - inteiro;
    }
    
    void imprimir(){
        
        cout << "inteiro: " << inteiro << endl;
        cout << "fracionado: " << fracionado << endl;
        cout << "endereço do valor real : " << pont << endl;
    }
    
};

int main()
{
    Divisao d;
    
    d.ler();
    d.imprimir();
    

    return 0;
}