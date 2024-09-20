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
    cout = 0;
}

bool OrderedList::Empty