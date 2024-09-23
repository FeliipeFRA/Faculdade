// cabeçalho
#pragma once

class OrderedList{
    public:
        OrderedList();
        ~OrderedList();
        bool Empty();
        void Insert(int x);
        void Delete(int x);
        int Size();
        void Clear();
        int Search();
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
};