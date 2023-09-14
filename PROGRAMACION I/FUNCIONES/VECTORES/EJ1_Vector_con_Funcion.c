#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define TAMANO_VECTOR 5

void CargarVector(int[]);
void MostrarVector(int[]);

int main()
{
    int vec[TAMANO_VECTOR];
    system("cls");
    CargarVector(vec);
    MostrarVector(vec);
    return 0;
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