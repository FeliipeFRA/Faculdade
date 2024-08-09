// Seção de Implementação
#include "Capacete.h"
// importa as classes de Capacete.h
#include <iostream>
#include <string>
using namespace std;

// evitar a repetição da definição do codigo toda vez que der includ
#ifndef CAPACETE_H
#define CAPACETE_H

void Cap::pressleft(){
    cout << leftSlot << endl;
}
void Cap::pressright(){
    cout << rightSlot << endl;
}
void Cap::Slots(string newLeft, string newRight){
    leftSlot = newLeft;
    rightSlot = newRight;
}
#endif