#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int Sumar(int,int);
int main()
{
    int a,b;
    printf("Ingrese 1er Valor:");
    scanf("%d",&a);
     printf("Ingrese 2do Valor:");
    scanf("%d",&b);
    printf("El resultado fue:%d\n",Sumar(a,b));
    return 0;
}

int Sumar(int x, int y)
{
    return x+y;
}
