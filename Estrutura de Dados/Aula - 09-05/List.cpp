#include "List.h"
#include <cstdlib>
#include <iostream>
using namespace std;

#ifndef LIST_H
#define LIST_H

List::List(){
    count = 0;
}

List::~List(){
    cout << "\nLista destruida!\n" << endl;
}

bool List::Empty(){
    return count == 0;
}

bool List::Full(){
    return count == MaxList;
}

void List::Insert(int x, int p){
    if(Full()){
        cout << "Lista Cheia! Sem espaco para novo elemento!" << endl;
        abort();
    }
    if(p<1 || p > count + 1){
        cout << "Posicao invalida!" << endl;
        abort();
    }
    for(int i = count; i >= p; i--){
        Entry [i + 1] = Entry[i];
    }
    Entry[p] = x;
    count ++;
}

void List::Delete(int &x, int p){
    if(Empty()){
        cout << "Lista vazia! Nao ha elementos para retirar" << endl;
        abort();
    }
    if(p<1 || p > count){
        cout << "Posicao invalida!" << endl;
        abort();
    }
    x = Entry[p];
    for(int i = p+1; i < count; i++){
        Entry[i] = Entry[i + 1];
    }
    count --;
}

int List::Size(){
    return count;
}

void List::Clear(){
    count = 0;
}

void List::Retrieve(int &x, int p){
    if (p < 1 || p > count){
        cout << "Posicao invalida!" << endl;
        abort();
    }
    x = Entry[p];
}

void List::Replace(int x, int p){
    if(p < 1 || p > count){
        cout << "Posicao invalida!" << endl;
        abort();
    }
    Entry[p] = x;
}


#endif