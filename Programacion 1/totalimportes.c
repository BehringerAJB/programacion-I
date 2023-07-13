#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main (){
       
    //definimos las variables 
    int vendedor, ventas, vemaximo, ventamax, aux;
    float importe, importeaux=0.0;

    //pedir codigo de vendedor
    printf("ingrese codigo de vendedor, si desea salir del programa ingrese 0 \n");
    //leer codigo de vendedor
    scanf("%d", &vendedor);
    aux=vendedor;
        while (vendedor!=0)
        {
            printf("Ingrese el monto de venta: \n");
            scanf("%f", &importe);
            importeaux+=importe;
            printf("ingrese codigo de vendedor, si desea salir del programa ingrese 0 \n");
            scanf("%d", &vendedor);
            if (aux!=vendedor)
            {  
                printf("la suma de ventas del vendedor %d, importe es %3.2f \n", aux, importeaux);
                aux=vendedor;
                importeaux=0.0;
            }
        }
        
        printf("Saliendo del programa");

    return 0;
}


