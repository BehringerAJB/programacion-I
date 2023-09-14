#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
void pausa(void); // prototipo

int main()
{
    int pescador, i, cantidad, flagLong = 1, PescadorMaxlong, CantPiezas1 = 0, CantPiezas2 = 0, CantPiezas3 = 0;
    float longitud, SumLong = 0.0, Maxlong, CantLong = 0.0;
    do
    {
        printf("Ingrese codigo de pescador <1 a 3> 0(cero) para Salir:");
        scanf("%d", &pescador);
    } while ((pescador < 1 || pescador > 3) && pescador != 0); // condicion de salida y validacion
    while (pescador != 0)
    {
        printf("Ingrese cantidad de Piezas Pescadas:");
        scanf("%d", &cantidad);
        for (i = 0; i < cantidad; i++)
        {
            printf("\t\tIngrese longitud del pez<%d>:", i + 1);
            scanf("%f", &longitud);
            SumLong += longitud;
            if (flagLong)
            {
                Maxlong = longitud;
                PescadorMaxlong = pescador; // quien pesco el pescado mas largo
                flagLong = 0;
            }
            else if (longitud > Maxlong)
            {
                Maxlong = longitud;
                PescadorMaxlong = pescador; // quien pesco el pescado mas largo
            }
        }
        CantLong += cantidad; // acumulador de cantidad de longitudes de pescado
        switch (pescador)
        {
        case 1:
            CantPiezas1 += cantidad;
            break;
        case 2:
            CantPiezas2 += cantidad;
            break;
        case 3:
            CantPiezas3 += cantidad;
        }
        do
        {
            printf("Ingrese codigo de pescador <1 a 3> 0(cero) para Salir:");
            scanf("%d", &pescador);
        } while ((pescador < 1 || pescador > 3) && pescador != 0); // condicion de salida y validacion
    }
    printf("la Pieza de mayor de longitud fue:%3.2f perteneciente al pescador: %d\n", Maxlong, PescadorMaxlong);
    printf("El total de piezas extraidas del agua, son:%3.0f\n", CantLong);
    printf("El promedio de las longitudes de las Piezas extraidas es de :%3.2f\n", SumLong / CantLong);
    if (CantPiezas1 > CantPiezas2 && CantPiezas1 > CantPiezas3)
        printf("La mayor cantidad de piezas estraidas fue del pescador 1 con %d piezas\n", CantPiezas1);
    else if (CantPiezas2 > CantPiezas1 && CantPiezas2 > CantPiezas3)
        printf("La mayor cantidad de piezas estraidas fue del pescador 2 con %d piezas\n", CantPiezas2);
    else if (CantPiezas3 > CantPiezas1 && CantPiezas3 > CantPiezas2)
        printf("La mayor cantidad de piezas estraidas fue del pescador 3 con %d piezas\n", CantPiezas3);
    else
    {

        printf("informamos la cantidad de piezas ya que se dio un empate en algun caso\n");
        printf("Piezas del Pescador 1:%d\n", CantPiezas1);
        printf("Piezas del Pescador 1:%d\n", CantPiezas2);
        printf("Piezas del Pescador 1:%d\n", CantPiezas3);
        printf("fijate !!\n");
    }
    pausa();
    return 0;
}

void pausa()
{
    printf("\nPresiona Enter para continuar...\n");
    fflush(stdin); // Limpia el búfer de salida para asegurarse de que se muestra el mensaje
    while (getchar() != '\n')
        ; // Lee y descarta cualquier carácter ingresado hasta que se presione Enter
}