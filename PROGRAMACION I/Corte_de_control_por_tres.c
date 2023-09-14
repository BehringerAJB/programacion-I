#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*

*/
int main (){
    //definimos las variables
    int vendedor, VendMaximo, aux, flag=1;
    int mes;
    float importe, importeaux=0.0,VentaMax;
    system("cls");
    printf("ingrese codigo de vendedor, < 0 > cero para salir:");
    scanf("%d", &vendedor);
    aux=vendedor;
        while (vendedor!=0)
        {
           do
           {
                printf("ingrese mes");
                scanf("%d",&mes);
           } while (mes<1 || mes>12);
           
        
            scanf("%d", &vendedor);
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