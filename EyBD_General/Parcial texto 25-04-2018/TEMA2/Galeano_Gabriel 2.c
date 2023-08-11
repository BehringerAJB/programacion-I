#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define p printf
#define s scanf


void cargar(FILE *x, FILE *y,int c, int z)
{
    int k=0,j=0;
    while(!feof(x))
    {

        if(k==c-1)
        {
            while(j<z)
            {fputc(toupper(fgetc(x)),y);}
            fputc(fgetc(x),y);
        }
        else
        {
            if(fgetc(x)==0)
            {
                k++;
            }
            fputc(fgetc(x),y);
        }

    }
}


int cantPal(char cad[],int z){

 int c = 0, i = 0, j=0;
 while(cad[i] && j!=z){
    while(cad[i]==' ' && cad[i]!='\n')
    {i++;
    j++;}
    ++c;
    while(cad[i]!=' '&&cad[i]) i++;
 }
return c;
}

int masLarga(char c[]){
//cont = contador de letras
//z = cantidad de letras mayor
 int i = 0, cont = 0, z = 0 ;
 char copia[20];
while(c[i]){
    while(c[i]==' ' && c[i]){
        cont = 0;
        i++;
    }
    while(c[i]!=' ' && c[i]) {
        cont++;
        i++;
    }
    if(cont>z){
        z=cont;
    }
 }
 return z;
}
int main()
{


FILE *origen, *destino;
 char *nom1="texto.txt", *nom2="texto2.txt" ;
 system("cls");
 system("color 9f");
 origen=fopen(nom1,"r+");
 destino=fopen(nom2,"w+");
 char cadena[80];
 int z,c;
 while(fgets(cadena,80,origen))
 {z=masLarga(cadena);}
 while(fgets(cadena,80,origen))
 {
     c=cantPal(cadena,z);
 }
 cargar(origen,destino,c,z);
}
