/*
Crear un programa que mediante un menú que tenga ingresar
        printf("\n\t\t\t MENU DE OPCIONES (RESERVAS)\n");
        printf("\n\t\t\t - Ingresar Dato de Reserva             <1>");
        printf("\n\t\t\t - Dar de Baja Una Reserva              <2>");
        printf("\n\t\t\t - mostrar asientos Libres y Reservados <3>");
        printf("\n\t\t\t - Salir                                <4>");
        printf("\n\t\t\tIngrese Opcion:  ");
admita reservar o cancelar asientos de un transporte
así como mostrar qué asientos están ocupados y libres actualmente.
El arreglo tendrá 25 filas y 2 hileras de asiento

*/
#include <stdio.h>
#include <stdlib.h>

// prototipos
int menu(void);
void cargarReservas(int[], int[]);
void BajaReserva(int[], int[]);
void MostrarLibresReservas(int[], int[]);
void pausa(void);
int main()
{
    int hilera1[25] = {0}, hilera2[25] = {0};
    int op;
    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            cargarReservas(hilera1, hilera2);
            break;
        case 2:
            BajaReserva(hilera1, hilera2);
            break;
        case 3:
            MostrarLibresReservas(hilera1, hilera2);
        }
    } while (op!=4);
    printf("\n\nsaliste del sistema ....\n\n");
    return 0;
}
void cargarReservas(int ventanilla[], int pasillo[])
{
    int nro_asiento;
    int fila, flag = 0;
    do
    {
        if (flag)
        {
            printf("\nEl asiento que eligio esta ocupado\n");
            printf("Seleccione Otro\n");
            flag = 0;
        
        else
        {
            do
            {
                printf("Ingrese Nro de asiento <1 al 25>:");
                scanf("%d", &nro_asiento);
            } while (nro_asiento < 1 || nro_asiento > 25);
            do
            {
                printf("Ingrese Ventanilla <1>:\n");
                printf("Ingrese Pasillo    <2>:\n");
                scanf("%d", &fila);
                // la fila determina el pasillo y Ventanilla
            } while (fila < 1 || fila > 2);

            if (fila == 1 && ventanilla[nro_asiento - 1] == 1)
            {
                flag = 1;
            }
            if (fila == 2 && pasillo[nro_asiento - 1] == 1)
            {
                flag = 1;
            }
        }
    } while (flag);
    if (fila==1)
        ventanilla[nro_asiento-1]=1;
    if (fila==2)
        pasillo[nro_asiento-1]=1;

    printf(" su asiento a sido reservado");
}
int menu(void)
{
    int op;
    do
    {
        //system("cls");
        printf("\n\t\t\t MENU DE OPCIONES (RESERVAS)\n");
        printf("\n\t\t\t - Ingresar Dato de Reserva             <1>");
        printf("\n\t\t\t - Dar de Baja Una Reserva              <2>");
        printf("\n\t\t\t - mostrar asientos Libres y Reservados <3>");
        printf("\n\t\t\t - Salir                                <4>");
        printf("\n\t\t\tIngrese Opcion:  ");
        scanf("%d", &op);
    } while (op < 1 || op > 4);
    return op;
}
void MostrarLibresReservas(int ventanilla[], int pasillo[])
{
    int i;
    printf("\nInforme de Ocupacion de Transporte\n");
    printf("fila Ventanilla\tPasillo\n");
    for (i = 0; i < 25; i++)
    {
        printf("<%2d>\t%2d\t%2d\n", i+1, ventanilla[i], pasillo[i]);
    }
    pausa();
}

void BajaReserva(int ventanilla[], int pasillo[])
{
    printf("NO FUNCIONA AUN");
}

void pausa()
{
    printf("Presiona Enter para continuar...");
    fflush(stdin); // Limpia el búfer de salida para asegurarse de que se muestra el mensaje
    while (getchar() != '\n'); // Lee y descarta cualquier carácter ingresado hasta que se presione Enter
}

