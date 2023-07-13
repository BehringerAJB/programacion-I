#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int numeroSecreto, intentos = 0;
    int nro;
    srand(time(NULL));
    numeroSecreto = rand() % 20 + 1;
    int distancia;
    int flag = 1;
    printf("\n\nBienvenido al juego de adivinar el numero\n");
    printf("Tenes 15 intentos para adivinar el numero secreto.\n");
    printf("\nIntento actual: %d\n", numeroSecreto);
    do
    {
        printf("\tIngresa tu numero entre <1 y 20>:");
        scanf("%d", &nro);
    } while (nro < 1 || nro > 20);

    while ((intentos < 15) && flag)
    {
        if (nro == numeroSecreto)
            flag = 0;
        else
        {
            distancia = abs(numeroSecreto - nro);
            if (distancia == 1)
                printf("Estas al lado.\n");
            else if (distancia >= 5)
                printf("Estas muy lejano\n");
            else if (distancia >= 2)
                printf("Estás muy cera..\n");
            if (intentos == 15)
            {
                printf("¡Agotaste tus intentos! El numero secreto era %d\n", numeroSecreto);
                flag = 0;
            }
            else
            {
                intentos++;
                printf("Incorrecto. Te quedan %d intentos.\n", 15 - intentos );
                printf("\nIntento actual: %d\n", intentos + 1);
                do
                {
                    printf("\tIngresa tu numero entre <1 y 20>: ");
                    scanf("%d", &nro);
                } while (nro < 1 || nro > 20);
            }
        }
    }

    if (intentos == 0)
        printf("¡Una genialidad! Adivinaste el numero en el primer intento.\n");
    else if (intentos <= 5)
        printf("¡Sos muy bueno! Adivinaste el numero en %d intentos.\n",  intentos+1);
    else if (intentos <= 10)
        printf("Podriamos mejorar esa marca. Adivinaste el numero en %d intentos.\n", intentos+1);
    else
        printf("Deberías practicar mas. Adivinaste el numero en %d intentos.\n", intentos+1);
    return 0;
}
