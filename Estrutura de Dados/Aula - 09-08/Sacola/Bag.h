#include <string>
using namespace std;

const int Capacity = 20;

class Bag {
    public:
        Bag(); // ???? construtor para adt
        void Insert(int num);
        int Occurence(int num);
        void Remove(int num);
        bool Full();
    private:
        int Nums[Capacity+1];
        int Quantity = 0;
};