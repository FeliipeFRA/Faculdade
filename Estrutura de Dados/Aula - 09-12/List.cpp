#include "List.h"
#include <iostream>
using namespace std;

#ifndef LIST_H
#define LIST_H

List::List(){
    count = 0;
    head = NULL;
}

List::~List(){
    ListPointer q;
    while(head != NULL){
        q = head;
        head = head->NextNode;
        delete q;
    }
}

bool List::Empty(){
    return head == NULL;
}

void List::Insert(int x, int p){
    if(p < 1 || p > count + 1){
        cout << "Posicao invalida" << endl;
        abort();
    }

    ListPointer NewNode;
    NewNode = new ListNode;
    if(NewNode == NULL){
        cout << "Falha na alocacao de memoria!" << endl;
        abort();
    }

    NewNode->Entry = x;
    if(p == 1){
        NewNode->NextNode = head;
        head = NewNode;
    } else {
        ListPointer q;
        SetPosition(p - 1, q);
        NewNode->NextNode = q->NextNode;
        q->NextNode = NewNode;
        count++;
    }
}

void List::Delete(int &x, int p){
    if(p < 1 || p > count){
        cout << "Posicao invalida!" << endl;
        abort();
    }

    ListPointer Node;
    if(p==1){
        Node = head;
        head = head->NextNode;
    }else{
        ListPointer q;
        SetPosition(p - 1, q);
        Node = q->NextNode;
        q->NextNode = Node->NextNode;
    }
    x = Node->Entry;
    delete Node;
    count --;
}

int List::Size(){
    return count;
}

void List::SetPosition(int p, ListPointer &current){
    current = head;
    for(int i = 2; i <= p; i++){
        current = current->NextNode;
    }
}

void List::Replace(int x, int p){
    if(p < 1 || p > count){
        cout << "Posicao invalida" << endl;
        abort();
    }

    ListPointer Node;
    SetPosition(p, Node);
    Node->Entry = x;
}

void List::Retrieve(int &x, int p){
    if(p < 1 || p > count){
        cout << "Posicao invalida" << endl;
        abort();
    }

    ListPointer Node;
    SetPosition(p, Node);
    x = Node->Entry;
}


#endif