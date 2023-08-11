#include <stdio.h>  // Lista abierta con repeticiones
#include <stdlib.h> // Inserta por la cola en forma secuencial.
#include <conio.h>  // busca un elemento y borra la lista nodo a nodo.
#include <time.h>
#define p printf
#define s scanf

// 1º Forma de definición
/*struct lista
{
    int dato;
    struct lista*sig;
} ;
typedef struct lista nodo;
*/

//  2º Forma de definición
/*struct  nodo
{
    int dato;
    struct nodo*sig;
} ;
typedef struct  nodo nodo;
*/

//  3º Forma de definición

typedef struct lista
{
    int dato;
    struct lista *sig;
} nodo;

nodo *buscar(nodo *, int);
void insertar(nodo **, int);
nodo *nuevonodo(int);
void listar(nodo *);
void eliminar(nodo **);
int main()
{
    int i, cant, num;
    nodo *cabeza, *aux;

    cabeza = NULL;
    srand(time(NULL));
    p("\n Ingrese la cantidad de elementos:");
    s("%d", &cant);
    for (i = 0; i < cant; i++)
    {
        p("\n Ingrese dato:");
        s("%d", &num);
        insertar(&cabeza, num);
        // insertar(&cabeza,rand()%80+1);
    }
    p("\n\n Lista Ingresada\n\n");
    listar(cabeza);
    p("\n\n Ingrese el Nro a buscar:");
    s("%d", &num);
    aux = buscar(cabeza, num);
    if (aux == NULL)
        p("\n El nro no fue encontrado");
    else
        p("\n El nro fue encontrado");
    p("\n Presione una Tecla para borrar los nodos!!!!");
    getch();
    eliminar(&cabeza);
    getch();
    free(cabeza);
    if (cabeza)
        listar(cabeza);
    else
        p("\n\nLista vacía!!!\n\n\n");

    return (0);
}
void insertar(nodo **x, int y)
{
    nodo *nuevo;
    nuevo = nuevonodo(y);
    if (*x == NULL)
        *x = nuevo;
    else
    {
        insertar(&(*x)->sig, y);
    }
}
nodo *nuevonodo(int x)
{
    nodo *a;
    a = (nodo *)malloc(sizeof(nodo));
    a->dato = x;
    a->sig = NULL;
    return a;
}

void listar(nodo *x)
{
    if (x)
    {
        p("%4d", x->dato);
        listar(x->sig);
    }
}

nodo *buscar(nodo *x, int y)
{
    if (!x)
        return (NULL);
    else if (y == x->dato)
        return (x);
    else
        return (buscar(x->sig, y));
}
void eliminar(nodo **x)
{
    nodo *aux;
    if (*x)
    {
        aux = *x;
        p("\nNodo a eliminar:%3d", (*x)->dato);
        getch();
        *x = aux->sig;
        free(aux);
        eliminar(x);
    }
}
