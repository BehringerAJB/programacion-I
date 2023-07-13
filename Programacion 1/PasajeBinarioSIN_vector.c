#include <stdio.h>

int main()
{
    int binario, decimal = 0, base = 1;

    printf("Ingrese un numero en binario: ");
    scanf("%d", &binario);

    while (binario > 0)
    {
        int digito = binario % 10;
        decimal += digito * base;
        binario /= 10;
        base *= 2;
    }

    printf("El numero en decimal es: %d\n", decimal);

    return 0;
}
