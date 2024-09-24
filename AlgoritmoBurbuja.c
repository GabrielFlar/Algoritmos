#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenar(int v[], int n) {
    int aux;
    
    // Implementación del algoritmo de la burbuja
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (v[j - 1] > v[j]) {
                aux = v[j - 1];
                v[j - 1] = v[j];
                v[j] = aux;
            }
        }
    }
}

int main() {
    int n = 9; // Tamaño del vector
    int v[n];  // Vector de tamaño 9

    // Inicializamos el generador de números aleatorios
    srand(time(0));

    // Llenamos el vector con números aleatorios entre 0 y 99
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 100;
    }

    // Imprimir el vector original
    printf("Vector original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    // Llamada al algoritmo de ordenación (burbuja)
    ordenar(v, n);

    // Imprimir el vector ordenado
    printf("Vector ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
