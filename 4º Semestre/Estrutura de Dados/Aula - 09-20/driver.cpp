#include <iostream>
#include <string>
#include "ListDCS.h"
#include <cstdlib>
using namespace std;

// g++ driver.cpp ListDCS.cpp -o driver.exe

int main(){
    OrderedList l1;

    cout << "Tamanho da lista: " << l1.Size() << endl;
    l1.Insert(2);
    cout << "Tamanho da lista: " << l1.Size() << endl;
    l1.Insert(2);
    l1.Insert(4);
    l1.Insert(1);
    cout << "Tamanho da lista: " << l1.Size() << endl;
    l1.Delete(4);
    cout << "Tamanho da lista: " << l1.Size() << endl;
    return 0;
}