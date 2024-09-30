/******************************************************************************
1. Escreva um programa que contenha duas variaveis inteiras.
Leia essas variáveis do teclado.
Em seguida, compare seus endereços e exiba o conteudo do maior endereço.

*******************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    int var1, var2;
    int *pont1, *pont2;
    
    cin >> var1 >> var2;
    
    pont1 = &var1;
    pont2 = &var2;
    
    cout << pont1 << endl << pont2 << endl;
    
    if(pont1 > pont2){
        cout << "O maior endereço é: " << pont1 << endl;
    }
    else{
        cout << "O maior endereço é: " << pont2 << endl;
    }

    return 0;
}
