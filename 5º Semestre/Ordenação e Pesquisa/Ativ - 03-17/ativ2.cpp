// FELIPE FERREIRA - 2208490

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip> // setprecision
#include <cstdlib> // lib para uso da func atof (convert string - double)
#include <chrono>  // lib para medir o tempo de forma mais precisa

using namespace std;
using namespace chrono;

vector<string> nomes1 = {
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

vector<string> nomes2 = nomes1;


const string GREEN = "\033[1;32m";
const string RESET = "\033[0m"; // Reseta a cor para padrão

void insertionSort (vector<string>& arr);
void mergeSort (vector<string>& vetor, int inicio, int fim);
void merge(vector<string>& vetor, int inicio, int meio, int fim);


int main() {
    cout << "-------------------------------------------------------------------------------------------------------------\n" << RESET;
        cout << GREEN << "VETOR DE " << nomes1.size() << " ELEMENTOS" << RESET << endl;
        
        auto inicio_insertion = high_resolution_clock::now(); // ligar cronometro
        insertionSort(nomes1);
        auto fim_insertion = high_resolution_clock::now(); // desligar cronometro
        double tempo_insertion = duration<double, ratio<1,1>>(fim_insertion - inicio_insertion).count();
        
        cout << GREEN << "- " << RESET << "TEMPO INSERTION SORT: " << GREEN << tempo_insertion << " segundos." << RESET << endl;

        auto inicio_merge = high_resolution_clock::now(); // ligar cronometro
        mergeSort(nomes2, 0, nomes2.size() - 1);
        auto fim_merge = high_resolution_clock::now(); // desligar cronometro
        double tempo_merge = duration<double, ratio<1,1>>(fim_merge - inicio_merge).count();

        cout << GREEN << "- " << RESET << "TEMPO MERGE SORT: " << GREEN << tempo_merge << " segundos." << RESET << endl;


    return 0;
}



void insertionSort (vector<string>& arr){
    int n = arr.size();
    for (int i = 1; i < n; i++){
        string key = arr[i];
        int j = i - 1; // 'j'inicia no último elemento já ordenado
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j]; // desloca o elemento para a direita
            j--; // move o j para o elemento anterior
        }
        arr[j + 1] = key; // insere key na posição correta dento da parte ordenada
    }
}


void merge(vector<string>& vetor, int inicio, int meio, int fim){
    // calcular o numero de elementos na primeira metade (esquerda)
    int n1= meio - inicio + 1;

    // calcula o num de elementos na metade da direita
    int n2 = fim - meio;

    // cria vetores temporários para armazenar as duas metades
    vector<string> esquerda(n1), direita(n2);

    // copiar os elementos da primeira metade do vetor original para o vetor esquerda
    for(int i = 0; i < n1; i++){
        esquerda[i] = vetor[inicio + i];
        // 'vetor[inicio + i]' percorre os elementos do sub vetor esquerdo
    }
    // elementos direita
    for (int j = 0; j < n2; j++){
        direita[j] = vetor[meio + 1 + j];
    }

    // inicializa os indices para percorrer os vetores temporarios
    int i = 0; // esquerda
    int j = 0; // direita
    int k = inicio; // indice para inserir os elementos no vetor original

    // while para enquanto houver elementos em ambos vetores temporários continua comparando
    while (i < n1 && j < n2) {
        // se o elemento da esquerda é menor ou igual ao elemento da direita
        if (esquerda[i] <= direita[j]){
            vetor[k] = esquerda[i]; // vetor recebe o elemento da esquerda já ordenado
            i++; // avança o prox da esquerda
        } else {
            vetor [k] = direita[j]; // vetor recebe o elemento da direita
            j++; // avança o prox da direita
        }
        k++; // avança para a proxima posição do vetor
    }

    // se ainda restarem elementos no vetor da esquerda, desce
    while(i < n1) {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    // mesma coisa se sobrar elementos na direita
    while(j < n2){
        vetor[k] = direita[j];
        j++;
        k++;
    }
}


void mergeSort(vector<string>& vetor, int inicio, int fim) {
    
    // Se o subvetor tem mais de um elemento
    if (inicio < fim) {
        // Calcula o índice do meio para dividir o vetor
        int meio = inicio + (fim - inicio) / 2;
        
        // Ordena recursivamente a primeira metade
        mergeSort(vetor, inicio, meio);
        
        // Ordena recursivamente a segunda metade
        mergeSort(vetor, meio + 1, fim);
        
        // Mescla as duas metades ordenadas
        merge(vetor, inicio, meio, fim);
    }
}