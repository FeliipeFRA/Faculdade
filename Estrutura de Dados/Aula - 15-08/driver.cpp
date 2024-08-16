#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
    Stack s1, s2;
    int x;

    do{
        cout << "Informe o numero que deseja dicionar na pilha (!=0) ";
        cin >> x;
        s1.Push(x);
    } while (x != 0);

    cout << "A quantidade de elemtnos armazenados na pilha: " << s1.Size() << endl;

    while(!s1.Empty()){
        s1.Pop(x);
        cout << "- " << x << endl;
    }

    return 0;
}