/*
Escribir un programa que genere un número aleatorio entre 1 y 20.
Luego, pide al usuario que adivine ese número.
El programa proporcionará pistas:
Si el número ingresado se encuentra a una distancia de 1 del número secreto, el programa mostrará el mensaje "Estás al lado".
Si el número ingresado se encuentra a una distancia de 2 del número secreto, el programa mostrará el mensaje "Estás muy cerca".
Si el número ingresado se encuentra a una distancia de 5 del número secreto, el programa mostrará el mensaje "Estás muy lejano".

El jugador tiene un total de 15 intentos para adivinar el número correcto. Después de cada intento, el programa mostrará cuántos intentos le quedan al jugador.
Informe Final:
Si el jugador adivina el número en el primer intento, el programa mostrará el mensaje "¡Una genialidad!" y finalizará el juego.
Si el jugador adivina el número antes de los 5 intentos (inclusive), el programa mostrará el mensaje "¡Sos muy bueno!".
Si el jugador adivina el número antes de los 10 intentos (inclusive), el programa mostrará el mensaje "Podríamos mejorar esa marca".
Si el jugador adivina el número después de los 10 intentos, el programa mostrará el mensaje "Deberías practicar más".
Si el jugador adivina correctamente el número, el programa mostrará un mensaje de felicitaciones y el número total de intentos realizados.
Si el jugador no logra adivinar el número después de los 15 intentos, el programa mostrará el mensaje "¡Agotaste tus intentos!" y finalizará el juego.

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int flag,numeroSecreto, intentos = 0;
    int nro;
    srand(time(NULL));
    numeroSecreto = rand() % 20 + 1;
    int distancia;
    int totalIntestos=15;
    flag = 1;
    printf("\n\nBienvenido al juego de adivinar el numero\n");
    printf("Tenes %d intentos para adivinar el numero secreto.\n",totalIntestos);
    printf("\nIntento actual: %d\n", numeroSecreto);
    do
    {
        printf("\tIngresa tu numero entre <1 y 20>:");
        scanf("%d", &nro);
    } while (nro < 1 || nro > 20);

    while ((intentos < totalIntestos) && flag)
    {
        if (nro == numeroSecreto)
            flag = 0;
        else
        {
            distancia = abs(numeroSecreto - nro);
            if (distancia == 1)
                printf("Estas al lado.\n");
            else if (distancia >= 3)
                printf("Estas muy lejano\n");
            else if (distancia == 2)
                printf("Estás muy cera..\n");
            if (intentos == totalIntestos)
                printf("¡Agotaste tus intentos! El numero secreto era %d\n", numeroSecreto);
            else
            {
                intentos++;
                printf("Incorrecto. Te quedan %d intentos.\n", totalIntestos - intentos );
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
