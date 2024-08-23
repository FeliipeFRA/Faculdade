#include "Stack.h"
#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef STACK_H
#define STACK_H

Stack::Stack(){ // criador
    size = 0;
    top = NULL;
}

Stack::~Stack(){ // criador
    Clear();
    cout << "Pilha destruida." << endl;
}

void Stack::Clear(){
    // StackPointer p;
    // while(top != NULL) {
    //      p = top;
    //      top = top->NextNode;
    //      delete p;
    //}
    
    int x;
    while (!Empty()) {
        Pop(x);
    }
}

void Stack::Push(int x){
    StackPointer p; // = StackNode *p
    p = new StackNode; // alocar na memoria
    if (p==NULL){
        cout << "Falha na alocacao, memoria insuficiente!!!";
        abort();
    }
    p->Entry = x;
    p->NextNode = top;
    top = p;
    size++;
}

void Stack::Pop(int &x){
    if (Empty()) {
        cout << "Pilha esta vazia" << endl;
        abort();
    }
    StackPointer p;
    x = top->Entry;
    p = top;
    top = top->NextNode;
    delete p;
    size--;
}

void Stack::Top(int &x){
    x = top->Entry;
}

int Stack::Size(){
    return size;
}

bool Stack::Full(){
    return false;
}

bool Stack::Empty(){
    return top == NULL;
}

#endif