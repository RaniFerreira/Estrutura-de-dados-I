/******************************************************************************

2. Crie um programa que contenha um array de float contendo 10 elementos.
Imprima o endereço de cada posição do array.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    float array[10];
    float *pont[10];
    
    
    //endereços do array
    
    for(int i=0;i<10;i++){
        
        pont[i] = &array[i];
        cout << "Endereço " << i << " " << pont[i] << endl;
    }
    

    return 0;
}