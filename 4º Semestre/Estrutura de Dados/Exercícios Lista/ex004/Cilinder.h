class Cilinder{
    public:
        Cilinder(float h, float r);
        ~Cilinder();
        float Height();
        float Radius();
        float Area();
        float Volume();
    private:
        float height;
        float radius;
        float area;
        float volume;
};