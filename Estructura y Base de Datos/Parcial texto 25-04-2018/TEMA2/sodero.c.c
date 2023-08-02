#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define p printf
#define s scanf

void mostrar(FILE*);
void cargar(FILE*, FILE*);

void cargar(FILE *o,FILE*d){
char linea[80];
int cant;
int renglon=0;
int palLarga=0;

rewind(o);
rewind(d);

 while(fgets(linea, 80+1, o)!=NULL){
    cant = cantPal(linea);
    palLarga=masLarga(linea);
    p("%s",linea[1]);
    //p("Linea: %d, cantidad de palabras: %d, palabra mas larga: %d \n", ++renglon, cant,palLarga);

    fputs(linea,d);
 }
}

void mostrar(FILE *x){
 char linea[80];
 rewind(x);

 while(fgets(linea,80+1,x)){
    p("%s",linea);
    getch();
}
}

void mayus(char x[]){

    int i=0;
    while(x[i]!='\0'){
        x[i]=(x[i]>='a'&&x[i]<='z')?(x[i]-32):x[i];
        i++;
    }
    x[i]='\0';

}

int cantPal(char cad[]){

 int c = 0, i = 0;
 while(cad[i]){
    while(cad[i]==' ' && cad[i]!='\n') i++;
    ++c;
    while(cad[i]!=' '&&cad[i]) i++;
 }
return c;
}

int masLarga(char c[]){
//cont = contador de letras
//z = cantidad de letras mayor
 int i = 0, cont = 0, z = 0 ;
 char copia[20];
while(c[i]){
    while(c[i]==' ' && c[i]){
        cont = 0;
        i++;
    }
    while(c[i]!=' ' && c[i]) {
        cont++;
        i++;
    }
    if(cont>z){
        z=cont;
    }
 }
 return z;
}

int main(){

 FILE *origen, *destino;
 char *nom1="texto.txt", *nom2="texto2.txt" ;
 int j,cuenta;

 system("cls");
 system("color 9f");

 origen=fopen(nom1,"r+");
 destino=fopen(nom2,"r+");

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
