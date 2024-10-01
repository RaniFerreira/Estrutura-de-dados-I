/******************************************************************************

4. Implemente uma função que calcule a área da superfície e
o volume de uma esfera de raio R. A area da superfície e o volume 
são dados, respectivamente, por:

A = 4 * p * R^2
V = 4/3 * p * R^3
*******************************************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void areaEvolume( double *raio){
   
    cout << "Area: " << fixed << setprecision(2) <<  4 * 3.1459 * pow(*raio, 2) << endl;
    cout << "volume: " << fixed << setprecision(2) << (4/3) *3.1459 *pow(*raio,3) << endl;
    
    
} 

int main()
{
    double raio;
    
    cout << "digite o raio " << endl;
    cin >> raio;
    
    areaEvolume(&raio);
    
    return 0;
}
