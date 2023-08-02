#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define p printf
#define s scanf

void mostrar(FILE*);
void cargar(FILE*, FILE*);
char cambiar(char);
int dimension(char*);
int palabraLarga(char*,char*);

int main(){
 FILE *origen, *destino;
 char *nom1="texto.txt", *nom2="texto2.txt" ;
 int j,cuenta;
 system("cls");
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
void cargar(FILE *x,FILE*y){
    char cad[80],pal[80],aux[80]=" ";
    int empieza,termina,i;
    while(fgets(cad,81,x)!=NULL){
        strcpy(aux,cad);
        empieza=palabraLarga(cad,pal);
        i=0;
        termina=dimension(pal);
        while(aux[i]){
            if(i>=empieza&&i<empieza+termina){
                aux[i]=cambiar(aux[i]);
            }
            i++;
          }
        fputs(aux,y);
    }
 }

char cambiar(char x){
    if((x>='a')&&(x<='z')){
        x=x-32;
    }
  return x;
}

void mostrar(FILE *x){
    char cad[81];
    while(fgets(cad,81,x)!=NULL) p("%s",cad);
}

int dimension(char *x){
    int i=0;
    while(x[i]) i++;
    return i;
}

int palabraLarga (char*x,char*y){ // De cada renglón devuelve en donde esta y cual es la 1º palabra mas larga si hay + de una
    int i=0,j,maxima=0,empieza=0,largo;
    char aux[80];
    while(x[i]){
        while(x[i]==' ') i++;
        j=0;
        empieza=i;
        while((x[i]!=' ')&&(x[i])){
          aux[j++]=x[i++];
          aux[j]='\0';
         if(dimension(aux)>maxima){
             maxima=dimension(aux);
             strcpy(y,aux);
             largo=empieza;
         }
        }
    }
    return largo; // devuelve en que posición de la cadena empieza
}

