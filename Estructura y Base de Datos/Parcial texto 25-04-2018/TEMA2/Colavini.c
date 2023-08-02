#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define p printf
#define s scanf

void mostrar(FILE*);
void cargar(FILE*, FILE*);
void mayu(char x []);
//void palabralarga(FILE*x,char x []);
void larga(char[],char[],FILE*y);

int main()
{

 FILE *origen, *destino;
 char cad [80];
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
void cargar(FILE *x,FILE*y)
{
char cad[80];
    while (fgets(cad,80,x)!=NULL)
    {

        mayu(cad);
        fputs(cad,y);

       }

}


void mostrar(FILE *x)
{

char cad [80];

 while (fgets(cad,80,x)!=NULL)
    {

        p("%s",cad);

}

}

 void mayu (char x [])
    {

        int i = 0;
        while (x[i])  /* WHILE (X[I]!='\0')*/
        {
        x[i]=(x[i]>='a' && x[i]<='z')?x[i]-32:x[i];
        i++;
        }
    }










/*
void palabralarga(FILE* x,char x[])


    int cantidadLetra,palabraLarga=0,i=0,max;
    char caracter;
    char palabraextensa[20];
    int flag=0;
    while(x[i])
    {
       palabra=0;

       while((x[i]!=' ')&&(x[i]))
       {
        cantidadLetra++;
        i++;
        while (x[i]==' ')
        {

        }
        if (flag==1)

        palabra[cantidadLetra]=caracter;
        cantidadLetra++;

       }
       palabra[cantidadLetra]='\0';
       if (cantidadLetra>palabraLarga)
        {
        palabraLarga=cantidadLetra;
       strcpy(palabraextensa,palabra);
       }
    }

    p("%s",palabraextensa);

}



*/

