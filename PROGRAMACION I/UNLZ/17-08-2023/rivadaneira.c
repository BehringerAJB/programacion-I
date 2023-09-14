#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    int numAdivinar;
    int tries = 0;
    int distancia;

    printf("Adivina un número del 1 al 20 en un máximo de 15 intentos:\n");
    srand(time(NULL));
    int numAleatorio = rand() % 20 + 1;
    while (tries < 15)
    {
        scanf("%d", &numAdivinar);
        tries++;
        if (numAleatorio == numAdivinar)
        {
            printf("¡Número correcto, felicitaciones!\n");
            printf("Intentos: %d\n", tries);
            if (tries == 1)
            {
                printf("¡Una genialidad!\n");
            }
            if (tries <= 5)
            {
                printf("¡Sos muy bueno!\n");
            }
            else if (tries <= 10)
            {
                printf("Podríamos mejorar esa marca\n");
            }
            if (tries > 10)
            {
                printf("Deberías practicar más\n");
            }
            return 0;
        }

        distancia = abs(numAleatorio - numAdivinar);

        if (distancia == 1)
        {
            printf("Estás al lado\n");
        }
        if (distancia == 2)
        {
            printf("Estás muy cerca\n");
        }
        if (distancia == 5)
        {
            printf("Estás muy lejos\n");
        }
        printf("Intentos restantes: %d\n", 15 - tries);
    }
    printf("¡Agotaste tus intentos!\nJuego terminado\n");

    return -1;
}