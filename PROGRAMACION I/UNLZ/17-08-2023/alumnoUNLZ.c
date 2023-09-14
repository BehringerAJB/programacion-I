#include <stdio.h>
int main()
{
    int codCli, Precio, cant;
    int ventaCli1, ventaCli2;
    ventaCli1 = 0;
    ventaCli2 = 0;
    printf("ingrese el codigo de cliente:");
    scanf("%d", &codCli);
    while (codCli != 0)
    {
        printf("ingrese cantidad:");
        scanf("%d", &cant);
        printf("ingrese el precio:");
        scanf("%d", &Precio);
        if (codCli == 1) // aqui faltaba un igual
            ventaCli1 += cant * Precio;
        else
            ventaCli2 += cant * Precio;
        printf("ingrese el codigo de cliente:\n"); // aca pusiste la barra al reves
        printf("0 para salir\n");// aca pusiste la barra al reves
        scanf("%d", &codCli);
    }
    printf("ventas del cliente1:$%d\n",ventaCli1); // aca te olvidaste la coma y la barra al reves
    printf("ventas del cliente2:$%d\n", ventaCli2);// aca te olvidaste la coma y la barra al reves
    if (ventaCli1 == ventaCli2) // aqui tenias un punto y coma y cortaba el if
        printf("ventas iguales%d\n", ventaCli1); //  la barra al reves
    else if (ventaCli1 > ventaCli2)
        printf("gano el cliente 1 con $%d\n", ventaCli1);//  la barra al reves
    else
        printf("gano el cliente 2 con $%d\n", ventaCli2);//  la barra al reves
    printf("promedioventas:%d\n", (ventaCli1 + ventaCli2) / 2);//  la barra al reves
    return 0;
}