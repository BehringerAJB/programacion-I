#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#define p printf
#define s scanf

void mostrar(FILE*);
void cargar(FILE*, FILE*);

int main()
{
    FILE *origen, *destino;
    char *nom1="texto.txt", *nom2="texto2.txt" ;
    int j,cuenta;
    system("cls");
    system("color 9f");
    origen=fopen(nom1,"r+");
    destino=fopen(nom2,"w+");
    cargar(origen, destino);
    rewind(origen);
    p("\n Presione una tecla para visualizar el contenido del archivo origen:%s\n\n",nom1); getch();
    mostrar(origen); getch();
    rewind(destino);
    p("\n Presione una tecla para visualizar el contenido del archivo destino:%s\n\n",nom2); getch();
    mostrar(destino); getch();
    p("\n \nPresione una tecla para salir del Programa******");
    getch();
    system("cls");
    fclose(destino);
    fclose(origen);
    return(0);
}

void mayu(char x[]){
    int i = 0,c=0,flag=0;
    while(x[i])
    {
        flag=0;
        while(x[i] != ' ' && x[i])
        {
            if(c==0 && x[i]=='A'||x[i]=='a'||x[i]=='E'||x[i]=='e'||x[i]=='I'||x[i]=='i'||x[i]=='O'||x[i]=='o'||x[i]=='U'||x[i]=='u')
                flag=1;
            if(flag==1 && x[i] >= 'a' && x[i] <= 'z')
            {
                while(x[i] != ' ' && x[i])
                {
                    x[i] = x[i]-32;
                    i++;
                }
                flag=0;
            }
            else
                x[i];
            i++;
            c++;
        }
        c=0;
        i++;
    }
    x[i] = '\0';
}

void cargar(FILE *x,FILE*y)
{
    char linea[80];
    while(fgets(linea,81,x))
    {
        mayu(linea);
        fputs(linea,y);
    }
}


void mostrar(FILE *x)
{
    char cod[81];
    while(fgets(cod, 81, x))
        {
        p("%s", cod);
    }
}

