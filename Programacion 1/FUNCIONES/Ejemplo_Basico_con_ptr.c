#include <stdio.h>

// Declaración de la función para sumar dos valores por referencia
void sumar(int , int , int *);

int main() {
    int num1, num2, resultado;

    printf("Ingrese el primer número: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);

    // Llamada a la función sumar, pasando las direcciones de memoria de los números
    sumar(&num1, &num2, &resultado);

    printf("La suma es: %d\n", resultado);

    return 0;
}

// Definición de la función sumar
void sumar(int a, int b, int *resultado) {
    *resultado = a + b;
}
