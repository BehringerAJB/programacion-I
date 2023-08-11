#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define p printf
#define s scanf

void mostrar(FILE*);
void cargar(FILE*, FILE*);
int main(){

 FILE *origen, *destino;
 char *nom1="texto.txt", *nom2="destino.txt" ;
 int j,cuenta;
 system("cls");
 system("color 9f");
 origen=fopen(nom1,"r+");
 destino=fopen(nom2,"w+");
 cargar(origen, destino);
 rewind(origen);
 p("\n Presione una tecla para visualizar el contenido del archivo origen:%s\n\n",nom1); getchar();
 mostrar(origen); getchar();
 rewind(destino);
 p("\n Presione una tecla para visualizar el contenido del archivo destino:%s\n\n",nom2); getchar();
 mostrar(destino); getchar();
 p("\n \nPresione una tecla para salir del Programa******");
 getchar();
 system("cls");
 fclose(destino);
 fclose(origen);

 return(0);

}
void cargar(FILE *x,FILE*y){
   //Generar la Función
   char linea[80];
   while(fgets(linea, 81, x) != '\0'){
        aMayusculas(linea, palabraLarga(linea));
        fputs(linea, y);
   }
}

int aMayusculas(char linea[], int numeroDePalabra){
    int i = 0;
    int nPalabra = 1;
    int flag = 0;
    int tamPalabraActual = 0;
    while(linea[i]){
        while(linea[i] == ' ')
            i++;
        while(linea[i] != ' ' && linea[i]){
            tamPalabraActual++;
            if(flag == 1){
                nPalabra++;
                flag = 0;
            }
            if(nPalabra == numeroDePalabra){
                if(linea[i] >= 'a' && linea[i] <= 'z')
                    linea[i] = linea[i] - 32;
            }
            if(nPalabra > numeroDePalabra)
                return;
            i++;
        }
        flag = 1;
    }
}

int palabraLarga(char linea[]){
    int i = 0;
    int nPalabra = 0;
    int flag = 0;
    int tamPalabraActual = 0;
    int max = 0;
    int palabraMasLarga;
    while(linea[i]){
        while(linea[i] == ' ')
            i++;
        while(linea[i] != ' ' && linea[i]){
            tamPalabraActual++;
            i++;
            if(flag == 1){
                nPalabra++;
                flag = 0;
            }
        }
        if(tamPalabraActual > max){
                max = tamPalabraActual;
                palabraMasLarga = nPalabra;
        }
        flag = 1;
        tamPalabraActual = 0;
    }
    palabraMasLarga++;
    //printf("%d \t", palabraMasLarga);
    return palabraMasLarga;
}

void mostrar(FILE *x){
    char cad[81];
    while(fgets(cad,81,x)!=NULL)
        p("%s",cad);
}

