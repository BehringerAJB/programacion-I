/*

FECHA 25-04-18
PARCIAL 1° DE ESTRUCTURA Y BASE DE DATOS
TURNO NOCHE
ALUMNO IGNACIO W. EGEL
TEMA 2

EJERCICIO: MOSTRAT TEXTO 1
BUSCAR LA PALABRA MAS LARGA DE CADA RENGLON
PASAR A MAYUSCULA LA PALABRA MAS LARGA DE CADA RENGLON
CARGAR EN TEXTO 2
MOSTRAR TEXTO 2

*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define p printf
#define s scanf

void mostrar(FILE*);
void cargar(FILE*, FILE*);
void buscadorDePalabraMasLarga(char[],int);
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
char cadena[80];
int renglon=0;

        while(fgets(cadena,81,x)){
            buscadorDePalabraMasLarga(cadena,renglon);
            renglon++;
           }
           rewind(x);
             while(fgets(cadena, 81, x)){
                    palabraMasLargaAMayus(cadena, y);
                }


}


void mostrar(FILE *x)
{
char cadena[80];

                while(fgets(cadena, 81, x)!=NULL){
                    p(cadena, x);
                }
}


void buscadorDePalabraMasLarga(char cad[],int reng){
    int indice = 0;
    int indiceAux = 0;
    char palabra[81] = "";
    char aux[81] = "";

    while(cad[indice] != '\n'){
        if(cad[indice] != ' '){
            if(cad[indice + 1] == '\n'){
                aux[indiceAux] = cad[indice];
                if(strlen(aux) > strlen(palabra))
                    strcpy(palabra, aux);
            }
            else{
                aux[indiceAux] = cad[indice];
                indiceAux++;
            }
        }
        else{
            indiceAux = 0;
            if(strlen(aux) > strlen(palabra))
                strcpy(palabra, aux);
        }
        indice++;
    }
    }



     void palabraMasLargaAMayus(char cadena[], FILE * archivo){
    int indice = 0;
    int indiceAux = 0;
    char palabra[81] = "";
    char aux[81] = "";

    while(cadena[indice] != '\n'){
        if(cadena[indice] != ' '){
            if(cadena[indice + 1] == '\n'){
                aux[indiceAux] = cadena[indice];
                if(strlen(aux) > strlen(palabra))
                    strcpy(palabra, aux);
            }
            else{
                aux[indiceAux] = cadena[indice];
                indiceAux++;
            }
        }
        else{
            indiceAux = 0;
            if(strlen(aux) > strlen(palabra))
                strcpy(palabra, aux);
        }
        indice++;
    }

    char * ocurrencia = strstr(cadena, palabra);
    indice = 0;

    while(ocurrencia[indice] != ' ' && ocurrencia[indice] != '\n'){
        if(ocurrencia[indice] >= 'a' && ocurrencia[indice] <= 'z')
            ocurrencia[indice] = ocurrencia[indice] - 32;
        indice++;
    }

    fputs(cadena, archivo);
}

