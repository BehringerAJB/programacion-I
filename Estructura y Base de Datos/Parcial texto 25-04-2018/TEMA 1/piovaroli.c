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
//void cargar(FILE *x,FILE*y)
//{
//    char cadena[100];
//    while(fgets(cadena,101,x))
//    {
//        int i=0;
//        while(cadena[i]!='\0')
//        {
//            cadena[i]=(cadena[i]>='a'&&cadena[i]<='z')?(cadena[i]-32):cadena[i];
//            i++;
//        }
//        cadena[i]='\0';
//        fputs(cadena,y);
//    }
//}


void cargar(FILE *x,FILE*y)
{
    char cadena[100];
    char *ptr;
    char c[4]=" ";
    int i;
    while(fgets(cadena,101,x))
    {
        ptr=strtok(cadena,c);
        if(ptr[0]=='a'||ptr[0]=='e'||ptr[0]=='i'||ptr[0]=='o'||ptr[0]=='u'||ptr[0]=='A'||ptr[0]=='E'||ptr[0]=='I'||ptr[0]=='O'||ptr[0]=='U')
            {
                i=0;
                while(ptr[i]!=" ")
                {
                    ptr[i]=(ptr[i]-32);
                    i++;
                }
                p("%s ",ptr);
                fputs(ptr,y);
            }
//        else
//            {
//                p("%s ",ptr);
//                fputs(ptr,y);
//            }
        while(ptr=strtok(NULL," "))
        if(ptr[0]=='a'||ptr[0]=='e'||ptr[0]=='i'||ptr[0]=='o'||ptr[0]=='u'||ptr[0]=='A'||ptr[0]=='E'||ptr[0]=='I'||ptr[0]=='O'||ptr[0]=='U')
            {
                p("%s ",ptr);
                fputs(ptr,y);
            }
//        else
//            {
//                p("%s ",ptr);
//                fputs(ptr,y);
//            }
    }
}

void mostrar(FILE *x)
{
    char cadena[100];
    while(fgets(cadena,101,x))
    {
        p("%s",cadena);
    }
}

