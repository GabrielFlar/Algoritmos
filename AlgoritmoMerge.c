#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para fusionar dos subarreglos
void combinar(int v[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Crear arreglos temporales
    int L[n1], R[n2];

    // Copiar los datos a los arreglos temporales L[] y R[]
    for (i = 0; i < n1; i++)
        L[i] = v[l + i];
    for (j = 0; j < n2; j++)
        R[j] = v[m + 1 + j];

    // Fusionar los arreglos temporales de nuevo en v[l..r]
    i = 0; // Índice inicial del primer subarreglo
    j = 0; // Índice inicial del segundo subarreglo
    k = l; // Índice inicial del subarreglo fusionado
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si los hay
    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si los hay
    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}

// Función recursiva que implementa Merge Sort
void mergeSort(int v[], int l, int r) {
    if (l < r) {
        // Encuentra el punto medio
        int m = l + (r - l) / 2;

        // Ordena la primera y la segunda mitad
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);

        // Fusiona las mitades ordenadas
        combinar(v, l, m, r);
    }
}

int main() {
    int n = 9;  // Tamaño del vector
    int v[n];

    // Inicializamos el generador de números aleatorios
    srand(time(0));

    // Llenamos el vector con números aleatorios entre 0 y 99
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 100;
    }

    // Imprimir el vector original
    printf("Arreglo original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    // Llamada al algoritmo de Merge Sort
    mergeSort(v, 0, n - 1);

    // Imprimir el vector ordenado
    printf("Arreglo ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
