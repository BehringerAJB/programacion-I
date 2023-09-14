#include <stdio.h>

int esCapicua(int );

int main() {
    int numero;
    system("cls");
    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    if (esCapicua(numero)) {
        printf("El numero es capicua.\n");
    } else {
        printf("El numero no es capicua.\n");
    }
    return 0;
}

int esCapicua(int numero) {
    int original = numero;
    int invertido = 0;
    int digito;
    printf("Original      digito      invertido          numero\n");
    while (numero > 0) {
        digito = numero % 10;
        invertido = invertido * 10 + digito;
        numero /= 10;
        printf("%d\t\t%d\t\t%d\t\t%d\n",original,digito,invertido,numero);
    }

    if (original == invertido) {
        return 1;  // El número es capicúa
    } else {
        return 0;  // El número no es capicúa
    }
}