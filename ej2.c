#include <stdio.h>

// Estos son los "rototipos"
int encontrarMinimo(int arr[], int size);
int encontrarMaximo(int arr[], int size);
void encontrarMinMax(int *arreglo, int *minimo, int *maximo, int longitud);

int main() {
    int arr[] = {21, 24, 65, 3, 56, 12, 35, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int minimo, maximo;

    // Llama la funcion para encontrar el minimo
    minimo = encontrarMinimo(arr, size);
    printf("El valor minimo en el arreglo es: %d\n", minimo);

    // Llama la funcion para encontrar el maximo
    maximo = encontrarMaximo(arr, size);
    printf("El valor maximo en el arreglo es: %d\n", maximo);

    // Llama la funcion para encontrar el minimo y maximo utilizando punteros
    encontrarMinMax(arr, &minimo, &maximo, size);
    printf("Usando punteros, el valor minimo es: %d y el valor maximo es: %d\n", minimo, maximo);

    return 0;
}

// Funcion para encontrar el valor minimo en el arreglo
int encontrarMinimo(int arr[], int size) {
    int minimo = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minimo) {
            minimo = arr[i];
        }
    }
    return minimo;
}

// Funcion para encontrar el valor maaximo en el arreglo
int encontrarMaximo(int arr[], int size) {
    int maximo = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maximo) {
            maximo = arr[i];
        }
    }
    return maximo;
}

// Función para encontrar los minimo y maximo usando punteros
void encontrarMinMax(int *arreglo, int *minimo, int *maximo, int longitud) {
    *minimo = arreglo[0];
    *maximo = arreglo[0];

    for (int i = 1; i < longitud; i++) {
        if (arreglo[i] < *minimo) {
            *minimo = arreglo[i];
        }
        if (arreglo[i] > *maximo) {
            *maximo = arreglo[i];
        }
    }
}