#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define p printf
#define s scanf

void cargar(FILE *x,FILE*y){
    char *resultado[100];
    char cadena [81];
    if (!feof(x)==NULL || !feof(y)==NULL){
        p("El archivo no se pudo encontrar");
    }else{
        while (fgets(cadena,81,x)!=NULL){
            strParse(cadena,resultado);
            fprintf(y,"%s",resultado);
        }
    }

}

void mostrar(FILE *x){
    char cadena [81];
    if (!feof(x)==NULL){
        p("El archivo no se pudo encontrar");
    }else{
        while (fgets(cadena,81,x)!=NULL){
            p("%s", cadena);
        }
    }
}

void strParse(char *c[], char *resultado[]){
    char *devuelve[100];
    char *original[100];
    char *aux[20];
    char *auxDos;
    char *largo[20];
    strcpy(original, c);
    //p("%s", original);

    strcpy(aux,strtok(c, " "));
    strcpy(largo,aux);

    while ((auxDos = strtok(NULL, " ")) != NULL){
        if(strlen(auxDos) > strlen(largo))
            strcpy(largo,auxDos);
    }

    encontrarReemplazar(strToUpper(largo),original, devuelve);
    strcpy(resultado, devuelve);
}

void encontrarReemplazar(char *largo, char *original[], char *devuelve[]){
    FILE *f = fopen("texto2.txt", "w");
    char *aux[20];
    char *auxDos;
    char *resultado[100];
    int i=0;

    strcpy(aux,strtok(original, " "));
    if(strlen(aux) == strlen(largo)) strcpy(resultado, largo);
    else strcpy(resultado, aux);
    while ((auxDos = strtok(NULL, " ")) != NULL){
        if(strlen(auxDos) == strlen(largo)){
            strcat(resultado, " ");
            strcat(resultado, largo);
        }else{
            strcat(resultado, " ");
            strcat(resultado, auxDos);
        }
    }

    strcpy(devuelve, resultado);

}

/*void copiarLinea(char *c[], FILE*f){
    p("%s\n", c);
    fprintf(f, "%s", c);
}*/


void strToUpper(char *str){
    int i;
    char aux[15];
    for(i=0;i<strlen(str);i++){
        appendChar(aux,toupper(str[i]));
    }
    strcpy(str,aux);
}

void appendChar(char *s, char c)
{
    int len = strlen(s);
    s[len] = c;
    s[len+1] = '\0';
}

int main(){

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

