#include <stdio.h>

// Declaración de la función para sumar dos valores
int sumar(int a, int b);

int main() {
    int num1, num2, resultado;

    printf("Ingrese el primer número: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);

    // Llamada a la función sumar
    resultado = sumar(num1, num2);

    printf("La suma es: %d\n", resultado);

    return 0;
}

// Definición de la función sumar
int sumar(int a, int b) {
    return a + b;
}
