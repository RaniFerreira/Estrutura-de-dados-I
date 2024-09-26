/**
2. Você deverá implementar um tipo abstrato de dados Conjunto para
representar conjuntos de números inteiros. Seu tipo abstrato deverá armazenar
os elementos do conjunto e o seu tamanho n. Considere que o tamanho máximo de um
conjunto é 20 elementos e use arranjos de 1 dimensão (vetores) para a sua implementação.
Seu TAD deve possuir procedimentos (ou funções quando for o caso) para:
a. criar um conjunto vazio;
b. ler os dados de um conjunto;
c. fazer a união de dois conjuntos;
d. fazer a interseção de dois conjuntos;
e. imprimir um conjunto
**/

#include <iostream>
using namespace std;

struct Conjunto {
    int elementos[20];  
    int tamanho; 

   
    void criaConjunto() {
        tamanho = 0; 
    }

  
    void ler() {
        int n;
        cout << "Quantos elementos deseja inserir no conjunto? (Máximo 20): ";
        cin >> n;

        if (n > 20) {
            cout << "O conjunto pode conter no máximo 20 elementos." << endl;
            return;
        }
        tamanho = n;
        
        cout << "Digite os " << n << " elementos do conjunto: " << endl;
        for (int i = 0; i < n; i++) {
            cin >> elementos[i];
        }
    }

   
    Conjunto Uniao(Conjunto &B) {
        Conjunto uniao;
        uniao.criaConjunto(); 
        
        for (int i = 0; i < tamanho; i++) {
            uniao.elementos[uniao.tamanho] = elementos[i];
            uniao.tamanho++;
        }

        for (int i = 0; i < B.tamanho; i++) {
            bool encontrado = false;
            for (int j = 0; j < tamanho; j++) {
                if (B.elementos[i] == elementos[j]) {
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                uniao.elementos[uniao.tamanho] = B.elementos[i];
                uniao.tamanho++;
            }
        }

        return uniao;
    }

   
    Conjunto Intersecao(Conjunto &B) {
        Conjunto intersecao;
        intersecao.criaConjunto();  

        
        for (int i = 0; i < tamanho; i++) {
            for (int j = 0; j < B.tamanho; j++) {
                if (elementos[i] == B.elementos[j]) {
                    intersecao.elementos[intersecao.tamanho] = elementos[i];
                    intersecao.tamanho++;
                    break;
                }
            }
        }

        return intersecao;
    }

    
    void Impressao() {
        cout << "{ ";
        for (int i = 0; i < tamanho; i++) {
            cout << elementos[i];
            if (i < tamanho - 1) {  
                cout << ", ";
            }
        }
        cout << " }" << endl;
    }
};

int main() {
    Conjunto A, B, uniao, intersecao;
    int opcao;

    do {
        cout << "--- \nMENU ---" << endl;
        cout << "1. Criar conjunto A" << endl;
        cout << "2. Criar conjunto B" << endl;
        cout << "3. Fazer união de A e B" << endl;
        cout << "4. Fazer interseção de A e B" << endl;
        cout << "5. Imprimir conjunto A" << endl;
        cout << "6. Imprimir conjunto B" << endl;
        cout << "7. Sair" << endl;

        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                A.ler();
                break;
            case 2:
                B.ler();
                break;
            case 3:
                uniao = A.Uniao(B);
                cout << "União dos conjuntos A e B: ";
                uniao.Impressao();
                break;
            case 4:
                intersecao = A.Intersecao(B);
                cout << "Interseção dos conjuntos A e B: ";
                intersecao.Impressao();
                break;
            case 5:
                cout << "Conjunto A: ";
                A.Impressao();
                break;
            case 6:
                cout << "Conjunto B: ";
                B.Impressao();
                break;
            case 7:
                cout << "Programa finalizado!" << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    } while (opcao != 7);

    return 0;
}
