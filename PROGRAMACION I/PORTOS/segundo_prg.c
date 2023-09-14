#include<stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int a;
    int b;
    int resultado;
    printf("Ingrese el 1er valor: ");
    scanf("%d", &a);
    printf("Ingrese el 2do valor: ");
    scanf("%d", &b);
    resultado = a+b;
    printf("%d + %d = %d\n",a,b,resultado);
    return 0;
}