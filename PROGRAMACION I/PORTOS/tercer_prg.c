#include<stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int a;
    int b;
    printf("Ingrese el 1er valor: ");
    scanf("%d", &a);
    printf("Ingrese el 2do valor: ");
    scanf("%d", &b);
    if (a > b)
    {
        printf("%d es mayor que %d\n",a,b);
    }
    else
        printf("%d es mayor que %d\n",b,a);
    return 0;
}