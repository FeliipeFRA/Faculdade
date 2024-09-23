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

    if(p != head && p->Entry == x){
        p->count ++;
    } else {
        q = new ListNode;
        if(q == NULL){
            cout << "Memoria insuficente" << endl;
            abort();
        }
        if(p == head){
            q->NextNode = p->NextNode;
            q->PreviousNode = p;
            p->NextNode = q;
            q->NextNode->PreviousNode = q;
            head = q;
        } else {
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