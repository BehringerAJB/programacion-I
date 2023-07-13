#include <stdio.h>
#include <math.h>

int main() {
    int cantidad, altura;
    printf("Ingrese la cantidad de asteriscos: ");
    scanf("%d", &cantidad);

    // Calcular la altura de la pirámide
    altura = ceil(sqrt(cantidad));

    // Imprimir la pirámide
    int asteriscos = 1;
    for (int i = 1; i <= altura; i++) {
        // imprimir espacios en blanco para alinear la piramide
        for (int j = 1; j <= altura - i; j++) {
            printf(" ");
        }
        // imprimir asteriscos para la fila actual
        for (int k = 1; k <= asteriscos; k++) {
            if (k > cantidad) {
                break;
            }
            printf("*");
        }
        printf("\n");
        cantidad -= asteriscos;
        asteriscos += 2;
    }

    return 0;
}
