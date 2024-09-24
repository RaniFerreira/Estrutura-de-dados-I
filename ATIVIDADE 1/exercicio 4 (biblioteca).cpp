/******************************************************************************
4. Faça um programa que seja capaz de armazenar informações sobre livros de uma biblioteca.
Seu programa deve ter um TAD para representar o livro, contendo título, autor e número de 
páginas. Além disso, seu TAD deve ter duas operações: ler e imprimir.
Seu programa também deve ter um TAD para representar toda a biblioteca, contendo um 
vetor de livros e a quantidade de livros já armazenados nessa TAD. O máximo de livros
na TAD biblioteca será 10. Seu TAD deve ter uma operação capaz de ler um novo livro, 
uma operação para imprimir todos os livros da biblioteca e outra operação capaz 
de imprimir o livro que contém o maior número de páginas de toda a biblioteca.

*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

struct Livro{
    string titulo;
    string autor;
    int numeroPaginas;
    
    void ler(){
        
        cout << "Digite o titulo do livro: " << endl;
        cin >> titulo;
        cout << "Digite o autor deste livro: " << endl;
        cin >> autor;
        cout << "Digite a quantidade de paginas: "<< endl;
        cin >> numeroPaginas;
    }
    
    void imprimir(){
        
        cout << "------------------------------------------" << endl;
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Total de paginas: " << numeroPaginas << endl;
        cout << "-------------------------------------------" << endl;
    }
    
};

struct Biblioteca{
    
    Livro L[10];
    int quantidade = 0;
    int opcao;
    
    
    void verificarNumeroPaginas(){
        int maior = -999999;
        string tMaior;
        
        for(int i=0; i< quantidade; i++){
            
            if(L[i].numeroPaginas > maior){
                
                maior = L[i].numeroPaginas;
                tMaior =  L[i].titulo;
            }
        }
        
        cout << "Maior numero de paginas: " << maior << endl;
        cout << "Livro: " << tMaior << endl;
       
    }
    
    void operacao(){
        
        do{
            cout << "MENU" << endl;
            cout << "1. Cadastrar Livro" << endl;
            cout << "2. Listar livros cadastrados" << endl;
            cout << "3. Livro com maior número de paginas" << endl;
            cout << "4. Sair" << endl;
            cin >> opcao;
           
           switch(opcao){
               
               case 1:
                if(quantidade >= 10){
                    cout << "Maximo de livros cadastrado atindigo!" << endl;
                }
                else{
                    L[quantidade].ler();
                    quantidade++;
                }
               
               break;
               
               case 2:
                    cout << "Livros Cadastrados: " << endl;
                    
                    for(int i=0; i < quantidade; i++){
                        
                        L[i].imprimir();
                    }
               
               break;
               
               case 3:
                    verificarNumeroPaginas();
               
               break;
               
               case 4:
                    cout << "Programa finalizado" << endl;
               break;
           }
               
           
            
        }while(opcao != 4);
        
    }
};

int main()
{
    Biblioteca b;
    
    b.operacao();
    

    return 0;
}