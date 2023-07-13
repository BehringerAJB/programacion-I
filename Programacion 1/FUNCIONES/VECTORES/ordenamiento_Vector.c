
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
//#include <unistd.h>

#define n 5
void ordenar(int [],int );
void MostrarVector(int [],char *);
void CargarVector(int[],int, char *);
void pausa(void);

int main()
{
    int vec[n];
    srand(time(NULL));
    CargarVector(vec,n, "Carga de Datos");
    MostrarVector(vec, "Vector Desordenado");
    pausa();
    ordenar(vec,n);
    MostrarVector(vec, "Vector Ordenado");
    pausa();
return 0;
}

void CargarVector(int x[], int y, char *tit)
{
    int i;
    char *dot="*";
    printf("\n%s\n",tit);
    for (i = 0; i < n; i++)
    {
        x[i]=rand()%(200-10+1)+10; // genero numeros aleatorios entre 10 y 200
        //sleep(1);  // Retraso de 1 segundo
        // activar libreria #include <unistd.h>
        printf(" %s ",dot);

    }
    
}

void ordenar(int x[],int y)		
{		
	// y posse laa cantidad de valores a Ordenar
    int i,cota=y-1,k=1,aux;	// k es una bandera, que me indica que se termino de ordenar
	while(k)	
	{	
	        k=0;	// partimos del supuesto que esta ordenado
	        for(i=0;i<cota;i++)	
	        {	
	            if(x[i]>x[i+1])	
	            {	
	                // aqui se produce el swap
                    aux=x[i];	
	                x[i]=x[i+1];	
	                x[i+1]=aux;	
	                k=i;	// aqui k toma el valor donde fue ordenado por ultima vez
	            }	
	       }	
	cota=k;	// aqui se lo pasa a cota, con lo cual lo limita en las iteracioners
	}	
}		

void pausa()
{
    printf("\nPresiona Enter para continuar...\n");
    fflush(stdin); // Limpia el búfer de salida para asegurarse de que se muestra el mensaje
    while (getchar() != '\n'); // Lee y descarta cualquier carácter ingresado hasta que se presione Enter
}
void MostrarVector(int x[], char *tit)
{
    int i;
    printf("\n%s\n",tit);
    for (i = 0; i < n; i++)
    {
        printf("%3d\n",x[i]);
    }
}