#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    int cod_cli, cant, precio;
    int Venta_cli1, Venta_cli2;
    // acumulativo de ventas
    Venta_cli1 = 0;
    Venta_cli2 = 0;
    // aqui realizamos una validacion
    // teniendo en cuenta tambien la salida con -1
    do
    {
        printf("Ingrese codigo de cliente < 1 o 2>:\n");
        printf("<0> para Salir\n");
        scanf("%d", &cod_cli);
    } while ((cod_cli < 1 || cod_cli > 2) && (cod_cli != -1));
    while (cod_cli != -1)
    {
        printf("Ingrese cantidad:");
        scanf("%d", &cant);
        printf("Ingrese Precio:");
        scanf("%d", &precio);
        if (cod_cli == 1)
            Venta_cli1 += precio * cant;
        else
            Venta_cli2 += precio * cant;
        do
        {
            printf("Ingrese codigo de cliente < 1 o 2>:\n");
            printf("<0> para Salir\n");
            scanf("%d", &cod_cli);
        } while ((cod_cli < 1 || cod_cli > 2) && (cod_cli != -1));
    }
    printf("Las ventas de Cliente 1:son:%d\n", Venta_cli1);
    printf("Las ventas de Cliente 2:son:%d\n", Venta_cli2);
    if (Venta_cli1 == Venta_cli2)
        printf("las ventas fueron iguales:%d\n", Venta_cli1);
    else if (Venta_cli1 > Venta_cli2)
        printf("las ventas del cliente 1 fueron mayores:%d\n", Venta_cli1);
    else
        printf("las ventas del cliente 2 fueron mayores:%d\n", Venta_cli2);
    printf("El promedio resulto:%d\n", (Venta_cli1 + Venta_cli2) / 2);
    return 0;
}
