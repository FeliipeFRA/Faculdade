#include "Cilinder.h"
#include <iostream>
using namespace std;

#ifndef CILINDER_H
#define CILINDER_H

Cilinder::Cilinder(float h, float r){
    cout << "Cilindro criado!" << endl;
    height = h;
    radius = r;
    area = 2 * 3.14 * radius * height + 2 * 3.14 * radius * radius;
    volume = 3.14 * radius * radius * height;
};

Cilinder::~Cilinder(){
    cout << "Cilindro destruido!" << endl;
}

#endif