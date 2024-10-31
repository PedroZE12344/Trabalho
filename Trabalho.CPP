#include <iostream>
using namespace std;

const int MAX_TAMANHO = 100;// Define o tamanho máximo do vetor que vc pode escolher

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++)
        cout << array[i] << " "; // Imprime cada elemento
    cout << endl; 
}

void insertionSort(int array[], int n) {// Função para ordenar o vetor usando Insertion Sort
    for (int i = 1; i < n; i++) { 
        int key = array[i]; 
        int j = i - 1; 
        
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key; 
    }
}

void selectionSort(int array[], int n) {// Aqui para  Selection Sort
    for (int i = 0; i < n - 1; i++) { 
        int minIndex = i; 
        for (int j = i + 1; j < n; j++) { 
            if (array[j] < array[minIndex]) {
                minIndex = j; 
            }
        }
        swap(array[i], array[minIndex]); 
    }
}

void bubbleSort(int array[], int n) {// Aqui para Bubble Sort
    for (int i = 0; i < n - 1; i++) { 
        for (int j = 0; j < n - i - 1; j++) { // Compara elementos adjacentes
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]); 
            }
        }
    }
}

int main() {
    int vetor[MAX_TAMANHO]; 
    int n; 

    
    cout << "Digite a quantidade de elementos (1 a " << MAX_TAMANHO << "): ";// Solicita ao usuário a quantidade de elementos, por exemplo 20, 30, 40, etc
    cin >> n;
    
    if (n < 1 || n > MAX_TAMANHO) {// Verifica se a quantidade é válida ou inválida
        cout << "Quantidade está inválida!" << endl;
        return 1; // Essa é a saido com erro se caso  estiver errada a quantidade, por exemplo um numero menor que zero
    }

    cout << "Digite os elementos:" << endl; // Indica  ao usuário para inserir os elementos do vetor
    for (int i = 0; i < n; i++) {
        cin >> vetor[i]; 
    }

    
    cout << "Array original: ";
    printArray(vetor, n);

    if (n >= 1 && n <= 20) {
        insertionSort(vetor, n); // Usa Insertion Sort
        cout << "Insertion Sort: ";
    } else if (n >= 21 && n <= 30) {
        bubbleSort(vetor, n); // Usa Bubble Sort
        cout << "Bubble Sort: ";
    } else {
        selectionSort(vetor, n); // Usa Selection Sort
        cout << "Selection Sort: ";
    }

    printArray(vetor, n);

    return 0; // Finaliza o programa aqui
}