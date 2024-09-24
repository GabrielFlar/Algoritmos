#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para intercambiar dos elementos
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función para particionar la lista
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Elegimos el último elemento como pivote
    int i = (low - 1);  // Índice del elemento más pequeño

    for (int j = low; j < high; j++) {
        // Si el elemento actual es menor o igual al pivote
        if (arr[j] <= pivot) {
            i++;  // Incrementa el índice del elemento más pequeño
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Función recursiva para implementar quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        // Particionamos la lista y obtenemos el índice del pivote
        int pi = partition(arr, low, high);

        // Ordenamos las sublistas recursivamente
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Función para imprimir el arreglo
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n = 9;  // El tamaño del array será siempre 9
    int arr[n];

    // Inicializamos el generador de números aleatorios
    srand(time(0));

    // Generamos números aleatorios y los almacenamos en el array
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;  // Genera números aleatorios entre 0 y 99
    }

    // Imprimir el array original
    printf("Array original: \n");
    printArray(arr, n);

    // Llamar a la función quicksort
    quicksort(arr, 0, n - 1);

    // Imprimir el array ordenado
    printf("Array ordenado: \n");
    printArray(arr, n);

    return 0;
}
