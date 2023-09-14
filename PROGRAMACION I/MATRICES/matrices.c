/*
10. Desarrollar un algoritmo que ingrese un matriz de n x m, y luego muestre por
pantalla la cantidad de ceros que contiene, crear una funci�n para tal fin.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void CargarMatriz(int [][N], int , int );
void MostrarMatriz(int [][N], int , int );
int ContarCeros(int [][N], int , int );
int ContarCerosDiagPrin(int [][N], int , int );
int ContarCerosDiagSec(int [][N], int , int );

int main(){
	int fil,col;
	int matriz[N][N];
    int ceros;

    srand(time(NULL)); // semilla aleatoria
	do
    {
        printf("Ingrese un valor para n(filas): ");
        scanf("%d", &fil);
    }while(fil<0 || fil>N);

	do
    {

        printf("Ingrese un valor para m(columnas): ");
        scanf("%d", &col);
    }while(col<0 || col>N);
    
    CargarMatriz(matriz,fil,col);
    MostrarMatriz(matriz,fil,col);

    ceros = ContarCeros(matriz, fil, col);
    printf("\n\nCantidad de ceros en la matriz: %d\n", ceros);

    printf("\n\nCantidad de ceros en la diagonal principal de la matriz: %d\n", ContarCerosDiagPrin(matriz, fil, col));

    printf("\n\nCantidad de ceros de la diagonal secundaria de la  matriz: %d\n", ContarCerosDiagSec(matriz, fil, col));
	return 0;
}
// Funci�n para contar ceros en una matriz
void CargarMatriz(int matriz[][N], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matriz[i][j] = rand()%5;
        }
    }
}
void MostrarMatriz(int matriz[][N], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%3d",matriz[i][j]);
        }
        printf("\n");
    }
}

int ContarCeros(int matriz[][N], int n, int m)
{
    int ceros=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(matriz[i][j] == 0)
                ceros++;
        }
    }
    return ceros;
}

int ContarCerosDiagPrin(int matriz[][N], int fil, int col)
{
    int ceros=0;
    for (int i = 0; i < fil; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(j == i && matriz[i][j] == 0)
                ceros++;
        }
    }
    return ceros;
}
int ContarCerosDiagSec(int matriz[][N], int fil, int col)
{
    int ceros=0;
    for (int i = 0; i < fil; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(j == col-1 && matriz[i][j] == 0)
                ceros++;
        }
        col--;
    }
    return ceros;
}
