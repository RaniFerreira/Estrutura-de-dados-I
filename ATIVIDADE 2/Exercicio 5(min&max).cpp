/******************************************************************************

5. Crie uma função que receba por parâmetro um vetor de números inteiros,
o tamanho do vetor e os endereços de duas variáveis inteiras 
(que podemos chamar de min e max). Ao passar essas variáveis 
para a função seu programa deverá analisar qual é o maior e o 
menor elemento do vetor e depositar 
esses elementos nas variáveis do parâmetro.

*******************************************************************************/
#include <iostream>
using namespace std;

void verificar(int *n,int vet[], int *min, int *max){
   
   *min = vet[0];
   *max = vet[0];
   
   
   for(int i=0; i<*n; i++){
       
       if(vet[i] < *min){
           
           *min = vet[i];
           
       }
       if(vet[i] > *max){
           *max = vet[i];
       }
   }
    cout << "Maior valor : " << *max << "  Endereço: " << max << endl ;
    cout << "Menor valor: " << *min << "  Endereço: " << min << endl;
}

int main()
{
    int N,min,max;
    
    cin >> N;
    int vet[N];
    
    for(int i=0; i< N; i++){
        
        cin >> vet[i];
    }
    
    verificar(&N, vet,&min,&max);
   

    return 0;
}