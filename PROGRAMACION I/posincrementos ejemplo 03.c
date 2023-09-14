#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

#define p printf
#define s scanf
/*
    0 = Negro       8 = Gris
    1 = Azul        9 = Azul claro
    2 = Verde       A = Verde claro
    3 = Aguamarina        B = Aguamarina claro
    4 = Rojo        C = Rojo claro
    5 = Púrpura     D = Púrpura claro
    6 = Amarillo    E = Amarillo claro
    7 = Blanco      F = Blanco brillante
    */

int main()
{
 int j=0,i=1;
 system("cls");
 system("color 9f");
 j=2;
 printf("j=%d\n",j*3);
 printf("i=%d\n",i);
 printf("\n--------------\n");
 j=(i++)*5;
 printf("j=%d\n",j);
 printf("i=%d\n",i);
 printf("\n--------------\n");
 return 0;
}

/*
j=6
i=1

--------------
j=5
i=2

--------------
*/
