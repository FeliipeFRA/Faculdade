#include "Queue.h"
#include <iostream>
using namespace std;

#ifndef QUEUE_H
#define QUEUE_h

Queue::Queue(){
    count = 0;
    head = tail = NULL;
}

Queue::~Queue(){
    //Clear();
    
    int x;
    while(!Empty()){
        Serve(x);
    }
}

bool Queue::Empty(){
    return head == NULL;
}

// nao e preciso implementar Full();
// será verificado pela logica do Append();

void Queue::Append(int x){
    QueuePointer p;

    p = new QueueNode;
    if(p == NULL){
        cout << "Memoria insuficiente!" << endl;
        abort();
    }

    p->Entry = x;
    p->NextNode = NULL;
    count ++;
    if (Empty()){
        head = tail = p;
    } else {
        // quando há um ou mais elementos
        tail->NextNode = p;
        tail = p;
    }

}

void Queue::Serve(int &x){
    if (Empty()){
        cout << "Fila vazia! Nao ha elemento para servir." << endl;
        abort();
    }
    QueuePointer p;
    x = head->Entry;
    p = head;
    count --;
    head = head->NextNode;
    delete p;
    if (head == NULL) {
        tail = NULL;
    }
}

void Queue::Clear(){
    int x;
    while(!Empty()){
        Serve(x);
    }
}

int Queue::Size(){
    return count;
}

void Queue::Front(int &x){
    if (Empty()){
        cout << "Fila vazia! Nao ha elemento no inicio da fila!" << endl;
        abort();
    }
    x = head->Entry;
}

void Queue::Rear(int &x){
    if (Empty()){
        cout << "Fila vazia! Nao ha elemento no fim da fila!" << endl;
        abort();
    }
    x = tail->Entry;
}

#endif