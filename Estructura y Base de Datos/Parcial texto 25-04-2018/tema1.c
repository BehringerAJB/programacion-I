#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
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
void cargar(FILE *x,FILE*y)
{
    int i=0;
    int j=0;
    char cadena[81], vocal[10]="aeiouAEIOU";
    while(fgets(cadena,81,x))
    {
        for(j=0;j<=10;j++)
            {
                if(cadena[i]==vocal[j])
                {
                      while(cadena[i]!=' ')
                        {
                            fputc(cadena[i]-32,y);
                            printf("%c",cadena[i]);
                            i++;
                        }
                printf("\n");
                }
            }
         while(cadena[i]!='\n'&&cadena[i]!=EOF&&cadena[i]!='\0')
            {
             for(j=0;j<10;j++)
             {
                 if((cadena[i]==vocal[j])&&(cadena[i-1]==' '))
                    while(cadena[i]!=' '&&cadena[i]!='\n'&&cadena[i]!=EOF&&cadena[i]!='\0')
                    {
                        fputc(cadena[i]-32,y);
                        printf("%c",cadena[i]);
                        i++;
                    }
             }
             fputc(cadena[i],y);
             i++;
            }
    fputc('\n',y);
    i=0;

    }
}

void mostrar(FILE *x)
{
    char cad[81];
    while(fgets(cad,81,x)!=NULL)
              p("%s",cad);
}

