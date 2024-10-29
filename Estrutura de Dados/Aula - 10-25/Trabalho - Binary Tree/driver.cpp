#include <iostream>
#include <string>
#include "BinaryTree.h"
#include <cstdlib>
using namespace std;

// g++ driver.cpp BinaryTree.cpp -o driver.exe

int main(){
    BinaryTree arvore1;
    bool fim = false;
    while (!fim)
    {
        char op;       
        cout << "--------------------------" << endl;
        cout << "BINARY TREE" << endl;
        cout << "--------------------------" << endl;
        cout << "[1] - Inserir Item\n[2] - Impressao Crescente\n[3] - Impressao Decrescente\n[4] - Buscar Valor\n[5] - Ocorrencia de um valor\n[6] - Finalizar Programa" << endl;
        cout << "Opcao ---> ";
        cin >> op;
        switch (op)
        {
        case '1':
            int n;
            cout << "Numero a ser inserido: " << endl;
            cin >> n;
            arvore1.Insert(arvore1.root, n);
            break;
        case '2':
            cout << "--------------------------" << endl;
            cout << "   IMPRESSAO CRESCENTE" << endl;
            arvore1.PrintRoot(arvore1.root);
            break;
        case '6':
            fim = true;
            break;
        default:
            cout << "Opcao invalida!" << endl;
            break;
        }
    }
    


    return 0;
}