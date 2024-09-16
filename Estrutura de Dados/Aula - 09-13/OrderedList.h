class OrderedList{
    public:
        OrderedList();
        ~OrderedList();
        bool Empty();
        void Insert(int x);
        void Delete(int x);
        int Size();
        void Clear();
        void Retrieve(int x, int p);
    private:
        struct ListNode{
            int Entry;
            ListNode *NextNode;
        };
        typedef ListNode* ListPointer;
        int count;
        ListPointer head;
        ListPointer sentinel;
};

