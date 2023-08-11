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
    char vocales[] = {'a','e','i','o','u','A','E','I','O','U'};
    char cadena[80];
    int i;
    int v;
    int j;
    while (fgets(cadena,81,x)!=NULL && !feof(x))
    {
        i=-1;
        while (cadena[i]!='\0')
        {
            if (cadena[i]!=" ")
            {
                v=0;
                for (j=0;j<=10;j++)
                {
                    if (cadena[i]==vocales[j])  v=1;
                }
                if (v==1)
                {
                    do
                    {
                        if(cadena[i]>='a'&&cadena[i]<='z')
                        {
                            cadena[i]=cadena[i]-32;
                        }
                        i++;
                    }
                    while (cadena[i]!=" ");
                    i++;
                }
            }
            else
                i++;
        }
        fputs(cadena,y);
    }
}

void mostrar(FILE *x)
{
    char cadena[80];
    while (fgets(cadena,81,x)!=NULL && !feof(x))
    {
        printf ("%s",cadena);
    }
}

/*strcpy(proc,"");
        cort=strtok(cadena," ");
        while (strcmpi(cort,"\n")!=0)
        {
            v=0;
            for (i=0;i<=10;i++)
            {   if (cort[0]==vocales[i]) v=1;
            }
            if (v==1)
            {
                for (i=0;cort[i]!='\0';++i)
                {
                    if(cort[i]>='a'&&cort[i]<='z')
                    {
                        cort[i]=cort[i]-32;
                    }
                }
            }
            strcat(cort," ");
            strcat(proc,cort);
            p("->%s",proc);
            cort=strtok(NULL," ");
        }
        fputs(proc,y);
        fgets(cadena,81,x);
        */
