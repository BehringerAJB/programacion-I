#include <stdio.h>

float Area_rectangulo(float,float);
float entradafloat(char *);
int main()
{
    float b,h; // height 
    char *a;
    gets(a);
    printf("%s",a);
    fflush(stdin);
    b=entradafloat("Ingrese la base del rectagulo:");
    h=entradafloat("Ingrese la altura de rectangulo:");
    printf("\n Area del Rectangulo:%3.2f\n",Area_rectangulo(b,h));
    return 0;
}

float Area_rectangulo(float b, float a)
{
    return b*a;
}

float entradafloat(char *msj)
{
    float valor;
    do{
        printf("\n %s",msj);
        scanf("%f",&valor);

    }while(valor<=0.0);
    return valor;
}
