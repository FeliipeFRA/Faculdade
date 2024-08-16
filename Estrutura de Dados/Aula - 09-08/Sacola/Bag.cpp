#include "Bag.h"
#include <iostream>
#include <string>
using namespace std;

#ifndef BAG_H
#define BAG_H

Bag::Bag(){} /// ??? construtor para adt

void Bag::Insert(int num){
    if (Bag::Full()){
        cout << "A sacola esta cheia!" << endl;
    } else {
        Nums[Quantity] = num;
        Quantity++;
        cout << "Numero " << num << " adicionado com sucesso a sacola!" << endl;
    };
}

int Bag::Occurence(int num){
    int occurence = 0;
    for (int i = 0; i < Quantity; i++) {
        if (Nums[i] == num) {
            occurence++;
        }
    };
    return occurence;
}

void Bag::Remove(int num){
    bool find = false;
    for (int i = 0; i < Quantity; i++) {
        if (Nums[i] == num && !find) {
            find = true;
        }
        if (!find && Nums[i] == num) {
            find = true;
            Quantity--;
            Nums[i] = Nums[i+1];
            i++;
        };
    }
}

bool Bag::Full() {
    if (Quantity == Capacity){
        return true;
    } else {
        return false;
    }
}

#endif