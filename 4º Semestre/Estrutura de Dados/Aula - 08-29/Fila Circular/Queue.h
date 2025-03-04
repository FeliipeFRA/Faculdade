// Arquivo de definição da classe
const int MaxQueue = 100;
class Queue{
public:
    Queue();
    ~Queue();
    bool Full();
    bool Empty();
    void Append(int x); // metodo de inserção na fila
    void Serve(int &x); // metodo de remoção da fila
    void Front(int &x); // copia do elemento que está em head
    void Rear(int &x); // copia do elemento que está em tail
    int Size();
    void Clear();
private:
    int count;
    int head;
    int tail;
    int Entry[MaxQueue + 1];
};