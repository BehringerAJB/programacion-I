#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define p printf
#define s scanf

//Parcial de Laureano Tula


void mostrar(FILE*);
void cargar(FILE*, FILE*);
char buscarvocal(char []);
void mayu(char []);




int esvocal(char x){
    int i;
    char vocal[] = {'a','e','i','o','u','A','E','I','O','U'};

  //  while (x != '\0')
    for(i=0;i<10;i++)
     {
        if (vocal[i] == x)
        {
            //      p("\n entro %c\n",x);
            return 1;
        }
    }
 return 0;
}




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

 void cargar (FILE *x, FILE *y)
{
    char cad[81], aux[81];
    while (fgets(cad,81,x))
    {
        buscarvocal(cad);
        fputs(cad,y);
    }
}

void mostrar(FILE* x){
char cad[81];
while (fgets(cad,81,x)){
    p("%s",cad);

}}



/*

void mayu(char x[]){
int i = 0;

    while(x[i]){

        x[i]=(x[i]>='a'&& x[i]<='z')?x[i]-32:x[i];
        i++;
}
x[i]='\0';
}
*/

char buscarvocal(char x[]){
int i=0, j=0;
char aux[80]=" ";

for (i=0; x[i] != '\0'; i++)
    {
  //  p("\n -%c- \n",x[i]);
    if ( (esvocal(x[i])) && (( i == 0 ) || ( x[i-1] == ' ' )) )
    {
        while((x[i]!=' ')&&(x[i]))
        {
            x[i]=(x[i]>='a'&& x[i]<='z')?x[i]-32:x[i];
            i++;
        }
    }


}
}




