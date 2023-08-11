#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

#define p printf
#define s scanf

void mostrar(FILE*);
void cargar(FILE*, FILE*);
void mayus (char [], int, int);

int main() {

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

void cargar(FILE *x,FILE*y) {
    char cad[81];

    while(fgets(cad,81,x)) {
        int i = 0, j = 0;
        int largo = 0, largomax = 0;
        int posicion = 0;


        while (cad[i]!='\n') {
            while(cad[i] == ' ' && cad[i]!='\n')//x[i]!='\0'
                i++;
            while(cad[i] != ' ' && cad[i]!='\n'){//x[i]!='\0'
                i++;
                j++;
            }
            largo = j; //largo de la palabra
            j = 0;

            if (largo > largomax) {
                largomax = largo;//largo maximo de la palabra
                posicion = i;//posicion en la cadena
            }
        }
        mayus(cad, posicion - largomax, posicion - 1);
        fputs(cad,y);

    }
}

void mostrar(FILE *x) {
    char cad[81];
    while (fgets(cad,81,x)){
        p("%s",cad);
    }
}

void mayus(char z[], int min, int max) {
    int i = 0;
    while (z[i]) {
        if((i >= min) && (i <= max))
            z[i] = (z[i]) - 32;
        else
            z[i] = z[i];
        i++;
    }
    z[i] = '\0';
}
