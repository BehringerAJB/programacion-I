#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define p printf
#define s scanf

/***********************************************************************/

void mostrar(FILE *x){
    char cad[81];
    while(fgets(cad,81,x)){
        p("%s",cad);
    }
}

/***********************************************************************/

char pasarMayu(char x){
    if((x>='a')&&(x<='z'))
        return (x-32);
    else
        return (x);
}

/***********************************************************************/

void cargar(FILE *x,FILE*y){
   char cad[81];
   //int i=0, bool=0;// bool 0=false, 1=true;
   int i, bool;
   while(fgets(cad,81,x)!=NULL){//mientras levanta
      i=0;
      while(cad[i]){//RENGLON POR RENGLON
        while(cad[i]==' ' && cad[i]) i++; //RENGLON.
           // i++;
        bool=0;
        /*if(cad[i]=='a' || cad[i]=='e' || cad[i]=='i' || cad[i]=='o' || cad[i]=='u'){
            bool=1;
            break;  }*/
         switch(cad[i]){
             case 'a':
                 bool=1;
                 break;
             case 'e':
                 bool=1;
                 break;
             case 'i':
                 bool=1;
                 break;
             case 'o':
                 bool=1;
                 break;
             case 'u':
                 bool=1;
                 break;
        }
        if(bool==1){//if(true)
            while(cad[i]!=' ' && cad[i]){
                cad[i]=pasarMayu(cad[i]);
                i++;
            }
        }else while(cad[i]!=' ' && cad[i])i++;
      }//return(cad,y);
      fputs(cad,y);
    }
      //fputs(cad,y);
}

/***********************************************************************/

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
