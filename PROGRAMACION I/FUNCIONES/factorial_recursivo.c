#include <stdio.h>

// Función para calcular el factorial
int factorial(int);

int main() {
    int numero;
    printf("Ingrese un número entero: ");
    scanf("%d", &numero);
    
    int resultado = factorial(numero);
    
    printf("El factorial de %d es %d\n", numero, resultado);
    
    return 0;
}
int factorial(int n) 
{
    if (n == 0 || n == 1) 
    {
        return 1;
    } 
    else 
    {
        return n * factorial(n - 1);
    }
}