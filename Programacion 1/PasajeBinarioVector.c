#include <stdio.h>
#include <math.h>

int main()
{
    char binario[32];
    int longitud, i, decimal = 0;

    printf("Ingrese un numero en binario: ");
    scanf("%s", binario);

    // Calcular la longitud de la cadena
    longitud = 0;
    while (binario[longitud] != '\0')
    {
        longitud++;
    }

    // Convertir binario a decimal
    for (i = longitud - 1; i >= 0; i--)
    {
        if (binario[i] == '1')
        {
            decimal += pow(2, longitud - 1 - i);
        }
    }

    printf("El numero en decimal es: %d\n", decimal);

    return 0;
}
