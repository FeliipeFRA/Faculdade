const int MaxList = 100;

class List{
    public:
        List();
        ~List();
        bool Empty();
        bool Full();
        void Insert(int x, int p); // x é o elemento, p é a posição
        void Delete(int &x, int p);
        int Size();
        void Clear();
        void Retrieve(int &x, int p);
        void Replace(int x, int p);
    private:
        int Entry[MaxList + 1];
        int count;
};