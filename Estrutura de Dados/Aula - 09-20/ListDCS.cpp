#include "ListDCS.h"
#include <iostream>
#include <cstdlib>
using namespace std;

OrderedList::OrderedList(){
    head = new ListNode;
    if (head == NULL){
        cout << "Memoria insuficiente" << endl;
        abort();
    }
    head->NextNode = head;
    head->PreviousNode = head;
    count = 0;
    cout << "Lista criada" << endl;
}

OrderedList::~OrderedList(){
    ListPointer q = head->NextNode;
    while(q != head){
        ListPointer temp = q->NextNode;
        delete q;
        q = temp;
    }

    delete head;
    count = 0;
    cout << "Lista destruida" << endl;
}

bool OrderedList::Empty(){
    return count == 0;
}

void OrderedList::Insert(int x){
    ListPointer p, q;

    head->Entry = x;
    p = head->NextNode;

    while(p->Entry < x){
        p = p->NextNode;
    }

    if(p != head && p->Entry == x){ // 1º caso
        p->count ++;
    } else {
        q = new ListNode;
        if(q == NULL){
            cout << "Memoria insuficente" << endl;
            abort();
        }
        if(p == head){ // 2º caso - encontra x na sentinela (maior valor da lista)
            q->NextNode = p->NextNode;
            q->PreviousNode = p;
            p->NextNode = q;
            q->NextNode->PreviousNode = q;
            head = q;
        } else { // 3º caso - encontra o primeiro valor maior que x
            *q = *p;
            p->Entry = x;
            p->NextNode = q;
            q->PreviousNode = p;
            q->NextNode->PreviousNode = q;
        }
        p->count ++;
    };
    count ++;
    cout << "Elemento " << x << " inserido com sucesso! " << endl;
}

void OrderedList::Delete(int x){
    ListPointer q;

    q = head->NextNode;
    head->Entry = x;

    while(q->Entry < x){
        q = q->NextNode;
    }
    if (q == head){
        cout << "Elemento nao encontrado" << endl;
        abort();
    }
    if (q->count > 1){
        q->count --;
    } else {
        q->PreviousNode->NextNode = q->NextNode;
        q->NextNode->PreviousNode = q->PreviousNode;
        delete q;
    }
    count --;
}

int OrderedList::Search(int x){
    ListPointer p;
    int pos = 1;
    p = head->NextNode;
    head->Entry = x;

    while(p->Entry < x){
        p = p->NextNode;
        pos++;
    }
    if (p->Entry != x || p == head){
        return 0;
    } else {
        return pos;
    }
}

int OrderedList::Size(){
    return count;
}