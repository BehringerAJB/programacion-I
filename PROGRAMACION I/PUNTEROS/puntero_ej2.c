#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// manejo de punteros
void sumar(int,int,int*);
int main()
{
    int i, a, resultado=0;
    int *ptr;
    printf("Ingrese un valor de i:");
    scanf("%d", &i);
    printf("Ingrese un valor de a:");
    scanf("%d", &a);
    ptr=&resultado;
    sumar(i,a,ptr);
    printf("valor de la suma:%d\n",*ptr);
    printf("contenido de i=%d\n", i);
    printf("contenido de a=%d\n", a);
    printf("contenido de ptr=%d\n", *ptr);
    printf("direccion de a: %p\n", (void *)&a);
    printf("direccion de i: %p\n", (void *)&i);
    printf("direccion de ptr: %p\n", (void *)ptr);
    return 0;
    /*
    En C, void* es un tipo de puntero genérico. 
    Puede apuntar a cualquier tipo de dato, 
    ya sea un int, float, char, 
    o cualquier otro tipo. Cuando utilizamos %p 
    como formato de salida en la función printf, 
    estamos esperando un argumento que sea un puntero. 
    */
}
void sumar(int x, int y,int *r)
{
    *r=x+y;
}