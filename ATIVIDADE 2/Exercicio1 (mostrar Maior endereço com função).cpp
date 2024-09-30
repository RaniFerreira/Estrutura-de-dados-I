/******************************************************************************
1. Escreva um programa que contenha duas variaveis inteiras.
Leia essas variáveis do teclado.
Em seguida, compare seus endereços e exiba o conteudo do maior endereço.

*******************************************************************************/

#include <iostream>
using namespace std;

int endereco(int *pont1, int *pont2){
    
    cout << "Endereços: " << endl;
    cout << pont1 << endl;
    cout << pont2 << endl;
    
    if(pont1 > pont2){
         cout << "O maior endereço: "<< pont1 << endl <<
        "valor guardado: " << *pont1 << endl;
    }
    else{
        cout << "O maior endereço: "<< pont2 << endl << 
        "valor guardado: " << *pont2 << endl;
    }
    
    return 0;
    
}

int main()
{   
    
    int var1, var2;
    
    cin >> var1 >> var2;
    
    endereco(&var1,&var2);

    return 0;
}
