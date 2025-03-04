// Arquivo de definição

class Queue{
    public:
        Queue();
        ~Queue();
        bool Empty();
        // bool Full(); <- Memória cheia
        void Append(int x);
        void Serve(int &x);
        void Clear();
        int Size();
        void Front(int &x);
        void Rear(int &x);
    private:
        struct QueueNode{
            int Entry;
            QueueNode *NextNode;
        };
        typedef QueueNode* QueuePointer;
        QueuePointer head;
        QueuePointer tail;
        int count;
};