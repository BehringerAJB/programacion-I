#include <stdio.h>

float Area_rectangulo(float, float);
float entrada(void);
int main()
{
    float b, h; // height
    printf("Ingrese la base del rectagulo:");
    b = entrada();
    printf("Ingrese la altura de rectangulo:");
    h = entrada();
    printf("\n Area del Rectangulo:%3.2f\n", Area_rectangulo(b, h));
    return 0;
}

float Area_rectangulo(float b, float a)
{
    return b * a;
}

float entrada()
{
    d float valor;
    do
    {
        scanf("%f", &valor);

    } while (valor <= 0.0);
    return valor;
}
