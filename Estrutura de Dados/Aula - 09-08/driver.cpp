#include <iostream>
#include "Capacete.h"
using namespace std;

int main() {
    Cap capacete1;
    capacete1.Slots("Ola", "Tchau");
    capacete1.pressleft();
    capacete1.pressright();
    return 0;
}

// g++ driver.cpp Capacete.cpp -o teste.exe
// ./teste.exe