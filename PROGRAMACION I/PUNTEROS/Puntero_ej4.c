/*
Dado un vector de 10 posiciones, 
se necesita generar una función, 
que cargue el mismo, con valores aleatorios entre 25 y 75, 
utilizando aritmética de punteros, por último, 
realizar una función que los muestre de la misma manera

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void CargarVector(int[]);
void ListarVector(int[]);

int main()
{
    int vec[10];
    srand(time(NULL));
    CargarVector(vec);
    ListarVector(vec);
    return 0;
}
void CargarVector(int x[])
{
    int i,Cs=75,Ci=25;
    for ( i = 0; i < 10; i++)
    {
        *(x+i)=rand()%(Cs-Ci+1)+Ci;
    }   
}
void ListarVector(int x[])
{
     int i;
    for ( i = 0; i < 10; i++)
    {
        printf("Direccion:0&%p\tValor de Vec[%d]=%d\n",(void*)x+i,i,*(x+i));
    }   
}