#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// Ejercicio 1 del Power Point de Punteros
// manejo de punteros, Intercambio de valores
void intercambio(int *, int *);

int main() 
{
    int num1, num2;
    printf("Ingrese el valor 1: ");
    scanf("%d", &num1);
    printf("Ingrese el valor 2: ");
    scanf("%d", &num2);
    printf("Valores originales: num1 = %d, num2 = %d\n", num1, num2);
    // Llamando a la función intercambio para intercambiar los valores
    intercambio(&num1, &num2);
    printf("Valores intercambiados: num1 = %d, num2 = %d\n", num1, num2);
    return 0;
}

// Función para intercambiar dos valores usando referencias
void intercambio(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}