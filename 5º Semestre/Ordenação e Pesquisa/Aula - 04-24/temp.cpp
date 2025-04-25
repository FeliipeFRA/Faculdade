#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

// função heapify
// 1. Determina o maior elemento
// 2. Realiza a troca recursiva
// Parâmetros
//  arr - vetor
//  n - tamanho do heap
//  i - indice do elemento
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;  // inicialmente assume que o elemento raiz é o maior
    int left = 2 * i + 1; // indice do filho à esquerda.
    int right = 2 * i + 2; // indice do filho à direita.

    // se o filho à esquerda existe e for maior que o elemento atual, atualiza 'largest'
    if (left < n && arr[left] > arr[largest])
        largest = left;
    // se o filho à direita existe e é maior, atualiza 'largest'
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    // se o maior elemento não é o nó troca
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        // chamada recursiva
        heapify(arr, n, largest);
    }
}

// função heapsort
// 1. construção do heap
// 2. Troca do primeiro com o último
// 3. Redução do Heap
void heapSort(vector<int>& arr){
    int n = arr.size();

    // realiza a construção do max heap
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i); 
    }

    // inverte e extrai o elemento do heap
    for (int i = n - 1; i >= 0; i--){
        // move o maior elemento (a raiz) para o inicio
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main() {
    // exemplo de vetor a ser ordenado
    vector<int> arr = {9, 2, 18, 47, 8, 1};

    // exibe o vetor original
    cout << "Vetor Original: ";
    for(size_t i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    // mede o tempo de execução e chama a função
    clock_t inicio = clock();
    heapSort(arr);
    clock_t fim = clock();
    double tempoExecucao = double(fim - inicio) / CLOCKS_PER_SEC;

    // exibe o vetor ordenado
    cout << "Vetor ordenado: ";
    for(size_t i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
// exibe o tempo de execuçao
cout << "Tempo: " << fixed << setprecision(6) 
    << tempoExecucao << " segundos. " << endl;

    return 0;
}