#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main() 
{
    int inter; // los estados de los interruptores
    int cont=0; // cuantos interuptores estan encendidos
    int i; // me cuenta la cantidad de interruptores que podre encender
    for ( i = 0; i < 3; i++)
    {
        // vamos a validar si el interruptor
        // le han colocado un dato cierto
        // pueden ser 0 apagado, 1 prendido
        do
        {
            printf("Ingrese el estado del interruptor:%d\n<0 apagado //  1 Prendido",i+1);
            scanf("%d",&inter);
        } while (inter!=0 && inter!=1);
        if(inter)
            cont++;
    }
    printf("El total de lamparas encendidas es:%d\n", cont);
    return 0;
}   