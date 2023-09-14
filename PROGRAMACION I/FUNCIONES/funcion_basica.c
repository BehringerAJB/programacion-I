#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

// trabajamos con funcioes
// se declara un prototipo
int Sumar(int,int);

int main()
{
    int a,b;
    printf("Ingrese 1er valor:");
    scanf("%d",&a);
    printf("Ingrese 2do valor:");
    scanf("%d",&b);
    printf("la suma resulto:%d\n",Sumar(a,b));
    return 0;

}
int Sumar(int x,int y)
{
    return x+y;
}