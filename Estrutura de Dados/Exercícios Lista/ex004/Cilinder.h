class Cilinder{
    public:
        Cilinder(float h, float r);

        ~Cilinder();

        float Height(){
            return height;
        }

        float Radius(){
            return radius;
        }

        float Area(){
            return area;
        }

        float Volume(){
            return volume;
        }

    private:
        float height;
        float radius;
        float area;
        float volume;
};