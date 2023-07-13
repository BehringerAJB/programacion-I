#include <stdio.h>
unsigned long long factorial(unsigned int );

int main() {
    unsigned int num;
    
    printf("Ingrese un número entero no negativo: ");
    scanf("%u", &num);
    
    unsigned long long fact = factorial(num);
    
    printf("El factorial de %u es: %llu\n", num, fact);
    
    return 0;
}

unsigned long long factorial(unsigned int n) {
    unsigned long long result = 1;
    
    while (n > 1) {
        result *= n;
        n--;
    }
    
    return result;
}