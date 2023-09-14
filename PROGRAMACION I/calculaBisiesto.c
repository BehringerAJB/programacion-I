#include <stdio.h>

int main()
{
    int mes, anio, dias, flag = 0;
    char *nombreMes, *mensaje = "El mes de ";
    system("cls");
    printf("Ingrese un numero de mes (1-12): ");
    scanf("%d", &mes);
    printf("Ingrese un a%co:", 164);
    scanf("%d", &anio);

    switch (mes)
    {
    case 1:
        nombreMes = "Enero";
        dias = 31;
        break;
    case 3:
        nombreMes = "Marzo";
        dias = 31;
        break;
    case 5:
        nombreMes = "Mayo";
        dias = 31;
        break;
    case 7:
        nombreMes = "Julio";
        dias = 31;
        break;
    case 8:
        nombreMes = "Agosto";
        dias = 31;
        break;
    case 10:
        nombreMes = "Octubre";
        dias = 31;
        break;
    case 12:
        nombreMes = "Diciembre";
        dias = 31;
        break;
    case 4:
        nombreMes = "Abril";
        dias = 30;
        break;
    case 6:
        nombreMes = "Junio";
        dias = 30;
        break;
    case 9:
        nombreMes = "Sptiembre";
        dias = 30;
        break;
    case 11:
        nombreMes = "Noviembre";
        dias = 30;
        break;
    case 2:
        nombreMes = "Febrero";
        if (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0))
        {
            dias = 29;
        }
        else
            dias = 28;
        break;
    }
    // El mes de xxxx tiene xx dias en el año xxxx
    if (flag)
    {
        printf("%s %s tiene:%2d dias, en el a%co Bisiesto de:%4d\n", mensaje, nombreMes, dias, 164, anio);
    }
    else
        printf("%s %s tiene:%2d dias, en el a%co de:%4d\n", mensaje, nombreMes, dias, 164, anio);
    return 0;
}
