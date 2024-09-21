/******************************************************************************

1. Criar uma struct para armazenar um cliente,

contendo os seguintes dados: nome, data de nascimento,
idade e sexo. O sexo é apenas uma letra (M ou F) e a data 
de nascimento deve ser armazenada numa struct de data, com 3 inteiros
(dia, mês e ano). A idade deve ser calculada quando a data de nascimento 
for lida, e não solicitada ao usuário. Guarde a data atual numa variável 
da struct de data e crie uma função para calcular a idade.

Após isso, criar um menu com 2 opções: cadastrar cliente e listar clientes.
Na primeira, um cliente deve ser lido e na segunda exibidos todos os clientes
em ordem de cadastro.
Trate para que seu aplicativo armazene no máximo 50 clientes ao mesmo tempo.
*******************************************************************************/
#include <iostream>
#include <string>
#include <ctime>
using namespace std;



struct Data{
    
    int dia, mes, ano;
    
    void lerData(){
        
        cout << "Digite a data de nascimento: " << endl;
        cout << "Dia: " << endl;
        cin >> dia;
        cout << "Mes: " << endl;
        cin >> mes;
        cout << "Ano: " << endl;
        cin >> ano;
    }
    
    int calcularIdade() {
        time_t t;
        struct tm tempoAtual;

        time(&t);
        tempoAtual = *localtime(&t);

        int diaAtual = tempoAtual.tm_mday;
        int mesAtual = tempoAtual.tm_mon + 1;
        int anoAtual = tempoAtual.tm_year + 1900; 

        int idade = anoAtual - ano;

        
        if (mesAtual < mes || (mesAtual == mes && diaAtual < dia)) {
            idade--;
        }
        
        return idade;

    }
    
};
struct Cliente{
    
    string nome;
    char sexo;
    Data dNasc;
    
    void cadastro(){
        
        cout << "Nome do Cliente: " << endl;
        cin >> nome;
        cout << "Sexo (M ou F): " << endl;
        cin >> sexo;
        
        dNasc.lerData();
        
        
        
        
    }
    
    void listar(){
        cout << "Nome do Cliente: " << nome << endl;
       
        cout << "Sexo (M ou F): " << sexo << endl;
        
        cout << "Data de nascimento: " << dNasc.dia << "/"
        << dNasc.mes << "/" << dNasc.ano << endl;
        
        cout << "Idade: " << dNasc.calcularIdade() << " anos" << endl;
        
    }
};

int main()
{
    
    Cliente c[50];
    int contador = 0;
    
    int opcao;

    do {
        cout << "\nMENU\n";
        cout << "1. Cadastrar Cliente\n";
        cout << "2. Listar Clientes\n";
        cout << "3. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                if (contador >= 50) {
                    cout << "Capacidade Máxima de cadastros atingida!" << endl;
                } else {
                    c[contador].cadastro();
                    contador++;
                }
                break;

            case 2:
                if (contador == 0) {
                    cout << "Não há clientes cadastrados!" << endl;
                } else {
                    for (int i = 0; i < contador; i++) {
                        cout << "\nCliente " << (i + 1) << ":\n";
                        c[i].listar();
                    }
                }
                break;

            case 3:
                cout << "Programa Finalizado." << endl;
                break;

            default:
                cout << "Opcao invalida! Tente novamente." << endl;
                break;
        }
    } while (opcao != 3);
    
    
    
    

    

    return 0;
}