#include <stdio.h>
#include <ctype.h>
#include <string.h>


void pasaMinuscula(char*);
void mayu(char []);
void invertir(char [],char []);

int main() 
{
    char x[100]; // Cadena para capturar el texto
    char aux[100];
    printf("Ingresa un texto: ");
    scanf("%[^\n]", x);
    pasaMinuscula(x);
    printf("Texto en mayusculas: %s\n", x);
    invertir(x,aux);
    printf("Texto Ivertido: %s\n", aux);
    return 0;
}

void pasaMinuscula(char *texto) 
{
    while (*texto) 
    {
        *texto = (*texto >= 'A' && *texto <= 'Z') ? *texto + 32 : *texto; // de Mayuscula a Minuscula
        // *texto = (*texto >= 'a' && *texto <= 'z') ? *texto - ('a' - 'A') : *texto; // de minuscula a mayuscula
        texto++;
    }
}
void mayu(char x[])
{
 int i=0;
 while(x[i])
   {
       x[i]=((x[i]>='a')&&(x[i]<='z'))?x[i]-32:x[i];//suma 32 si es Mayuscula
       i++;
   }
 x[i]='\0';

}

void invertir(char x[],char z[])
{
  int i=0,dim=strlen(x), j=strlen(x);
    while(i<dim)
    {
      z[i]=x[j-1];
      i++; j--;
    }
     z[i]='\0';
     //z[i+1]='\n';
}

