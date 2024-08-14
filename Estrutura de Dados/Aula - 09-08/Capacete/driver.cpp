#include <iostream>
// incluir arquivo.h com a classe
#include "Capacete.h"
using namespace std;

int main() {
    // criar objetos
    Cap cap1, cap2;
    // ativando o método do objeto
    // nome do objeto.metodo(arg)
    cap1.Slots("Gabigol", "Em Dezembro de 81");
    cap1.pressleft();
    return 0;
}

// navegar no diretório cd..
// cd 'local'
// g++ (main)    (implementação) -o (executavel)
// g++ driver.cpp Capacete.cpp -o teste.exe
// ./teste.exe