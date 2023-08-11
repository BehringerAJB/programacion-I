#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define p printf
#define s scanf

/*
 * PROTOTIPOS
 */

void cargar(FILE*, FILE*);
void hacerMayus(char[], FILE*);
void mostrar(FILE*);

int main() {

    FILE *origen, *destino;
    char *nom1="texto.txt", *nom2="texto2.txt" ;
    int j, cuenta;
 //system("cls");
 //system("color 9f");
    origen = fopen(nom1,"r+");
    destino = fopen(nom2,"w+");

    cargar(origen, destino);

    rewind(origen);
    p("\n Presione una tecla para visualizar el contenido del archivo origen:%s\n\n",nom1); //getch();
    mostrar(origen); //getch();

    rewind(destino);
    p("\n Presione una tecla para visualizar el contenido del archivo destino:%s\n\n",nom2); //getch();
    mostrar(destino); //getch();

    p("\n \nPresione una tecla para salir del Programa******");
//getch();
//system("cls");
    fclose(destino);
    fclose(origen);

 return(0);
}

void cargar(FILE *origen, FILE*destino) {
    char cadena[80];

    if( origen != NULL && destino != NULL ){
        fgets(cadena, 80, origen);
        while ( !feof(origen) ){
            hacerMayus(cadena, destino);
            fgets(cadena, 80, origen);
        }
    } else {
        p("Alguno de los archivos no pudo ser abierto o no existe.\n");
    }
}

void hacerMayus(char cadena[], FILE* destino){
    char *token;
    int i;

    token = strtok(cadena, " ");
    while (token != NULL ){
       if ( token[0] == 'a'
            || token[0] == 'e'
            || token[0] == 'i'
            || token[0] == 'o'
            || token[0] == 'u'
            || token[0] == 'A'
            || token[0] == 'E'
            || token[0] == 'I'
            || token[0] == 'O'
            || token[0] == 'U'){

            i = 0;
            while(token[i]!='\0'){
                if ( token[i] >= 'a' && token[i] <= 'z' ){
                    token[i] = token[i]-32;
                } else token[i] = token [i];
                i++;
            }
        }
        fputs(token, destino);
        fputs(" ", destino);
        token = strtok(NULL, " ");
    }
}

void mostrar(FILE *archivo) {
    char cadena[80];
    p("\n\n");
    do{
        fgets(cadena, 80, archivo);
        p("%s\n", cadena);
    } while ( !feof(archivo) );
    p("\n\n");
}
