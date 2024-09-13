#include "List.h"
#include <iostream>
using namespace std;

int main(){
    List L1, L2;

    L1.Insert(10,1);
    L1.Insert(15,2);
    int x;
    L1.Retrieve(x,1);

    cout << "Elemento na posicao 1" << x;

    return 0;
}