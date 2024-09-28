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
    ListPointer q;

    ListPointer p = head->NextNode;
    while(q != head){
        q = p;
        p = p->NextNode;
        delete q;
    }
    delete head;
    cout << "Lista destruida" << endl;
}

void OrderedList::Clear(){
    ListPointer p, q;
    p = head->NextNode;
    while(p != head){
        q = p;
        p = p->NextNode;
        delete q;
    }
    head->NextNode = head;
    head->PreviousNode = head;
    count = 0;
}

bool OrderedList::Empty(){
    return count == 0;
}

// 1 versao
/*
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
*/

// 2 versao
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
        q->Entry = x;
        q->count = 1;
        q->NextNode = p;
        q->PreviousNode = p->PreviousNode;
        p->PreviousNode->NextNode = q;
        p->PreviousNode = q;
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
        cout << "Elemento " << q->Entry << " removido com sucesso" << endl;
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

void OrderedList::BreakList(int pos, OrderedList &newList){
    if (!newList.Empty()){
        cout << "Segunda lista passada como argumento nao esta vazia!" << endl;
        abort();
    }
    if(pos < 1 || pos > count + 1){
        cout << "Posicao invalida passada como argumento!" << endl;
        abort();
    }

    ListPointer ponteiro, q;

    SetPosition(pos, ponteiro);

    while(ponteiro != head){
        int vezes = 0;
        for (int i = 1; i <= ponteiro->count; i++){
            vezes++;
            newList.Insert(ponteiro->Entry);
        }
        q = ponteiro;
        ponteiro = ponteiro->NextNode;
        for (int i = 0; i < vezes; i++){
            Delete(q->Entry);
        }
    }
}

void OrderedList::SetPosition(int pos, ListPointer &current){
    current = head;
    for(int i = 1; i <= pos; i++){
        current = current->NextNode;
    }
}

void OrderedList::PrintList(){
    ListPointer p;
    cout << "Lista: ";
    // achar a posicao e parar o ponteiro p
    p = head->NextNode;
    while(p != head){
        cout << p->Entry << "[" << p->count << "]  ";
        p = p->NextNode;
    }
    cout << "\n";
}