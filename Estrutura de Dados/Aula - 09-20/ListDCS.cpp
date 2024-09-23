#include "ListDCS.h"
#include <iostream>
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
}

OrderedList::~OrderedList(){

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

}

void OrderedList::Delete(int x){
    ListPointer q;

    q = head->NextNode;
    head->Entry = x;

    while(q->Entry < x){
        q = q.NextNode;
    }

}