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
    origen = fopen(nom1,"r+");
    destino = fopen(nom2,"w+");

    cargar(origen, destino);
    rewind(origen);

    p("\n Presione una tecla para visualizar el contenido del archivo origen:%s\n\n",nom1); getch();

    mostrar(origen); getch();
    rewind(destino);

    p("\n Presione una tecla para visualizar el contenido del archivo destino:%s\n\n",nom2); getch();

    mostrar(destino); getch();

    p("\n \nPresione una tecla para salir del Programa******"); getch();
    system("cls");
    fclose(destino);
    fclose(origen);

    return(0);
}

void cargar(FILE *origen,FILE *destino)
{
    /*int cantidadLetras, palabraLarga = 0, i;
    char caracter, palabra[20], palabraExtensa[20], */
    char cadena[100], caracter;
    int cantidad,i;


    if(destino == NULL)
    {
        p("El archivo no se creo correctamente");
    }
    else
    {
        fgets(cadena,100,origen);
        caracter = fgetc(cadena);
        while(caracter != '\n')
        {
            if(caracter != ' ')
            {
               cantidad++;
            }

        }
        if(cantidad < 8)
        {

        }
    }
    rewind(destino);



    caracter = fgetc(destino);

    for(i = 0; i <8; i++)
    {
        if((caracter >= 97) && (caracter <= 122))
        {
            caracter -= 32;
            fputc(caracter, destino);
        }
        else
        {
            fputc(caracter,destino);
        }
        caracter = fgetc(destino);
    }

/*
    while(!feof(destino))
    {
        cantidadLetras = 0;
        caracter = fgetc(destino);
        while((caracter != ' ') && (caracter != '\n') && (!feof(destino)))
        {
            palabra[cantidadLetras] = caracter;
            cantidadLetras ++;
            caracter = fgetc(destino);
        }
        palabra[cantidadLetras] = '\0';

        if(cantidadLetras > palabraLarga)
        {
            palabraLarga = cantidadLetras;
            strcpy(palabraExtensa, palabra);
        }



    }*/
}


void mostrar(FILE *archivo)
{
    char caracter;
    caracter = fgetc(archivo);

    while(!feof(archivo))
    {
        p("%c", caracter);
        caracter = fgetc(archivo);
    }
}







