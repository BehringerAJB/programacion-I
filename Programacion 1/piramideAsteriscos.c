#include <stdio.h>

int main() {
    int altura;
    printf("Ingrese la altura de la piramide: ");
    scanf("%d", &altura);

    // iterar a través de las filas de la piramide
    for (int i = 1; i <= altura; i++) {
        // imprimir espacios en blanco para alinear la piramide
        for (int j = 1; j <= altura - i; j++) {
            printf(" ");
        }
        // imprimir asteriscos para la fila actual
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
