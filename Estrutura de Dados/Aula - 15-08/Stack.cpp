// Arquivo de implementação da classe Stack
#include "Stack.h"
#include <iostream>
using namespace std;

#ifndef STACK_H
#define STACK_H
Stack::Stack(){
    top = 0;
}

Stack::~Stack(){
    cout << "Pilha destruida." << endl;
}

bool Stack::Full(){
    return (top == MaxStackSize);
}

bool Stack::Empty(){
    return (top == 0);
}

void Stack::Push(int x){
    if(Full()){
        cout << "Pilha cheia!!!" << endl;
        abort();
    } else {
        top++;
        entry[top] = x;
    }
}

void Stack::Pop(int &x){
    if(Empty()){
        cout << "Pilha vazia!!!" << endl;
        abort();
    }
    x = entry[top];
    top--;
}

int Stack::Size(){
    return top;
}

void Stack::Clear(){
    top = 0;
}

void Stack::Top(int &x){
    if(Empty()){
        cout << "Nao ha elementos no topo" << endl;
        abort();
    }
}
#endif