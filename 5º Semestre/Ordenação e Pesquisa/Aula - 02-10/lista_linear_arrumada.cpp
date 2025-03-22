#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <ctime> // lib para medir o tempo com clock() e CLOCKS_PER_SEC
#include <iomanip> // lib para formatar a saida cout {fixed, setprecision}

using namespace std;
using namespace chrono;

int buscaLinear(const vector<string>& nomes, const string& chave){
    for(size_t i = 0; i < nomes.size(); i++){
        if (nomes[i] == chave){
            return static_cast<int>(i);
        }
    }
    return -1;
}

int main() {

        const char* arr[] = {
        "Gustavo Costa", "Fabiana Barbosa", "Igor Martins", "Natália Souza", "Bruno Martins", 
        "Otávio Lima", "Carlos Almeida", "Paula Silva", "Alice Lima", "Beatriz Lima", 
        "Beatriz Souza", "Helena Fernandes", "Marcos Almeida", "Daniel Barbosa", "Otávio Dias", 
        "Igor Barbosa", "Marcos Lima", "Eduardo Costa", "Eduardo Fernandes", "Fernanda Silva", 
        "Cecilia Azevedo", "Fernanda Lima", "Juliana Silva", "Larissa Almeida", "Beatriz Silva", 
        "Juliana Barbosa", "Amanda Martins", "Gustavo Barbosa", "Otávio Costa", "Larissa Martins", 
        "Paula Fernandes", "Marcos Dias", "Helena Lima", "Amanda Lima", "Gabriel Almeida", 
        "Carlos Dias", "Helena Costa", "Daniel Silva", "Fernanda Martins", "Marcos Barbosa", 
        "Otávio Barbosa", "Marcos Silva", "Larissa Silva", "Fernanda Fernandes", "Larissa Barbosa", 
        "Cecilia Silva", "Fernanda Souza", "Daniel Dias", "Cecilia Martins", "Eduardo Almeida", 
        "Juliana Almeida", "Fabiana Martins", "Igor Fernandes", "Amanda Fernandes", "Carlos Silva", 
        "Cecilia Souza", "Beatriz Dias", "Marcos Fernandes", "Amanda Barbosa", "Carlos Souza", 
        "Natália Costa", "Helena Silva", "Fabiana Almeida", "Amanda Souza", "Igor Dias", 
        "Amanda Almeida", "Bruno Souza", "Amanda Costa", "Eduardo Dias", "Gabriel Azevedo", 
        "Natália Silva", "Alice Martins", "Carlos Costa", "Alice Silva", "Natália Barbosa", 
        "Bruno Barbosa", "Paula Azevedo", "Bruno Dias", "Daniel Azevedo", "Paula Lima", 
        "Otávio Fernandes", "Larissa Souza", "Fabiana Souza", "Daniel Lima", "Fernanda Azevedo", 
        "Beatriz Almeida", "Fabiana Lima", "Cecilia Dias", "Juliana Souza", "Amanda Azevedo", 
        "Juliana Costa", "Alice Souza", "Fabiana Azevedo", "Igor Lima", "Cecilia Almeida", 
        "Fernanda Costa", "Natália Martins", "Gustavo Fernandes", "Fabiana Silva", "Fabiana Costa", 
        "Fernanda Almeida", "Gabriel Lima", "Beatriz Azevedo", "Cecilia Lima", "Larissa Lima", 
        "Carlos Fernandes", "Natália Almeida", "Alice Fernandes", "Eduardo Martins", "Paula Dias", 
        "Fabiana Fernandes", "Eduardo Souza", "Bruno Lima", "Gustavo Martins", "Alice Barbosa", 
        "Gabriel Costa", "Eduardo Barbosa", "Igor Souza", "Gustavo Lima", "Otávio Almeida", 
        "Beatriz Barbosa", "Natália Azevedo", "Juliana Fernandes", "Bruno Almeida", "Amanda Dias", 
        "Gustavo Souza", "Helena Barbosa", "Igor Almeida", "Cecilia Fernandes", "Helena Dias", 
        "Natália Fernandes", "Alice Costa", "Beatriz Costa", "Juliana Azevedo", "Igor Silva", 
        "Marcos Souza", "Carlos Lima", "Larissa Costa", "Paula Martins", "Paula Almeida", 
        "Daniel Costa", "Daniel Souza", "Daniel Almeida", "Otávio Martins", "Otávio Souza", 
        "Helena Souza", "Eduardo Silva", "Beatriz Martins", "Carlos Martins", "Fabiana Dias", 
        "Fernanda Barbosa", "Gustavo Silva", "Eduardo Lima", "Gabriel Silva", "Natália Dias", 
        "Marcos Azevedo", "Fernanda Dias", "Otávio Silva", "Gustavo Almeida", "Paula Barbosa", 
        "Helena Almeida", "Larissa Azevedo", "Marcos Martins", "Cecilia Costa", "Juliana Dias", 
        "Carlos Barbosa", "Gabriel Fernandes", "Igor Costa", "Bruno Silva", "Gabriel Barbosa", 
        "Daniel Martins", "Eduardo Azevedo", "Bruno Fernandes", "Alice Almeida", "Paula Souza", 
        "Alice Azevedo", "Cecilia Barbosa", "Natália Lima", "Juliana Lima", "Paula Costa", 
        "Larissa Fernandes", "Beatriz Fernandes", "Juliana Martins", "Larissa Dias", "Igor Azevedo", 
        "Marcos Costa", "Gustavo Dias", "Gabriel Martins", "Gustavo Azevedo", "Gabriel Souza", 
        "Daniel Fernandes", "Helena Martins", "Helena Azevedo", "Otávio Azevedo", "Alice Dias", 
        "Amanda Silva", "Bruno Azevedo", "Gabriel Dias", "Carlos Azevedo", "Bruno Costa"
    };

    // calcula o numero de elementos do array
    // sizeof(arr) retorna o tamanho total do array
    // sizeof(arr[0]) retorna o tamanho de apenas 1 elemento

    int n = sizeof(arr) / sizeof(arr[0]);
        vector<string> nomes(arr, arr + n);

    // solicita pro usuario a chave que vai ser procurada
    string chave;
    cout << "Busca Linear - Digite o nome a ser procurado: ";
    getline(cin, chave);


    auto inicio = high_resolution_clock::now();
    int indice = buscaLinear(nomes, chave);
    auto fim = high_resolution_clock::now();

    double duracao = duration<double, micro>(fim - inicio).count(); // Em microssegundos

    cout << fixed << setprecision(10);
    if (indice != -1)
        cout << "Busca Linear: " << chave << " encontrado no indice " << indice << "\n";
    else
        cout << "Busca Linear: " << chave << " não encontrado.\n";

    cout << "Tempo: " << duracao << " microssegundos.\n";

    return 0;
}
