#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
/* Escribir una función que reciba como parámetro 
un vector de enteros y su tamaño y que calcule 
la suma de todos los elementos del vector. */

#define TAMANO_VECTOR 5

int Sumatoria(int[]);
void MostrarVector(int[]);
void CargarVector(int a[]);

int main()
{
    int vec[TAMANO_VECTOR];
    system("cls");
    CargarVector(vec);
    MostrarVector(vec);
    printf("\nla sumatoria del Vector fue:%d\n",Sumatoria(vec));
    return 0;
}
int Sumatoria(int a[])
{
    int i,s=0;
    for ( i = 0; i < TAMANO_VECTOR; i++)
    { 
        s+=a[i];
    }
    return s;
}
void CargarVector(int a[])
{
    int i;
    for ( i = 0; i < TAMANO_VECTOR; i++)
    { 
        printf("\nIngrese dato <%d> de <%d>:",i+1,TAMANO_VECTOR);
        scanf("%d",&a[i]);
    }
}
void MostrarVector(int a[])
{
    int i;
    for ( i = 0; i < TAMANO_VECTOR; i++)
    {
        printf("\nDato <%d>:%d",i+1,a[i]);
    }
}