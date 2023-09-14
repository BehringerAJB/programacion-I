#include <stdio.h>
#include <stdlib.h>
#include<time.h> // esto es necesario para trabajar el aleatorio, porque se usa el tiempo

void pausa(void);

int main()
{
    int fila, columna;
    int CotaSup=200, CotaInf=10; 
    // esto me da los limites en los que 
    // genero las cotas para generar aleatorios, o sea entre 10 y 200

    srand(time(NULL)); // semilla aleatoria, SIN esto no genera aleatorios
    printf("DEFINAMOS DE CUANTO QUEREMOS LA MATRIZ\n");
    printf("Por lo cual te pediremos las filas y las columnas\n\n");
    printf("Defina la cantidad de filas: ");
    scanf("%d", &fila);
    printf("Defina la cantidad de columnas: ");
    scanf("%d", &columna);

    // Reserva de memoria para la matriz
    int **matriz = (int **)malloc(fila * sizeof(int *));

    // Rellenamos los  espacios de Memoria
    // segun lo pedido por el usuario para la matriz
    for (int i = 0; i < fila; i++)
    {
        matriz[i] = (int *)malloc(columna * sizeof(int));
    }

    // Inicialización de la matriz con valores
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            matriz[i][j] = rand()%(CotaSup-CotaInf+1)+CotaInf; 
            // inicializa con el valor que desees
            // en mi caso voy a utilizar numeros aleatorios
        }
    }

    // Mostrar la matriz
    printf("Matriz:\n");
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberar la memoria al finalizar
    printf("\n\nEstamos por liberar la memoria Dinamica que generamos\n");
    pausa();
    for (int i = 0; i < fila; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
    printf("\n\nMemoria Dinamica Liberada!!!!\n");
    pausa();
    return 0;
}

void pausa()
{
    printf("\nPresiona Enter para continuar...\n");
    fflush(stdin); // Limpia el búfer de salida para asegurarse de que se muestra el mensaje
    while (getchar() != '\n'); // Lee y descarta cualquier carácter ingresado hasta que se presione Enter
}