// Arquivo de definição da classe

class Stack{
    public:
        // metodos:
        Stack(); // construtor
        ~Stack(); // destrutor
        bool Full();
        bool Empty();
        void Push(int x);
        void Pop(int &x);
        int Size();
        void Clear();
        void Top(int &x);
    private:
        // campos de dados:
        struct StackNode{
            int Entry;
            StackNode *NextNode;
        };
        typedef StackNode *StackPointer;

        // declaração 
        StackPointer top;
        int size;
};