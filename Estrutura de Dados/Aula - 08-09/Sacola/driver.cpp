#include <iostream>
#include "Bag.h"
using namespace std;

int main(){
    Bag bag1;

    bag1.Insert(2);
    cout << "Quantos 2 tem na sacola 1: " << bag1.Occurence(2) << endl;
    cout << "Quantos 3 tem na sacola 1: " << bag1.Occurence(3) << endl;

    return 0;
}

// g++ driver.cpp Bag.cpp -o teste.exe
// ./teste.exe