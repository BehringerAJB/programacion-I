#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int main()
{
    int op;
    float celcius,far;
    printf("Para convertir de C a F pulse <1>\n");
    printf("Para convertir de F a C pulse <2>\n");
    printf("Digite la opcion:\n");
    scanf("%d",&op);
    if(op==1)
    {
        printf("Ingrese una temperatura en Celcius:");
        scanf("%f",&celcius);
        far=(1.8*celcius)+32.0;
        printf("%3.2f grados Celcius equivalen a %3.2f Grados Farenheit\n",celcius,far);
    }
    if (op==2)
    {
        printf("Ingrese una temperatura en Farenheit:");
        scanf("%f",&celcius);
        celcius=(far-32)/1.8;
        printf("%3.2f grados Farenheit equivalen a %3.2f Grados Celcius\n",far,celcius);
    }
    if (op!=1 || op!=2)
    {
        printf("\n Pulso otra opcion distintas a las Ofrecidas\n");
    }
    return 0;
}