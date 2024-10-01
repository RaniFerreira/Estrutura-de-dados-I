/******************************************************************************

Escreva uma função que dado um número real passado como parâmetro,
retorne a parte inteira e a parte fracionária deste número.
Escreva um programa que chama esta função.
*******************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

double* separar (double *pont){
    
    int inteiro;
    double fracionado;
    
    inteiro = floor(*pont);
    fracionado =  *pont - inteiro ;
    
    cout << "Inteiro: " << inteiro << endl;
    cout << "Fracionado: " << fracionado << endl;
    
    return pont;
}

int main()
{
    double valor;
    
    cout << "digite um valor real: " << endl;
    cin >> valor;
    
    cout << separar(&valor) << "  <- endereço do valor: " << endl;

    return 0;
}
