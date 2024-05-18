#include <stdio.h>

#define SIZE 6

// EStos son los prototipos 
int busquedaLineal(int arr[], int size, int valor);
int busquedaBinaria(int arr[], int size, int valor);
int busquedaBinariaRecursiva(int arr[], int izquierda, int derecha, int valor);

int main() {
    int arr[SIZE] = {2, 4, 6, 23, 56, 79};
    int valor;

    printf("Ingrese un valor entero: ");
    scanf("%d", &valor);

    // Realiza una busqueda lineal
    int posLineal = busquedaLineal(arr, SIZE, valor);
    if (posLineal != -1) {
        printf("Busqueda Lineal: El valor %d se encuentra en la posicion %d del arreglo.\n", valor, posLineal);
    } else {
        printf("Busqueda Lineal: El valor %d no fue encontrado en el arreglo.\n", valor);
    }

    // Realiza una busqueda binaria iterativa
    int posBinaria = busquedaBinaria(arr, SIZE, valor);
    if (posBinaria != -1) {
        printf("Busqueda Binaria Iterativa: El valor %d se encuentra en la posicion %d del arreglo.\n", valor, posBinaria);
    } else {
        printf("Busqueda Binaria Iterativa: El valor %d no fue encontrado en el arreglo.\n", valor);
    }

    // Realiza una busqueda binaria recursiva
    int posBinariaRec = busquedaBinariaRecursiva(arr, 0, SIZE - 1, valor);
    if (posBinariaRec != -1) {
        printf("Busqueda Binaria Recursiva: El valor %d se encuentra en la posicion %d del arreglo.\n", valor, posBinariaRec);
    } else {
        printf("Busqueda Binaria Recursiva: El valor %d no fue encontrado en el arreglo.\n", valor);
    }

    return 0;
}

// Funcion para la búsqueda lineal
int busquedaLineal(int arr[], int size, int valor) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == valor) {
            return i;
        }
    }
    return -1;
}

// Funcion para la busqueda binaria iterativa
int busquedaBinaria(int arr[], int size, int valor) {
    int izquierda = 0;
    int derecha = size - 1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (arr[medio] == valor) {
            return medio;
        } else if (arr[medio] < valor) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }
    return -1;
}

// Funcion para la busqueda binaria recursiva
int busquedaBinariaRecursiva(int arr[], int izquierda, int derecha, int valor) {
    if (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (arr[medio] == valor) {
            return medio;
        } else if (arr[medio] < valor) {
            return busquedaBinariaRecursiva(arr, medio + 1, derecha, valor);
        } else {
            return busquedaBinariaRecursiva(arr, izquierda, medio - 1, valor);
        }
    }
    return -1;
}