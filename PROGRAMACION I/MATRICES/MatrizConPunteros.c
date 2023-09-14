#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pausa(void);
void cargarMatriz(int **, int , int , int , int );
void mostrarMatriz(int **, int , int );
void mostrarMatrizPuntero(int **, int , int );

int main()
{
    int fila, columna;
    int CotaSup = 200, CotaInf = 10;
    srand(time(NULL)); // Semilla Aleatoria

    printf("DEFINAMOS DE CUANTO QUEREMOS LA MATRIZ\n");
    printf("Por lo cual te pediremos las filas y las columnas\n\n");
    printf("Defina la cantidad de filas: ");
    scanf("%d", &fila);
    printf("Defina la cantidad de columnas: ");
    scanf("%d", &columna);

    // Reserva de memoria para la matriz
    int **matriz = (int **)malloc(fila * sizeof(int *));

    // Rellenamos los espacios de Memoria
    // segun lo pedido por el usuario para la matriz
    for (int i = 0; i < fila; i++)
    {
        matriz[i] = (int *)malloc(columna * sizeof(int));
    }
    cargarMatriz(matriz, fila, columna, CotaInf, CotaSup);

    // Mostrar la matriz original
    printf("\nMatriz Normal:\n");
    mostrarMatriz(matriz, fila, columna);
    printf("\nMatriz Con recorrido de Puntero:\n");
    mostrarMatrizPuntero(matriz, fila, columna);
    // Liberar la memoria al finalizar
    printf("\n\nEstamos por liberar la memoria Dinamica que generamos\n");
    printf("OjO - Se borrara la Matriz Original - OjO\n");
    pausa();
    printf("Liberamos Matriz Original !!\n");
    for (int i = 0; i < fila; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
    printf("\n\nMemoria Dinamica Liberada!!!!\n");
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
void pausa(void)
{
    printf("\nPresione Enter para continuar...");
    fflush(stdin);
    getchar();
}
void mostrarMatrizPuntero(int **matriz, int fila, int columna)
{
    int *filaActual;

    for (int i = 0; i < fila; i++)
    {
        filaActual = matriz[i];
        for (int j = 0; j < columna; j++)
        {
            printf("%4d ", *filaActual++);
        }
        printf("\n");
    }
}