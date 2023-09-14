#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pausa(void);
void cargarMatriz(int **, int, int, int, int);
void mostrarMatriz(int **, int, int);
void cargarVector(int** , int*, int , int );
void ordenar(int [],int );
void cargarMatrizOrdenada(int **, int*, int, int);

int main()
{
    int fila, columna;
    int CotaSup = 200, CotaInf = 10;
    srand(time(NULL));

    printf("DEFINAMOS DE CUANTO QUEREMOS LA MATRIZ\n");
    printf("Por lo cual te pediremos las filas y las columnas\n\n");
    printf("Defina la cantidad de filas: ");
    scanf("%d", &fila);
    printf("Defina la cantidad de columnas: ");
    scanf("%d", &columna);
    int *Vector = (int*)malloc((fila*columna) * sizeof(int)); // este me va a servir para poder ordenar la matriz
    int **matriz = (int **)malloc(fila * sizeof(int *));
    for (int i = 0; i < fila; i++)
    {
        matriz[i] = (int *)malloc(columna * sizeof(int));
    }

    cargarMatriz(matriz, fila, columna, CotaInf, CotaSup);
    printf("Matriz:\n");
    mostrarMatriz(matriz, fila, columna);
    cargarVector(matriz , Vector, fila , columna );
    ordenar(Vector,fila*columna);
    cargarMatrizOrdenada(matriz,Vector,fila,columna);
    printf("\nMatriz ordenada:\n");
    mostrarMatriz(matriz, fila, columna);

    for (int i = 0; i < fila; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
    pausa();
    return 0;
}

void cargarMatriz(int **matriz, int fila, int columna, int cotaInf, int cotaSup)
{
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            matriz[i][j] = rand() % (cotaSup - cotaInf + 1) + cotaInf;
        }
    }
}
void cargarMatrizOrdenada(int **matriz,int *vec, int fila, int columna)
{
    int c=0;
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            matriz[i][j] = vec[c];
            c++;
        }
    }
}
void mostrarMatriz(int **matriz, int fila, int columna)
{
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void cargarVector(int** Matriz, int *vec, int fil, int col) 
{
    for (int i = 0; i < fil; ++i) {
        for (int j = 0; j < col; ++j) 
        {
           vec[i]=Matriz[i][j];
        }
    }
}

void pausa(void)
{
    printf("\nPresione Enter para continuar...");
    fflush(stdin);
    getchar();
}

void ordenar(int x[],int y)		
{		
	// y posse laa cantidad de valores a Ordenar
    int i,cota=y-1,k=1,aux;	// k es una bandera, que me indica que se termino de ordenar
	while(k)	
	{	
	        k=0;	// partimos del supuesto que esta ordenado
	        for(i=0;i<cota;i++)	
	        {	
	            if(x[i]>x[i+1])	
	            {	
	                // aqui se produce el swap
                    aux=x[i];	
	                x[i]=x[i+1];	
	                x[i+1]=aux;	
	                k=i;	// aqui k toma el valor donde fue ordenado por ultima vez
	            }	
	       }	
	cota=k;	// aqui se lo pasa a cota, con lo cual lo limita en las iteracioners
	}	
}	