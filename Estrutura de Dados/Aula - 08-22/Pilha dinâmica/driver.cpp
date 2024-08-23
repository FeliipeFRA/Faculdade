#include "Stack.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    Stack pilha1;
    int x;

    do{
        cout << "Informe o numero que deseja adicionar na pilha (!=0) ";
        cin >> x;
        if (x != 0) {
            pilha1.Push(x);
        }
    } while (x != 0);

    cout << "Tamanho da pilha1: " << pilha1.Size() << endl;
    
    pilha1.Pop(x);
    pilha1.Pop(x);
    
    pilha1.Top(x);

    cout << "Topo da pilha: " << x << endl;

    return 0;
}