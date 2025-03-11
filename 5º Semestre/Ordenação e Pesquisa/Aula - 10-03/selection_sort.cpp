/*
Selection sort
*/

#include <iostream>
#include <vector>

using namespace std;

// funçao para implementar o selection sort que ordena em ordem crescente
void selectionSort(vector<int>& arr){
    int n = arr.size(); // numero de elementos do vetor
    // laço externo: percorrer todas as posiçoes do vetor, exceto a última, já que após as iteraçoes os elementos restantes estarão ordenados
    for (int i = 0; i < n - 1; i++){
        int minIndex = i; // assume que o menor elemento esta na posição de 'i, posição inicial de execução
        // laço interno: procurar o menor elemento do subvetor arr[i+1] até arr[n-1]
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[minIndex]){
                // se encontrar um elemento menor que o atual, atualiza o inidice
                minIndex = j;
            }
        }
        // se o menor elemento não estiver na posição i, realiza a troca
        if (minIndex != i){
            int temp = arr[i];  // valor de arr[i] var temp
            arr[i] = arr[minIndex]; // move o menor elemento para a posiçao do i
            arr[minIndex] = temp; // colocar o valor antigo de arr[i] no lugar do menor encontrado
        }
    }
}

int main(){
    // vetor de inteiros que será ordenado
    vector<int> arr = {64, 25, 12, 22, 11, 99, 27, 1, 4};

    //
}
