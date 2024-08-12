// Seção de Definições

#include <string>
using namespace std;

// declaração de tipo + Nome da classe
class Cap{
    // cabeçalhos dos metodos
    // modificador de acesso publico, para que os usuarios consigam utilizar
    public:
        // metodos ou funções
        void pressleft();
        void pressright();
        void Slots(string newLeft, string newRight);

    // modificador de acesso privado
    private:
        // campos de dados, variavies ou ATRIBUTOS
        string leftSlot;
        string rightSlot;
};