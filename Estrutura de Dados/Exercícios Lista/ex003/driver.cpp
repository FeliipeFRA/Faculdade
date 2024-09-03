#include "Cube.h"
#include <iostream>
using namespace std;

int main() {

    Cube cube1(2);

    cout << cube1.Size() << endl;
    cout << cube1.Area() << endl;
    cout << cube1.Volume() << endl;

    return 0;
}