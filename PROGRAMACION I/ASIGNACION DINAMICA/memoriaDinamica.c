#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define n 50      // es una variable
#define p printf
#define s scanf

void cargaVector(int[], int);
int cuentaPrimos(int[], int);
int* buscaPrimos(int[], int, int*);
void mostrarVector(int[], int, char *);
void pausa(void);

int main()
{
    int vec1[n], cantprimos = 0;
    int* Vecprimos = NULL; // esto es porque asignare memoria dinamica

    srand(time(NULL));
    cargaVector(vec1, n);
    cantprimos=cuentaPrimos(vec1, n);
    mostrarVector(vec1, n, "El Vector original");
    pausa();

    Vecprimos = buscaPrimos(vec1, n, &cantprimos);

    mostrarVector(Vecprimos, cantprimos, "Numeros Primos");
    p("La cantidad de numeros primos que tiene el vector es %d\n", cantprimos);

    free(Vecprimos);
    // Liberamos la memoria asignada para el vector de primos
    pausa();
    p("Presione cualquier tecla para continuar");
}

void cargaVector(int x[], int y)
{
    int i, num;
    int cs = 100, ci = 1;
    for (i = 0; i < y; i++)
    {
        x[i] = rand() % (cs - ci + 1) + ci;
    }
}

int* buscaPrimos(int x[], int y, int* numPrimos)
{
    int i, j, z = 0, cont = 0;
    int* primos = (int*)malloc(*numPrimos * sizeof(int));
    // Asignar memoria para el vector de primos
    if (primos == NULL)
    {
        perror("Error en la asignación de memoria.");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < y; i++)
    {
        cont = 0;
        for (j = 1; j <= x[i]; j++)
        {
            if (x[i] % j == 0)
            {
                cont++;
            }
        }
        if (cont == 2)
        {
            primos[z] = x[i];
            z++;
        }
    }

    *numPrimos = z; // Actualizamos la cantidad de números primos encontrados
    return primos;
}

void mostrarVector(int x[], int y, char* msj)
{
    int i,c=1;
    printf("\n%s\n", msj);
    for (i = 0; i < y; i++)
    {
        p("%3d",x[i]);
        if(c%10==0)
        {
            printf("\n");
            c=0;
        }
        c++;
    }
    printf("\n\n");
}
int cuentaPrimos(int x[], int y)
{
    int i, j, cont = 0, contprimo = 0;
    for (i = 0; i < y; i++)
    {
        cont = 0;
        for (j = 1; j <= x[i]; j++)
        {
            if (x[i] % j == 0)
            {
                cont++;
            }
        }
        if (cont == 2)
        {
            contprimo++;
        }
    }
    return contprimo;
}

void pausa(void)
{
    printf("\n\nPresione Enter para continuar...\n\n");
    fflush(stdin);
    getchar();
}

