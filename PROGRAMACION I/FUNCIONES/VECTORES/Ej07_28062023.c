#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOTES 30

int main() 
{
    int hh[LOTES], mm[LOTES], ss[LOTES];
    float porcentajeBienes;
    float porcentajeMales;
    int bienIngresados = 0;
    int malIngresados = 0;

    srand(time(NULL));  // Inicializar la semilla aleatoria

    printf("Horarios generados:\n");
    for (int i = 0; i < LOTES; i++) {
        hh[i] = rand() % 41;    // Generar hora aleatoria entre 0 y 40
        mm[i] = rand() % 81;    // Generar minutos aleatorios entre 0 y 80
        ss[i] = rand() % 81;    // Generar segundos aleatorios entre 0 y 80

        printf("hh:%2d mm:%2d ss:%2d\n", hh[i], mm[i], ss[i]);

        if (hh[i] >= 0 && hh[i] <= 24 && mm[i] >= 0 && mm[i] <= 60 && ss[i] >= 0 && ss[i] <= 60) {
            bienIngresados++;
        } else {
            malIngresados++;
        }
    }

    porcentajeBienes = (float)bienIngresados / LOTES * 100;
    porcentajeMales = (float)malIngresados / LOTES * 100;

    printf("\nResultados:\n");
    printf("Cantidad de horarios bien ingresados.........> %2d\n", bienIngresados);
    printf("Cantidad de horarios mal ingresados:.........> %2d\n", malIngresados);
    printf("Porcentaje de horarios bien ingresados:.. %3.2f%%\n", porcentajeBienes);
    printf("Porcentaje de horarios mal ingresados:... %3.2f%%\n", porcentajeMales);

    return 0;
}

