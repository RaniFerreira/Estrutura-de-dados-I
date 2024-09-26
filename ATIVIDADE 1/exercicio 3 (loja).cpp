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

struct Loja {
    string nome;
    string cargo;
    double salarioBase;
    double beneficio;
    double desconto;

    void leitura() {
        cout << "Insira o nome do funcionário: " << endl;
        cin.ignore();
        getline(cin, nome);
        cout << "Insira o cargo: " << endl;
        getline(cin, cargo);
        cout << "Digite o salário: " << endl;
        cin >> salarioBase;
        cout << "Digite o valor do benefício: " << endl;
        cin >> beneficio;
        cout << "Digite o valor a ser descontado: " << endl;
        cin >> desconto;
    }

    double calcularSalario() {
        return (salarioBase + beneficio) - desconto;
    }

    void listar() {
        cout << "Nome: " << nome << endl;
        cout << "Cargo: " << cargo << endl;
        cout << fixed << setprecision(2) << "Salário Base: " << salarioBase << endl;
        cout << fixed << setprecision(2) << "Valor do benefício: " << beneficio << endl;
        cout << fixed << setprecision(2) << "Valor do desconto: " << desconto << endl;
        cout << fixed << setprecision(2) << "Salário Líquido: " << calcularSalario() << endl;
    }

    static void calcularMediaSalarios(Loja loja[], int contador) {
        double somaSalarios = 0;
        for (int i = 0; i < contador; i++) {
            somaSalarios += loja[i].calcularSalario();
        }
        double media = (contador > 0) ? somaSalarios / contador : 0;
        cout << fixed << setprecision(2) << "Média Salarial: " << media << endl;
    }

    static void funcionarioMaiorSalario(Loja loja[], int contador) {
        if (contador == 0) {
            cout << "Não há funcionários cadastrados!" << endl;
            return;
        }
        int indiceMaiorSalario = 0;
        double maiorSalario = loja[0].calcularSalario();

        for (int i = 1; i < contador; i++) {
            if (loja[i].calcularSalario() > maiorSalario) {
                maiorSalario = loja[i].calcularSalario();
                indiceMaiorSalario = i;
            }
        }
        cout << "Funcionário com maior salário:\n";
        loja[indiceMaiorSalario].listar();
    }
};

int main() {
    Loja loja[10];
    int contador = 0;
    int opcao;

    do {
        cout << "MENU" << endl;
        cout << "1. Cadastrar Funcionário\n";
        cout << "2. Listar Funcionários\n";
        cout << "3. Visualizar média salarial da loja" << endl;
        cout << "4. Funcionário com maior Salário" << endl;
        cout << "5. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                if (contador >= 10) {
                    cout << "Capacidade máxima de cadastros atingida!" << endl;
                } else {
                    loja[contador].leitura();
                    contador++;
                }
                break;

            case 2:
                if (contador == 0) {
                    cout << "Não há funcionários cadastrados!" << endl;
                } else {
                    for (int i = 0; i < contador; i++) {
                        cout << "\nFuncionário " << (i + 1) << ":\n";
                        loja[i].listar();
                    }
                }
                break;

            case 3:
                if (contador == 0) {
                    cout << "Não há funcionários cadastrados!" << endl;
                } else {
                    Loja::calcularMediaSalarios(loja, contador);
                }
                break;

            case 4:
                if (contador == 0) {
                    cout << "Não há funcionários cadastrados!" << endl;
                } else {
                    Loja::funcionarioMaiorSalario(loja, contador);
                }
                break;

            case 5:
                cout << "Programa finalizado!" << endl;
                break;

            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    } while (opcao != 5);

    return 0;
}
