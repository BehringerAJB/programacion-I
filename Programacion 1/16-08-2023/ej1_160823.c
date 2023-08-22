#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

#define n 20
/*
ENUNCIADO
Dado un vector de 20 posiciones, necesitamos cargar números aleatorios del 1 al 200 en un vector llamado VecOriginal. 
Se pide que puedas generar otro vector llamado Vecprimos con los números que cumplan con la condicion de Primo. Sacados del Vector Original.
Luego llamar a una función de ordenamiento para mostrar el vector de primos en forma creciente.

*/
void ordenar(int [],int );
void pausa();
void MostrarVector(int [], char *, int);
void CargarVector(int [], int);
void CargaValoresPrimos(int [],int [],int, int *);

int main()
{
    int Vecoriginal[n]={0};
    int Vecprimos[n]={0};
    srand(time(NULL));
    int i=0; // indice para controlar la cantidad de elementos de numeros Primos en el Vector
    CargarVector(Vecoriginal, n);
    MostrarVector(Vecoriginal,"Vector Original",n);
    CargaValoresPrimos(Vecoriginal,Vecprimos,n,&i);
    MostrarVector(Vecprimos,"Vector de Primos Sin Ordenar",i );
    ordenar(Vecprimos,i);
    MostrarVector(Vecprimos,"Vector de Primos Ordenado",i );
    return 0;
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
void MostrarVector(int x[], char *tit, int tam)
{
    int i;
    printf("\n*****************************\n");
    printf("%s",tit);
    printf("\n*****************************\n");
    for (i = 0; i < tam; i++)
    {
        printf("%3d\n",x[i]);
    }
}
void CargarVector(int x[], int tam)
{
     int i;
    for ( i = 0; i < tam; i++)
    { 
        x[i] = rand()%(200-1+1)+1;   
    }
}
void CargaValoresPrimos(int x[],int y[],int tam,int *z)
{
    int i,j,r;
    for ( i = 0; i < tam; i++)
    { 
       r=0;
       for ( j = 1; j <= x[i]; j++)
       {
            if ((x[i]%j)==0)
            {
                r++;
            }  
       }
       if (r==2)
       {
        y[*z]=x[i];
        *z=*z+1;
       }
    }
    
}