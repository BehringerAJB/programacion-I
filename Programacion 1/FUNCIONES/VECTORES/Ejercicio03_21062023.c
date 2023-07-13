#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define TAMANO_VECTOR 50
/* Escribir una función que reciba como parámetro
un vector de enteros con 50 valores cargados
 al azar entre 10 y 20. Determine
  cuantas veces se repite el mayor */
void CargarVector(int[]);
void MostrarVector(int[]);
int Mayor(int[]);
int repiteMayor(int, int[]);

int main()
{
    int vec[TAMANO_VECTOR];
    int may;
    srand(time(NULL));
    // Inicializar el vector con valores
    CargarVector(vec);
    // Imprimir el vector
    may=Mayor(vec);
    MostrarVector(vec);
    printf("\n\n El mayor fue:%d\n",may);
    printf("\n\ny el %d se repite:%d\n",may, repiteMayor(may, vec));
    return 0;
}
void CargarVector(int x[])
{
    int i;
    for (i = 0; i < TAMANO_VECTOR; i++)
    {
        x[i] = rand() % (20 - 10 + 1) + 10;
    }
}
void MostrarVector(int a[])
{
    int i;
    for (i = 0; i < TAMANO_VECTOR; i++)
    {
        printf("\nDato <%d>:%d", i + 1, a[i]);
    }
}
int Mayor(int x[])
{
    int i, may;
    may = x[0];

    for (i = 1; i < TAMANO_VECTOR; i++)
    {
        if (x[i] > may)
            may = x[i];
    }
    return may;
}
int repiteMayor(int x, int y[])
{
    int i, cont = 0;

    for (i = 0; i < TAMANO_VECTOR; i++)
    {
        if (x == y[i])
            cont++;
    }
    return cont;
}