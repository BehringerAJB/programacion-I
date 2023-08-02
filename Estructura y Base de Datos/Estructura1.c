#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>

#define M 5


typedef struct
{
    int cod_rubro;
    char nom_rub[25];
    float precio;
}registro;

void mostrar(registro[]);
void ordenar(registro []);

main()
{
    registro rubro[M]={
                {1,"Automotores",15.25},
                {2,"Oficinas",12.46},
                {3,"Profesionales",14.80},
                {4,"Enseñanza",8.34},
                {5,"Servicios",10.54}
             };
 printf("\nListado Original\n");
    mostrar(rubro);
    ordenar(rubro);
    printf("\nListado ordenado por Nombre\n");
    mostrar(rubro);
    system("pause");
    return 0;
}
void ordenar(registro x[])
{
    int i, k=1,cota=M-1;
    registro aux;
    while(k)
    {
        k=0;
        for(i=0;i<cota;i++)
        {
            if(strcmpi(x[i].nom_rub,x[i+1].nom_rub)>0)
            {
                aux=x[i];
                x[i]=x[i+1];
                x[i+1]=aux;
                k=i;

            }
        }
        cota=k;
    }
}

void mostrar(registro rubro[])
{
     int i;
    for(i=0; i<M; i++)
    {
        printf("\t%3d   %-20s\t\t%3.2f \n  ",rubro[i].cod_rubro,rubro[i].nom_rub,rubro[i].precio);

    }
}
