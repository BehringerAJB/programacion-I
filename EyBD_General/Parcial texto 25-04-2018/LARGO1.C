#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define p printf
#define s scanf
// Captura un texto de varios renglones en un archivo texto.txt
// Cuenta las palabras por renglones y determina cual es la palabra más larga de cada renglón
// Convierte a mayúsculas la palabra más larga de cada renglón.
void mostrar(FILE*);
void cargar(FILE*, FILE*);
int contar(char[]);
int dim(char[]);
int larga(char*,char*);
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
void cargar(FILE *x,FILE*y)
{
    char cad[80],pal[80],aux[80]=" ";
    int ren=1,emp,ter,i;
    while(fgets(cad,81,x)!=NULL)
    {
        strcpy(aux,cad);
        emp=larga(cad,pal);
        p("\nDel Renglon:%d Palabra + larga:%s\n",ren,pal);
        i=0;
        ter=dim(pal);
        while(aux[i])
          {
            if(i>=emp-1&&i<emp+ter-1)
                aux[i]=((aux[i]>='a')&&(aux[i]<='z'))?aux[i]-32:aux[i];
            p("%c",aux[i]); //getch();
            i++;
          }
        fputs(aux,y);
        ren++;
       // getch();
    }
 }

void mostrar(FILE *x)
{
    char cad[81];
    while(fgets(cad,81,x)!=NULL)
              p("%s",cad);
}

int dim(char *x)
{
    int i=0;
    while(x[i]) i++;
    return (i);
}
//            cadena  pal
int larga (char*x,char*y) // De cada renglón devuelve en y la 1º mas larga si hay + de una
{
    int i=0,j,maxi=0,emp=0,lar;
    char aux[80];
    while(x[i])
    {
        while(x[i++]==' ');
        j=0;
        i--;
        emp=i;
        while((x[i]!=' ')&&(x[i]))
          aux[j++]=x[i++];
          aux[j]='\0';
         if(dim(aux)>maxi)
         {
             maxi=dim(aux);
             strcpy(y,aux);
             lar=emp;
         }
    }
    return(lar+1); // devuelve en que posición de la cadena empieza
}



