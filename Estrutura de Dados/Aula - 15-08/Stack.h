// Arquivo de definição
// Definir o tamanho máximo da pilha

const int MaxStackSize = 100;

class Stack{
    //* Metodos */
        // Construtor
        Stack();
        // Destruição
        ~Stack();
        // Status
        bool Full();
        bool Empty();
        // Operações básicas
        void Push(int x);
        void Pop(int &x);
        // Outras operaçoes (Clear, Top, Size)
        int Size();
        void Clear();
        void Top(int &x);
    //* Campos de dados */
    private:
        int entry[MaxStackSize+1];
        int top;

};