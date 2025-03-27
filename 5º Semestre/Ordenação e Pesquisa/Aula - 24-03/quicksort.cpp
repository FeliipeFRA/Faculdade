/*
Quick Sort

O que é Quick Sort?

Quick Sort é um algoritmo de ordenação eficiente que utiliza o paradigma divisão e conquista. Seu funcionamento básico é o seguinte:

1.	Escolha de um Pivô:
Um elemento do vetor é escolhido como pivô. Esse pivô serve para particionar o vetor.

2.	Particionamento:
O vetor é reorganizado de modo que todos os elementos menores que o pivô fiquem à sua esquerda e todos os elementos maiores fiquem à sua direita. Após essa etapa, o pivô estará na sua posição final ordenada.

3.	Divisão e Conquista:
Em seguida, o algoritmo recursivamente aplica o mesmo processo às sublistas à esquerda e à direita do pivô.

Diferenças entre Quick Sort e Merge Sort

•	Espaço Adicional:
    o	Quick Sort: Geralmente é um algoritmo in-place, ou seja, ordena os elementos no próprio vetor sem a necessidade de espaço extra significativo.
    o	Merge Sort: Requer espaço adicional proporcional ao tamanho da entrada para armazenar os subvetores temporários durante a mesclagem.

•	Desempenho no Pior Caso:
    o	Quick Sort: Tem tempo de execução médio de O(n log ⁡n), mas no pior caso pode atingir O(n^2) (por exemplo, se o pivô for escolhido de forma desfavorável).
    o	Merge Sort: Garante O(n log ⁡n) no melhor, pior e caso médio.

•	Estabilidade:
    o	Merge Sort: É um algoritmo estável, ou seja, mantém a ordem relativa de elementos iguais.
    o	Quick Sort: Em sua forma clássica, não é estável (embora variações estáveis existam).

*/

#include <iostream>     // Para entrada e saída (cout, cin)
#include <vector>       // Para usar o container vector
#include <ctime>        // Para medir o tempo com clock() e CLOCKS_PER_SEC
#include <iomanip>      // Para formatar a saída (fixed, setprecision)

using namespace std;

// Função de particionamento: reorganiza o vetor de forma que os elementos menores que o pivô
// fiquem à esquerda e os maiores, à direita. Retorna o índice final do pivô.
int partition(vector<int>& vetor, int low, int high) {
    int pivot = vetor[high]; // Escolhe o último elemento como pivô.
    int i = low - 1;         // 'i' marcará a posição onde os elementos menores que o pivô serão colocados.

    // Percorre o vetor de 'low' até 'high - 1'
    for (int j = low; j < high; j++) {
        // Se o elemento atual for menor ou igual ao pivô, incrementa 'i' e troca os elementos.
        if (vetor[j] <= pivot) {
            i++; // Incrementa o índice para os elementos menores que o pivô.
            // Troca vetor[i] com vetor[j]
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }
    // Coloca o pivô na posição correta (após todos os elementos menores que ele)
    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[high];
    vetor[high] = temp;
    return i + 1; // Retorna a posição do pivô
}

// Função Quick Sort: ordena o vetor 'vetor' no intervalo [low, high] usando recursão.
void quickSort(vector<int>& vetor, int low, int high) {
    if (low < high) {  // Se houver pelo menos dois elementos no intervalo
        // Particiona o vetor e obtém o índice do pivô na posição correta
        int pi = partition(vetor, low, high);
        
        // Recursivamente, ordena os elementos antes do pivô
        quickSort(vetor, low, pi - 1);
        // Recursivamente, ordena os elementos depois do pivô
        quickSort(vetor, pi + 1, high);
    }
}

int main() {
    // Exemplo de vetor de inteiros a ser ordenado com Quick Sort
    vector<int> vetor = {9, 2, 18, 47, 8, 1};

    // Exibe o vetor original
    cout << "Vetor original: ";
    for (size_t i = 0; i < vetor.size(); i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;

    // Mede o tempo de execução do Quick Sort
    clock_t inicio = clock();
    quickSort(vetor, 0, vetor.size() - 1);
    clock_t fim = clock();
    double tempoExecucao = double(fim - inicio) / CLOCKS_PER_SEC;

    // Exibe o vetor ordenado
    cout << "Vetor ordenado: ";
    for (size_t i = 0; i < vetor.size(); i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;

    // Exibe o tempo de execução formatado com 6 casas decimais
    cout << "Tempo de execucao do Quick Sort: " << fixed << setprecision(6)
        << tempoExecucao << " segundos." << endl;

    return 0;
}
