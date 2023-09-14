/*
Escribe un programa que permita ingresar los datos de clientes,
incluyendo artículos, precios y cantidades y luego
informe el resultado final mediante un mensaje de impresión (printf).
El programa debe repetirse hasta que se ingrese un código de cliente igual a 0.
Además, se deben incluir validaciones para asegurar la correcta entrada de datos por parte del usuario.

El programa debe funcionar de la siguiente manera:

Solicitar al usuario que ingrese el código del cliente (ingresar 0 para finalizar).
Si el código del cliente ingresado es 0, terminar el programa.
Si el código del cliente es diferente de 0, solicitar los datos de los artículos.
Para cada artículo, solicitar al usuario que ingrese el código del artículo (ingresar 0 para finalizar el cliente).
Si el código del artículo ingresado es 0, finalizar el ingreso de artículos para el cliente actual.
Si el código del artículo es diferente de 0, solicitar al usuario que ingrese el precio del artículo y
la cantidad.
Calcular y acumular el subtotal (precio * cantidad) para cada artículo.
Al finalizar el ingreso de artículos para el cliente actual,
mostrar el total para ese cliente mediante un mensaje de impresión (printf).
Repetir los pasos del 1 al 8 para cada cliente adicional hasta que se ingrese un código de cliente igual a 0.
Al finalizar el programa, mostrar el total general de todos los clientes mediante un mensaje de impresión (printf).


*/
#include <stdio.h>

int main()
{
    int codigoCliente;
    int codigoArticulo;
    float precio;
    int cantidad;
    float subtotal;
    float totalCliente = 0.0;
    float totalGeneral = 0.0;
    system("cls");
    printf("Ingrese el c%cdigo del cliente (ingrese 0 para finalizar):\n", 162);
    scanf("%d", &codigoCliente);
    while (codigoCliente != 0)
    {
        printf("Ingrese el c%cdigo del artículo (ingrese 0 para finalizar cliente): ", 162);
        scanf("%d", &codigoArticulo);
        while (codigoArticulo != 0)
        {
            printf("Ingrese el precio del artículo: ");
            scanf("%f", &precio);

            printf("Ingrese la cantidad: ");
            scanf("%d", &cantidad);
            subtotal = precio * cantidad;
            totalCliente += subtotal;
            printf("Ingrese el código del artículo (ingrese 0 para finalizar cliente): ");
            scanf("%d", &codigoArticulo);
        }

        printf("El total para el cliente %2d es: %3.2f\n", codigoCliente, totalCliente);
        totalGeneral += totalCliente;
        totalCliente = 0.0;
        printf("Ingrese el código del cliente (ingrese 0 para finalizar):\n");
        scanf("%d", &codigoCliente);
    }
    printf("El total general de todos los clientes es: %.2f\n", totalGeneral);
    return 0;
}
