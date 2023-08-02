
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int *p , *q ;
    int a=5;
    printf("direccion de a:%x, contenido de a%2d\n\n",&a,a);
    printf("\n---------------------------------------------------------------------------\n");
    p=(int*) malloc (sizeof (int));
    p=&a;
    
    printf (" Contenidos de p y q \n");
    printf ("direccion de p[%x], p apunta a la direcci%cn %x que contiene %2d\n ",&p,162,p,*p);
    printf ("q apunta a la direcci%cn %x que contiene %2d\n",162,q,*q);
    printf("\n---------------------------------------------------------------------------\n");
    q=p;
    *q=2;
    printf (" Contenidos de p y q Cambiados\n");
    printf ("direccion de p[%x], p apunta a la direcci%cn %x que contiene %2d\n ",&p,162,p,*p);
    printf ("q apunta a la direcci%cn %x que contiene %2d\n",162,q,*q);
    printf("\n---------------------------------------------------------------------------\n");
    q= (int *) malloc (sizeof(int));
    *q=8;
    printf ("p apunta a la direcci%cn p=%x que contiene %2d\n",162,p,*p);
    printf ("q apunta a la direcci%cn q=%x que contiene %2d\n",162,q,*q);
    printf("\n---------------------------------------------------------------------------\n");
    free (q);
    free (p);
    return 0;
}

