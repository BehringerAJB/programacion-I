///Un programa que lee una cadena de texto y la trabaja
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
 unsigned int  i;
 char cad[81];
 printf("ingrese un Nombre:");
 scanf("%s",cad);
 printf("%30s\n",cad);
 printf("Largo de la cadena:%d\n",strlen(cad));
 for ( i = 0; i < strlen(cad); i++)
 {
    printf("-%c-",cad[i]);
 }
 return 0;
}