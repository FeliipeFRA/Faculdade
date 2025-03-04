// arquivo de implementação
#include "Cube.h"
#include <iostream>
using namespace std;

#ifndef CUBE_H
#define CUBE_H

Cube::Cube(int size){
    cout << "Cubo criado!" << endl;
    facesize = size;
    area = facesize * facesize;
    volume = facesize * facesize * facesize;
};

Cube::~Cube(){
    cout << "Cubo destruido!" << endl;
};

int Cube::Size(){
    return facesize;
};

int Cube::Area(){
    return area;
};

int Cube::Volume(){
    return volume;
};

#endif