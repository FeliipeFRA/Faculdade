class OrderedList{
    public:
        OrderedList();
        ~OrderedList();
        bool Empty();
        void Insert(int x);
        void Delete(int x);
        int Size();
        void Clear();
        void Search(int x); // return 0 se o elemento não ocorrer na lista
        // senão ele retorna a posicao da primeira ocorrencia
    private:
        struct ListNode{
            int Entry;
            ListNode *NextNode;
        };
        typedef ListNode* ListPointer;
        int count;
        ListPointer head, sentinel;
};

