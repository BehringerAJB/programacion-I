#include <stdio.h>
#include <math.h>
#include<time.h>
int main()
{
    // bloque de codigo
    int n1,n2,resul;
    printf("Ingrese 1er Valor:");
    scanf("%d",&n1);
    printf("Ingrese 2do Valor:");
    scanf("%d",&n2);
    if (n1>n2)
    {
        printf("%d fue mayor que %d\n",n1,n2);
    }
    else
    {
        printf("%d fue mayor que %d\n",n2,n1);
    }
    
}