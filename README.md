# Trabalho C++: Lista Ordenada

**Aluno:** Pedro Henrique  
**Turno:** Noite

Este código em C++ implementa três algoritmos de ordenação: **Insertion Sort**, **Bubble Sort** e **Selection Sort**, permitindo ao usuário inserir um vetor de inteiros que será ordenado.

## Descrição do Código

O programa começa incluindo a biblioteca padrão de entrada e saída, permitindo o uso de `cout` e `cin`. Em seguida, define uma constante que estabelece um tamanho máximo para o vetor, limitando a entrada a 100 elementos.

### Funções Implementadas

- **printArray**: 
  - Responsável por imprimir os elementos do vetor. 
  - Recebe o vetor e o número de elementos como parâmetros e exibe cada elemento em sequência.

- **insertionSort**: 
  - Implementa o algoritmo Insertion Sort. 
  - Percorre o vetor, pega um elemento (chave) e o insere na posição correta dentro de uma sublista já ordenada.

- **selectionSort**: 
  - Funciona encontrando repetidamente o menor elemento na parte não ordenada do vetor e trocando-o com o primeiro elemento dessa parte.

- **bubbleSort**: 
  - Compara pares de elementos adjacentes, trocando-os se estiverem na ordem errada.
  - Repete esse processo até que o vetor fique ordenado.

### Função Principal

Na função principal, o programa solicita ao usuário que informe quantos elementos deseja inserir e, após receber a entrada, verifica se o número está dentro do intervalo permitido (1 a 100).

O usuário então insere os elementos do vetor, que são impressos na tela. Dependendo do número de elementos, o programa decide qual algoritmo de ordenação utilizar:

- Para **1 a 20** elementos, usa **Insertion Sort**.
- Para **21 a 30** elementos, usa **Bubble Sort**.
- Para **31 a 100** elementos, usa **Selection Sort**.

Por fim, o vetor ordenado é impresso.

## Código Fonte

```cpp
#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// Função para imprimir o vetor
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Função para Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Função para Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Função para Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Função principal
int main() {
    int n;
    int arr[MAX_SIZE];

    cout << "Quantos elementos deseja inserir? (1 a 100): ";
    cin >> n;

    if (n < 1 || n > MAX_SIZE) {
        cout << "Número de elementos fora do intervalo permitido." << endl;
        return 1;
    }

    cout << "Insira os elementos do vetor:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Vetor original: ";
    printArray(arr, n);

    // Escolha do algoritmo de ordenação
    if (n <= 20) {
        insertionSort(arr, n);
    } else if (n <= 30) {
        bubbleSort(arr, n);
    } else {
        selectionSort(arr, n);
    }

    cout << "Vetor ordenado: ";
    printArray(arr, n);

    return 0;
}
