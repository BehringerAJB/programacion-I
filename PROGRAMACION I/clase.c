#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

#define n 20
/*
ENUNCIADO
Dado un vector de 20 posiciones, 
necesitamos cargar números aleatorios del 1 al 200 en un vector
 llamado VecOriginal. 
Se pide que puedas generar otro vector llamado Vecprimos 
con los números que cumplan con la condicion de Primo. 
Sacados del Vector Original.
Luego llamar a una función de ordenamiento 
para mostrar el vector de primos en forma creciente.
HOLA
*/
void CargaVector(int[],int);
void mostrarVector(int[],int, char *);
void CargarlosPrimos(int[],int[],int, int*);
void ordenar(int [],int );

int main()
{
    int vecOriginal[n],vecPrimo[n];
    int z=0;
    srand(time(NULL)); // semilla aleatoria
    CargaVector(vecOriginal,n);
    mostrarVector(vecOriginal,n,"Vector Original");
    pausa();
    CargarlosPrimos(vecOriginal,vecPrimo,n,&z);
    mostrarVector(vecPrimo,z,"Vector de primos sin Ordenar");
    ordenar(vecPrimo,z);
    mostrarVector(vecPrimo,z,"Vector de primos Ordenado");
}
void pausa()
{
    printf("\nPresiona Enter para continuar...\n");
    fflush(stdin); // Limpia el búfer de salida para asegurarse de que se muestra el mensaje
    while (getchar() != '\n'); // Lee y descarta cualquier carácter ingresado hasta que se presione Enter
}
void CargaVector(int x[],int y )
{
    int i;
    int cs=200,ci=1;
    for ( i = 0; i < y; i++)
    {
        x[i]=rand()%(cs-ci+1)+ci;
    }
}
void mostrarVector(int x[],int y, char *tit)
{
    int i;
    printf("\n%s\n",tit);
    for ( i = 0; i < y; i++)
    {
        printf("%d\n",x[i]);
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