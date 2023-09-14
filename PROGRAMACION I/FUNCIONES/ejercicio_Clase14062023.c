#include <stdio.h>
float Area_rectangulo(float, float);
float entrada(char *);
int main()
{
    // ambiente de datos
    // definimos variables
    float b,h;
    b=entrada("Ingrese el valor de la base:");
    h=entrada("Ingrese el valor de la Altura:");
    printf("\nEl area del rectangulo resulto:%3.2f\n",Area_rectangulo(b,h));
    return 0;
}

float entrada(char *msj)
{
    // ambiente de datos
    float valor;
    do
    {
        printf("%s",msj);
        scanf("%f",&valor);
    } while (valor<=0.0);
    return valor;
}
float Area_rectangulo(float b, float a)
{
    return b*a;
}
