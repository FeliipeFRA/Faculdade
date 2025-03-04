// arquivo de definição da classe

class Cube{
    public:
        Cube(int size); //construtuor
        ~Cube(); //destrutor
        int Size();
        int Area();
        int Volume();
    private:
        int facesize;
        int area;
        int volume;
};