/******************************************************************************

3. Uma loja precisa controlar a folha de pagamento de seus funcionários. 
Os atributos de um funcionário são nome, cargo, salário base, benefícios e descontos.
Criar uma struct para a loja e cadastrar uma lista de no máximo 10 funcionários com os 
campos acima e depois mostre os dados de cada um deles, com o salário liquido de cada um. 
O cálculo do salário líquido é: salário base + benefícios – descontos.
Criar operações também para exibir a média salarial da loja e exibir quem recebe o maior salário

*******************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


struct Loja{
    
    string nome;
    string cargo;
    double salarioBase;
    double beneficio;
    double desconto;
    
    void leitura(){
       
       cout << "Insira o nome do funcionário: " << endl;
       cin >> nome;
       cout << "Insira o cargo: " << endl;
       cin >> cargo;
       cout << "Digite o salário: " << endl;
       cin >> salarioBase;
       cout << "Digite o valor do beneficio: " << endl;
       cin >> beneficio;
       cout << "Digite o vaor a ser descontado: " << endl;
       cin >> desconto;
       
       Loja l;
       
       l.calcularSalario();
    
    }
    
    int calcularSalario(){
        
        int salarioLiquido = (salarioBase + beneficio) - desconto;
        
        return salarioLiquido;
    }
    
    void listar(){
        
        Loja lo;
        cout << "Nome: " << nome <<endl;
        cout << "Cargo: " << cargo << endl;
        cout << fixed << setprecision(2) << "Salario Base: "<< salarioBase << endl;
        cout << fixed << setprecision(2) <<  "Valor do beneficio: " << beneficio << endl;
        cout << fixed << setprecision(2) << "Valor do desconto: " << desconto << endl;
        cout << fixed << setprecision(2) << "Salario Líquido: " << lo.calcularSalario() << endl;
        
    }
    
};



int main()
{
    Loja loja[10];
    int  contador = 0;
    int opcao;
    int media;
    
    do{
      
      cout << "MENU" << endl;
      cout << "1. Cadastrar Cliente\n";
      cout << "2. Listar Clientes\n";
      cout << "3. Visualizar média salarial da loja" << endl;
      cout << "4. Funcionário com maior Salario" << endl;
      cout << "5. Sair\n";
      cout << "Escolha uma opcao: ";
      cin >> opcao;
      
      switch(opcao){
          case 1: 
          
          if(contador >= 10){
              cout << "Capacidade Máxima de cadastros atingida!" << endl;
          }
          else{
              loja[contador].leitura();
              contador++;
          }
          break;
          
          case 2:
          
          if(contador == 0){
              cout << "Não há funcionários cadastrados!" << endl;
          }
          else{
              for(int i=0;i < contador; i++){
                  cout << "\nFuncionário " << (i + 1) << ":\n";
                  loja[i].listar();
              }
          }
          break;
        
      }
    }while(opcao != 5);
    
    

    return 0;
}