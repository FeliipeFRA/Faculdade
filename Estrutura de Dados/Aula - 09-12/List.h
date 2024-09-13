class List{
    public:
        List();
        ~List();
        bool Empty();
        void Insert(int x, int p);
        void Delete(int &x, int p);
        int Size();
        void Clear();
        void Retrieve(int &x, int p);
        void Replace(int x, int p);
    private:
        struct ListNode{
            int Entry;
            ListNode *NextNode;
        };
        typedef ListNode* ListPointer;

        int count;
        ListPointer head;
        void SetPosition(int p, ListPointer &current);
};