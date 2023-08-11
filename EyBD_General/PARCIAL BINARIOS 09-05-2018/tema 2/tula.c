#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define p printf
#define s scanf



typedef struct
{
 int cod_prof;
 char nom_prof[30];
 int cant_insp;
 int horas;
 } registro;


 void linea(int x)
{
 int i;
	for(i=1;i<x;i++)
	p("*");
 p("\n");
}


 void tecla()
{
 p("\nPresione un tecla para continuar\n");

 system("pause");
//  getch();
 system("cls") ;
}







float mostrar(FILE *x)
{
	registro r;
	rewind(x);
	p("\n \t\t\t  Profesionales \n\n");
	p("\n Num Prof \tProfesor  \t Cant de insp \t Cant de horas totales \t Sueldo \n");
    linea(80);
	fread(&r,sizeof(registro),1,x);
	while(!feof(x))
		{

		//Completar la función
		p("\n %3d \t\t%-20s \t %d \t\t %d \t\t %d \n\n",r.cod_prof,r.nom_prof,r.cant_insp,r.horas,((r.horas)* 250));
		fread(&r,sizeof( registro),1,x);
		}

}




 void cargar(FILE *x)
{
	registro datos;
    int bar;
    int cod, caninsp, horas, aux;



    p("\n Ingrese Cod. del Profesor [0 para salir]:");

    s("%d",&cod);
    while(cod!=0){
            rewind(x);
            bar=0;
            fread(&datos, sizeof(datos), 1, x);
            p("%d %s",datos.cod_prof,datos.nom_prof);
            while(!feof(x) && bar==0){

                if(cod!=datos.cod_prof){
                    fread(&datos, sizeof(datos), 1, x);
                }else{
                    p("\n El profesor ya ha sido cargado!!\n");
                    system("pause");
                    //getch();
                    bar = 1;
                    break;
                }

            }

            if(bar==0){

                fflush(stdin);
                datos.cod_prof=cod;
                p("\nIngrese nombre del Profesor  ");
                s("%[^\n]", datos.nom_prof);
                p("\nIngrese la cantidad de horas: ");

                s("%d",&horas);

                datos.horas = horas;
                //datos.horas = aux + horas;

                datos.cant_insp= 1;
                fseek(x,0L,SEEK_END);
                fwrite(&datos, sizeof(datos), 1, x);

            }else {
                 p("\nIngrese la cantidad de horas: ");
                fflush(stdin);
                s("%d",&horas);

                datos.horas += horas;
                datos.cant_insp++;
                fseek(x,sizeof(datos)*(-1L),SEEK_CUR);
                fwrite(&datos,sizeof(datos),1,x);
            }

            system("CLS");
                p("\n Ingrese Cod. del Profesor [0 para salir]:");
                fflush(stdin);
                s("%d",&cod);
    }
}




 int main(){

 FILE *arch;


 char *nomarch="Profesionales.dat";
  system("cls");
  system("color 9f");

if (arch=fopen(nomarch,"rb+") == NULL){
       arch=fopen(nomarch,"wb+");


  p("\nEL ARCHIVO %s HA SIDO ABIERTO PARA ESCRITURA!!!",nomarch);
  }
  else(p("El archivo fue abierto"));
  cargar(arch);
  tecla();
  p("\n  \n\n");
  tecla();
  mostrar(arch);
  linea(80);
  tecla();
  fclose(arch);

    system("pause");
  	//getch();


  	return(0);

 }
