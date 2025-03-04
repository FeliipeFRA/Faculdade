#include "Queue.h"
#include <iostream>

using namespace std;

int main() {
    Queue fila1;
    int x;


    fila1.Append(3);
    fila1.Append(5);
    fila1.Append(7);
    fila1.Serve(x);
    cout << fila1.Size() << endl;
    
    return 0;
}

// navegar no diretório cd TAB
// cd 'local'
// g++ (main)    (implementação) -o (executavel)
// g++ driver.cpp Capacete.cpp -o teste.exe
// ./teste.exe