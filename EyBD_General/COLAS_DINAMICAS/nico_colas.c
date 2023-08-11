// un menu que tenga acolar, desacolar,listar,vaciar,mostrarenarchivo,salir
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define s scanf

typedef struct nodo
{
    int dato;
    struct nodo *sig;
} nodo;

typedef struct
{
    int nro;
} registro;

void guardar(nodo, FILE *, char *);
nodo ingresar_dato(void);
nodo *nuevonodo(nodo);
void acolar(nodo, nodo **, nodo **);
nodo *verificar(nodo *);
void dato_eliminado(nodo);
nodo desacolar(nodo **);
void vaciar(nodo **);
void listar(nodo *);
void mostrar(FILE *, char *);

int main()
{
    int opcion;
    FILE *archivo;
    char *nombre = "cola.dat";
    printf("que desea realizar\n");
    printf("(1), acolar\n");
    printf("(2), desacolar\n");
    printf("(3), listar\n");
    printf("(4), vaciar\n");
    printf("(5), mostrar en archivo\n");
    printf("(6), salir\n");
    s("%d", &opcion);
    nodo *p = NULL;
    nodo r;
    nodo *q = NULL;
    while (opcion > 0 && opcion < 6)
    {
        switch (opcion)
        {
        case 1:
        {
            system("cls");
            r = ingresar_dato();
            acolar(r, &p, &q);
            break;
        }
        case 2:
        {
            system("cls");
            if (verificar(p) != NULL)
            {
                r = desacolar(&p);
                guardar(r, archivo, nombre);
                dato_eliminado(r);
            }
            break;
        }
        case 3:
        {
            if (verificar(p) != NULL)
                listar(p);
            break;
        }
        case 4:
        {

            if (verificar(p) != NULL)
                vaciar(&p);
            break;
        }
        case 5:
        {
            system("cls");
            mostrar(archivo, nombre);
            break;
        }
        }
        printf("\nque desea realizar\n");
        printf("(1), apilar\n");
        printf("(2), desapilar\n");
        printf("(3), mostrar\n");
        printf("(4), vaciar\n");
        printf("(5), mostrar en archivo\n");
        printf("(6), salir\n");
        s("%d", &opcion);
    }
}

void guardar(nodo r, FILE *archivo, char *nombre)
{
    registro x;
    x.nro = r.dato;
    if ((archivo = fopen(nombre, "rb+")) == NULL)
        archivo = fopen(nombre, "wb+");

    fseek(archivo, 0L, SEEK_END);
    fwrite(&x, sizeof(x), 1, archivo);
    fclose(archivo);
}

void mostrar(FILE *archivo, char *nombre)
{
    registro x;
    if ((archivo = fopen(nombre, "rb+")) == NULL)
        archivo = fopen(nombre, "wb+");

    fread(&x, sizeof(x), 1, archivo);

    while (!feof(archivo))
    {
        printf("dato en archivo:%d\n", x.nro);
        fread(&x, sizeof(x), 1, archivo);
    }
    fclose(archivo);
}
nodo ingresar_dato(void)
{
    nodo r;
    system("cls"); // clrscr();
    printf("\nIngrese un Nro:");
    s("%d", &r.dato);

    return (r);

} // CIERRA INGRESAR_DATO

void dato_eliminado(nodo r)

{

    system("cls"); // clrscr();
    printf("\nValor Eliminado:%d", r.dato);
    printf("\n\n\nPulse una tecla.....\n");
    getch();

} // CIERRA DATO_ELIMINADO

void vaciar(nodo **p)

{

    nodo *aux;
    while (*p != NULL)
    {
        aux = *p;
        *p = (*p)->sig;
        free(aux);
    }

} // CIERRA VACIAR?

nodo *verificar(nodo *p)
{

    if (p == NULL)
    {
        system("cls"); // clrscr();
        printf("\nCOLA VACIA!!");
        printf("\n\n\n\nPulse una tecla.....");
        getch();
    }
    return (p);

} // CIERRA VERIFICAR?

void listar(nodo *p)
{
    while (p)
    {
        printf("%d\n", p->dato);
        p = p->sig;
    }
}

nodo desacolar(nodo **p)
{

    nodo r, *aux;
    r = **p;
    aux = *p;
    *p = (*p)->sig;
    free(aux);
    return (r);

} // CIERRA DESACOLAR

void acolar(nodo r, nodo **p, nodo **q)
{

    nodo *nuevo;
    nuevo = nuevonodo(r);
    if (*p == NULL)
        *p = nuevo;
    else
        (*q)->sig = nuevo;
    *q = nuevo;

} // CIERRA ACOLAR?

nodo *nuevonodo(nodo r)
{
    nodo *x;
    x = (nodo *)malloc(sizeof(nodo));
    x->dato = r.dato; //*x=r;?
    x->sig = NULL;
    return (x);
}
