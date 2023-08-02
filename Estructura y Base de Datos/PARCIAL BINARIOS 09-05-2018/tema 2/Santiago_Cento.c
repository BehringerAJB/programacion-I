#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#define s scanf

typedef struct{
  int cod_prof;
  char nom_prof[30];
  int cant_insp;
  int horas;
} registro;

void ingresar(FILE*);
void mostrar(FILE*);
int buscaRegistro(FILE*,int,int);
int error(char*);
void tecla(void);

int main(){
	FILE *horas;
	char nomArchHoras[]="Profesionales.dat";
	system("cls");
	if((horas=fopen(nomArchHoras,"wb+"))==NULL)
		exit(error(nomArchHoras));
	printf("\nEl archivo %s ha sido cargado!!\n",nomArchHoras);
	tecla();
	system("cls");
	ingresar(horas);
	system("cls");
	mostrar(horas);
	tecla();
	fclose(horas);
	return(0);

}

void mostrar(FILE *x){
  registro c;
    rewind(x);
	system("cls");
	printf("\n\n\t\t\tNomina de Profesionales\n\n",224);
	printf("\nN de Profesional  NOMBRE\tCant. Inspecciones\tHoras totales Sueldo\n");
	fread(&c,sizeof(c),1,x);
	while(!feof(x)){
		printf("\n\t%d\t%s\t\t\t%d\t\t\t%d\t%d\n",c.cod_prof,c.nom_prof,c.cant_insp,c.horas,c.horas*250);
		fread(&c,sizeof(c),1,x);
	}
	printf("\n");
}

void ingresar(FILE *archHoras){
 int inspeccion,profesional,cantHoras,b=0;
 char nomProf[30];
 registro p;
 printf("\nINGRESE NUMERO DE INSPECCION O CERO PARA FINALIZAR: ");
 s ("%d",&inspeccion);
 while(inspeccion!=0){
    printf("\nINGRESE codigo de Profesional: ");
    s ("%d",&profesional);
    printf("\nINGRESE cantiadad de horas: ");
    s ("%d",&cantHoras);
    b=buscaRegistro(archHoras,profesional,cantHoras);
    if(b==0){
        printf("\nINGRESE Nombre de Profesional: ");
        fflush(stdin);
        gets(nomProf);
        p.cod_prof=profesional;
        strcpy(p.nom_prof,nomProf);
        p.cant_insp=1;
        p.horas=cantHoras;
        fseek(archHoras,0,SEEK_END);
        fwrite(&p,sizeof(p),1,archHoras);
    }
     printf("\nINGRESE NUMERO DE INSPECCION O CERO PARA FINALIZAR: ");
     s ("%d",&inspeccion);
  }
}

int buscaRegistro(FILE* archivo,int codigo,int horas){
    rewind(archivo);
    registro p;
    fread(&p,sizeof(p),1,archivo);
    while(!feof(archivo))
        {

        if(p.cod_prof==codigo)
        {
            p.horas=p.horas+horas;
            p.cant_insp=p.cant_insp+1;
            fseek(archivo,-1l *sizeof(p),SEEK_CUR);
            fwrite(&p,sizeof(p),1,archivo);
            return 1;
        }
       fread(&p,sizeof(p),1,archivo);
    }
    return 0;
}

int error(char *x){
	fprintf(stderr,"no se puede abrir el archivo %s",x);
	return(1);
}
void tecla(void){
	printf("\n\nPRESIONE CUALQUIER TECLA PARA CONTINUAR!!!");
	getch();
}




