#include <stdio.h>
#define TAMANO_VECTOR 5

int main() {
    int vector[TAMANO_VECTOR]={23,67,54,6,45};
    int i;

    // Inicializar el vector con valores
    /* for (i = 0; i < TAMANO_VECTOR; i++) {
        vector[i] = i + 1;
    } */

    // Imprimir el vector
    printf("\nValores del Vector:\n\n ");
    for (i = 0; i < TAMANO_VECTOR; i++) 
    {
        printf("vector[%d]=%2d\n ",i,vector[i]);
    }
    printf("\n");

    return 0;
}
