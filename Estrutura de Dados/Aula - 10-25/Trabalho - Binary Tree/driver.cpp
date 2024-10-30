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
            cout << "Numero a ser inserido: ";
            cin >> n;
            arvore1.Insert(arvore1.root, n);
            break;
        case '2':
            cout << "--------------------------" << endl;
            cout << "   IMPRESSAO CRESCENTE" << endl;
            arvore1.CrescentPrintTree(arvore1.root);
            break;
        case '3':
            cout << "--------------------------" << endl;
            cout << "   IMPRESSAO DECRESCENTE" << endl;
            arvore1.DecrescentPrintTree(arvore1.root);
            break;
        case '4':
            cout << "--------------------------" << endl;
            cout << "       BUSCAR VALOR" << endl;
            int num;
            cout << "Numero a ser procurado: ";
            cin >> num;
            if (arvore1.SearchValue(arvore1.root, num)){
                cout << "O numero " << num << " existe na arvore" << endl;
            } else {
                cout << "O numero " << num << " NAO existe na arvore" << endl;
            }
            break;
        case '5':
            cout << "--------------------------" << endl;
            cout << "   OCORRENCIA DE VALOR" << endl;
            cout << "Numero a ser procurado: ";
            cin >> num;
            if (arvore1.SearchValue(arvore1.root, num)){
                cout << "O numero " << num << " ocorre " << arvore1.ValueOccur(arvore1.root, num) << " vezes na arvore" << endl;
            } else {
                cout << "O numero " << num << " NAO existe na arvore" << endl;
            }
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