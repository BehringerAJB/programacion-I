#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
Se desea saber el total de ventas de cada uno de los vendedores de una empresa.
A tal fin se tienen como datos: 
el código de vendedor y el importe de cada unade las ventas;
 un vendedor puede haber realizado más de una venta. 
  No  se  sabela  cantidad  de  vendedores  que  tiene  la  empresa  
  ni  la cantidad de ventas hechas por cada vendedor 
  (un código de vendedor igual a cero es fin de datos). 
  –ESTOS DATOS ESTAN ORDENADOS POR CODIGO DE VENDEDOR.
  Exhibir cada código de vendedor y su total correspondiente y 
  al final el código de vendedor con mayor importe vendido y dicho importe.
*/
int main (){
    //definimos las variables
    int vendedor, VendMaximo, aux, flag=1;
    float importe, importeaux=0.0,VentaMax;
    system("cls");
    //pedir codigo de vendedor
    printf("ingrese codigo de vendedor, < 0 > cero para salir:");
    //leer codigo de vendedor
    scanf("%d", &vendedor);
    aux=vendedor;
        while (vendedor!=0)
        {
            printf("Ingrese el monto de venta:");
            scanf("%f", &importe);
            importeaux+=importe;
            printf("ingrese codigo de vendedor, < 0 > cero para salir:");
            scanf("%d", &vendedor);
            if (aux!=vendedor)
            {  
                printf("\t\t>>>>>> la suma de ventas del vendedor %d, importe es %3.2f \n", aux, importeaux);
                if(flag)
                {
                    VentaMax=importeaux;
                    VendMaximo=aux;
                    flag=0;
                }
                if(importeaux>VentaMax)
                {
                    VentaMax=importeaux;
                    VendMaximo=aux;
                }
                aux=vendedor;
                importeaux=0.0;
            }
        }
        printf("\n\n La mejor acumulacion de Ventas fue realzada por el Vendedor:%2d\n",VendMaximo);
        printf("y el monto fue:%5.2f\n",VentaMax);
        printf("\n\nPulse una tecla para continuar\n");getch();
    return 0;
}