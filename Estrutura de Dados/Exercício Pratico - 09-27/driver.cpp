#include <iostream>
#include <string>
#include "ListDCS.h"
#include <cstdlib>
using namespace std;

//

int main(){
    OrderedList l1, l2;

    l1.PrintList();
    cout << "Tamanho da lista 1: " << l1.Size() << endl;
    l2.PrintList();
    cout << "Tamanho da lista 2: " << l2.Size() << endl;
    cout << "------------------------" << endl;
    l1.Insert(2);
    l1.Insert(4);
    l1.Insert(78);
    l1.Insert(78);
    l1.Insert(23);


    l1.PrintList();
    cout << "Tamanho da lista 1: " << l1.Size() << endl;
    l2.PrintList();
    cout << "Tamanho da lista 2: " << l2.Size() << endl;
    cout << "------------------------" << endl;  

    l1.PrintList();
    cout << "Tamanho da lista 1: " << l1.Size() << endl;
    l2.PrintList();
    cout << "Tamanho da lista 2: " << l2.Size() << endl;
    cout << "------------------------" << endl; 
    l1.BreakList(1, l2);

    l1.PrintList();
    cout << "Tamanho da lista 1: " << l1.Size() << endl;
    l2.PrintList();
    cout << "Tamanho da lista 2: " << l2.Size() << endl;
    cout << "------------------------" << endl; 

    return 0;
}