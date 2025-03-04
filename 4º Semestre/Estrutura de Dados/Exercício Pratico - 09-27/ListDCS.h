// cabeçalho
#pragma once

class OrderedList{
    private:
        struct ListNode{
            int Entry;
            ListNode* NextNode;
            ListNode* PreviousNode;
            int count;
        };
        typedef ListNode *ListPointer;
        ListPointer head;
        int count;
    public:
        OrderedList();
        ~OrderedList();
        bool Empty();
        void Insert(int x);
        void Delete(int x);
        int Size();
        void Clear();
        int Search(int x);
        void BreakList(int pos, OrderedList &newList);
        void PrintList();
        void SetPosition(int pos, ListPointer &current);
};