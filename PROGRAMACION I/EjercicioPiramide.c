#include <stdio.h>  // Lista abierta con repeticiones
#include <stdlib.h> // Inserta por la cola en forma secuencial.
#include <conio.h>  // busca un elemento y borra la lista nodo a nodo.
#include <time.h>
#define p printf
#define s scanf

int main()
{
    int elementos=0,cociente=0,resto,aux,linea;
    system("cls");
    p("Ingrese la cantidad de elementos:");
    s("%d",&elementos);
    aux=elementos;
    while(aux)
    {
        cociente=aux/2;
        resto=aux%2;
        linea=cociente+resto;
        //printf("linea:%d Cociente:%d Resto:%d\n",linea,cociente,resto);
        //getch();
        if(aux==2 || aux==1)
        {
            aux=0;
            linea=0;
        }
        else
            {
                aux=cociente+resto;
                //p("aux:%d\n",aux);
            }
        while(linea)
        {
            p(" * ");
            linea--;
        }
        p("\n");
    }
return 0;
}