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
mostrar(origen);
getch();
rewind(destino);
p("\n Presione una tecla para visualizar el contenido del archivo destino:%s\n\n",nom2); getch();
mostrar(destino);
getch();
p("\n \nPresione una tecla para salir del Programa******");
getch();
system("cls");
 fclose(destino);
 fclose(origen);

 return(0);

}
void cargar(FILE *x,FILE*y) { // x es origen, y es destino
    char cad1[80], *cad2;
    int j = 0;
    fgets(cad1,80,x);
    p("%s",cad1);
    cad2 = strtok(cad1," ");
    while (!feof(x)) {
        while (cad2 != NULL) {
            if (cad2[j] == 'a' || cad2[j] == 'e' || cad2[j] == 'i' || cad2[j] == 'o' || cad2[j] == 'u')
                while (cad2[j]) {
                    cad2[j] = cad2[j] - 32;
                    j++;
                }
                fputs(cad2,y);
                fputc(" ",y);
                j = 0;
                cad2 = strtok(NULL," ");
        }
    fputc("\n",y);
    fgets(cad1,80,x);
    cad2 = strtok(cad1," ");
}
}

void mostrar (FILE *x) {
char cad[81];
    while (fgets(cad,81,x))
        p("%s",cad);
}
