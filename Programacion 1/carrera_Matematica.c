#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 2
#define limpiar system("cls");
#define pausa system("pause");
int main()
{
    int jugador1, jugador2, jugador3, pasos1, pasos2, pasos3;
    int inicio;
    pasos1 = 0;
    pasos2 = 0;
    pasos3 = 0;
    srand(time(NULL)); // semilla aleatoria
    limpiar
    printf("Bienvenido/a a la carrera matematica! \n");
    printf("En la carrera hay 3 jugadores que deberan recorrer un tablero,\n");
    printf("el tablero tiene 20 espacios y en cada turno se generara \n");
    printf("un numero aleatorio para cada jugador y dependiendo el resultado \n");
    printf("avanzaran o retrocederan los casilleros. \n");
    printf("Comenzamos el juego?\n");
    pausa
    limpiar
    printf("Elija:\n\n<1> para Comenzar \n<0> para Salir del juego \n");
    scanf("%d", &inicio);
   
    if (inicio == 1)
    {
        printf("Comienza el juego...\n \n");
        do
        {
            /*Turno jugador 1, lanzamiento aleatorio*/
            //printf("Es el turno del jugador 1 \n \n");
            //printf("Generando el número aleatorio...\n \n");
            /*Control del numero obtenido jugador1*/
            jugador1 = rand() % 1800 + 1;
            //printf("Salio el numero %d \n \n", jugador1);
            if ((jugador1 % N) == 0 && (jugador1 > 1 && jugador1 < 200))
            {
                //printf("El jugador 1 avanza 1 casillero! \n \n");
                pasos1 += 1;
            }
            else if (jugador1 % N == 0 && jugador1 > 281 && jugador1 < 550 && pasos1 > 0)
            {
                //printf("El jugador 1 retrocede 1 casillero! \n \n");
                pasos1 = pasos1 - 1;
            }
            /*Turno jugador 2, lanzamiento aleatorio*/
            //printf("Es el turno del jugador 2 \n \n");
            //printf("Generando el número aleatorio...\n \n");

            jugador2 = rand() % 1000 + 1;
            //printf("Salio el numero %d \n \n", jugador2);

            /*Control del numero obtenido jugador2*/
            if (jugador2 % 3 == 0 && jugador2 > 1 && jugador2 < 500)
            {
                //printf("El jugador 2 avanza 1 casillero! \n \n");
                pasos2 = pasos2 + 1;
            }
            else if (jugador2 >= 800 && pasos2 > 0)
            {
                //printf("El jugador 2 retrocede 1 casillero! \n \n");
                pasos2 = pasos2 - 1;
            }
            /*Turno jugador 3, lanzamiento aleatorio*/
           // printf("Es el turno del jugador 3 \n \n");
            //printf("Generando el número aleatorio...\n \n");

            jugador3 = rand() % 1000 + 1;
            //printf("Salio el numero %d \n \n", jugador3);

            /*Control del numero obtenido jugador3*/
            if (jugador3 % 5 == 0 && jugador3 > 1 && jugador3 < 750)
            {
                //printf("El jugador 3 avanza 1 casillero! \n \n");
                pasos3 = pasos3 + 1;
            }
            else if (jugador3 >= 800 && pasos3 > 0)
            {
                //printf("El jugador 3 retrocede 1 casillero! \n \n");
                pasos3 = pasos3 - 1;
            }
            printf("El jugador 1:%d jugador 2:%d Jugador 3:%d\n", pasos1,pasos2,pasos3);
        } while (pasos1 < 20 && pasos2 < 20 && pasos3 < 20);
    }
    pausa
    return 0;
}